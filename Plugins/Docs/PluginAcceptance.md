# Plugin Acceptance Checklist

Use the steps below to validate the refactor in a project.

## 1. Core-only Compile
- Enable only `CombatCore`, `SquadCore`, `HitRegister`.
- Build the project.
- Expected: compile succeeds without `GameplayAbilities`, `UMG`, `Slate`, or `DebugFramework` dependencies.

## 2. Combat GAS Adapter
- Enable `CombatCoreGASAdapter`.
- Add `UCombatGASAttackAdapterComponent` to the actor that owns `UAttackOrchestratorComponent`.
- Trigger an attack intent/commit flow.
- Expected: ability activates and commits successfully.

## 3. Squad StateTree Adapter
- Enable `SquadCoreStateTreeAdapter`.
- Open a StateTree asset that uses squad tasks/conditions and re-save.
- Expected: tasks/conditions resolve; runtime behavior matches pre-refactor.

## 4. Squad Debug Adapter
- Enable `SquadCoreDebugAdapter` and `DebugFramework`.
- Set `DebugFramework` visibility settings (opt-in) or use console toggle.
- Expected: Squad debug panels/widgets appear and update.

## 5. HitRegister GAS Adapter
- Enable `HitRegisterGASAdapter`.
- Attach `UHitRegisterGASDamageableComponent` to a target with ASC.
- Execute a hit register pipeline that applies damage.
- Expected: GameplayEffect is applied and events fire.

## 6. Log Hygiene
- Run `rg -n LogTemp Plugins`.
- Expected: no LogTemp usage in plugin code (docs may mention it).

## 7. Hardcoding Check
- Scan for project name tags, fixed asset paths, or hard-coded GameplayTags in plugins.
- Expected: none introduced by this refactor.
