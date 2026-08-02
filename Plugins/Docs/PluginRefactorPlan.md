# UE5.7 Plugins 重构方案（Core / Adapter 解耦）

## 1. 目标与原则
- 目标：将 Plugins 重构为“跨项目复用、低耦合、按需启用”。
- 原则：
  - Core 只承载稳定业务抽象，不强依赖 GAS / UMG / Slate / DebugFramework。
  - 集成能力（GAS、Debug/UI、StateTree）以 Adapter 形式拆分，可独立启停。
  - 配置强类型化与启动期校验，避免运行时静默失败。
  - 默认行为保守（opt-in），通过配置显式开启。

## 2. 现状问题归纳
- `SquadCore` 单模块混合：核心逻辑 + StateTree + Debug/UI + DebugFramework Provider。
- `CombatCore` 单模块直接依赖 `GameplayAbilities`。
- `HitRegister` 将 GAS Adapter 作为同插件 Runtime 模块，无法按插件粒度可选。
- `HitRegisterCollisionSettings.RelationResolver` 采用宽类型 `TSoftObjectPtr<UObject>`。
- `DebugFramework` 默认强制显示策略侵入性高。
- `CombatCore/SquadCore` 存在 `LogTemp`。

## 3. 目标模块边界

### 3.1 Combat 体系
- `CombatCore`（保留）：
  - 攻击请求/上下文/武器执行接口/AttackOrchestrator（不含 GAS 实现）。
  - 不依赖 `GameplayAbilities`。
- `CombatCoreGASAdapter`（新增插件）：
  - GAS 能力实现（AttackAbility、ASC 交互、Ability 激活/提交/取消）。
  - 实现 `CombatCore` 暴露的 Attack Adapter 接口。

### 3.2 Squad 体系
- `SquadCore`（保留）：
  - Formation/Manager/Member/Threat/Loot/Compliance 等核心逻辑。
  - 不依赖 `StateTreeModule`、`DebugFrameworkCore`、`UMG/Slate`。
- `SquadCoreStateTreeAdapter`（新增插件）：
  - `USquadTask_*` / `USquadCond_*`。
- `SquadCoreDebugAdapter`（新增插件）：
  - `USquadDebugComponent`、`USquadDebugWidget`、`ASquadDebugHUD`。
  - DebugFramework Provider 集成与 UMG 可视化。

### 3.3 HitRegister 体系
- `HitRegister`（保留）：
  - `HitRegisterCore` + `HitRegisterCollision`。
  - `RelationResolver` 改为强类型资产基类。
- `HitRegisterGASAdapter`（拆成独立插件）：
  - 原 `HitRegisterGASAdapter` 模块迁移到独立插件，可独立启用。

### 3.4 DebugFramework 体系
- `DebugFramework`（保留）：
  - 默认改为 opt-in。
  - 增加/明确多本地玩家 `PlayerController` 选择策略。

## 4. 目标依赖图（简化）

```text
SquadCoreStateTreeAdapter --> SquadCore --> CombatCore
SquadCoreDebugAdapter ----> SquadCore
SquadCoreDebugAdapter ----> DebugFrameworkCore + UMG + Slate

CombatCoreGASAdapter -----> CombatCore + GameplayAbilities

HitRegisterGASAdapter ----> HitRegister(Core/Collision) + GameplayAbilities
HitRegisterCollision -----> HitRegisterCore
```

约束：
- `CombatCore`、`SquadCore`、`HitRegisterCore/Collision` 均不强依赖 GAS。
- `SquadCore` 不强依赖 DebugFramework / UMG / Slate / StateTree。

## 5. 迁移策略

### 阶段 A：接口与日志基线
- 在 Core 内补 Adapter 接口（如 Combat Attack Adapter）。
- 新增插件级日志分类，替换 `LogTemp`。

### 阶段 B：模块/插件拆分
- Combat：将 GAS 实现迁出到 `CombatCoreGASAdapter`。
- Squad：将 StateTree 与 Debug/UI 迁出到两个 Adapter 插件。
- HitRegister：将 GASAdapter 模块迁出为独立插件。

### 阶段 C：配置强类型与校验
- `HitRegisterCollisionSettings` 改强类型 resolver。
- 启动期（模块 Startup）+ 运行入口处（Subsystem）校验并报错。
- DebugFramework 默认显示策略改 opt-in；补充玩家控制器策略配置。

### 阶段 D：兼容收口
- 对迁移类路径加入 `ClassRedirects`。
- 对旧配置保留兼容字段（Deprecated）并给出映射。
- 提供迁移文档与可复现验收步骤。

## 6. 兼容性风险与应对
- 风险：类迁移后蓝图父类路径失效。
  - 应对：`ActiveClassRedirects`，并在迁移文档提供重存流程。
- 风险：配置字段类型收紧导致旧配置无法加载。
  - 应对：保留 deprecated 字段并在启动期输出明确迁移日志。
- 风险：未启用 Adapter 时行为变化。
  - 应对：Core 返回可诊断错误，不 silent fail；文档明确“启用哪个 Adapter 恢复旧行为”。

## 7. 验收标准
- 仅启用 Core（CombatCore / SquadCore / HitRegister）可编译。
- 启用对应 Adapter 后行为与旧版等价：
  - Combat 的 GAS 攻击提交链路可用。
  - Squad 的 StateTree 与 Debug 面板可用。
  - HitRegister 的 GAS 受击组件可用。
- 插件代码内无 `LogTemp`。
- 无项目硬编码（项目名、固定 GameplayTag、固定资产路径）。

## 8. 回滚策略
- 按模块独立 commit；出现问题可对单模块 `git revert`。
- 优先保留“文档 + 日志分类 + 类型安全”commit，按需回滚功能拆分 commit。
- 兼容期内保留 deprecated 映射，支持分阶段回退。
