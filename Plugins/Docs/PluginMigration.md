# Plugin Migration Guide

This guide maps old plugin/module usage and settings to the new Core/Adapter layout.

## 1. Plugin Enablement

Old usage often only enabled a single plugin. You now enable Core plus any adapters you need.

- Combat
  - Core only: `CombatCore`
  - GAS integration: `CombatCoreGASAdapter`
- Squad
  - Core only: `SquadCore`
  - StateTree tasks/conditions: `SquadCoreStateTreeAdapter`
  - Debug HUD/UI + DebugFramework provider: `SquadCoreDebugAdapter`
- HitRegister
  - Core only: `HitRegister`
  - GAS integration: `HitRegisterGASAdapter`

## 2. Config Mapping

### DebugFramework (defaults are now opt-in)
- Old default behavior: overlay forced visible in editor/non-shipping.
- New default: opt-in. To restore old behavior:
  - `bEnabledByDefault = true`
  - `bForceVisibleInEditor = true`
  - `bForceVisibleInNonShipping = true`
  - `bAlwaysShowControlMenuInEditor = true`
  - `bAlwaysShowControlMenuInNonShipping = true`

### DebugFramework PlayerController Selection
New settings:
- `PlayerControllerPolicy` (`FirstLocal`, `PrimaryLocalPlayer`, `ExplicitLocalPlayerIndex`)
- `ExplicitLocalPlayerIndex` (used when policy is explicit)

Use these to control which local player owns debug input and UI.

### HitRegister Collision Resolver
- Old: `RelationResolver` (loose `TSoftObjectPtr<UObject>`)
- New: `RelationResolver` (typed `TSoftObjectPtr<UHitRegisterRelationResolverAsset>`)

If you were using a custom resolver, re-save it in Project Settings using the new typed field.

## 3. Blueprint / API Compatibility

### Combat
- `UAttackAbility` moved to `CombatCoreGASAdapter`.
- Class redirect is provided. Ensure `CombatCoreGASAdapter` is enabled if your content uses the ability.
- `UAttackOrchestratorComponent` now delegates to `ICombatAttackAdapter`.
  - Add `UCombatGASAttackAdapterComponent` to actors that use GAS attacks.

### Squad
- StateTree tasks/conditions moved to `SquadCoreStateTreeAdapter`.
- Debug components/widgets/HUD moved to `SquadCoreDebugAdapter`.
- Class redirects are provided. Enable the corresponding adapter plugins and re-save assets to lock in the new class path.

### HitRegister
- `UHitRegisterGASDamageableComponent` moved to `HitRegisterGASAdapter`.
- Enable `HitRegisterGASAdapter` if you use GAS-based damage.

### AttackProfile AbilityClass
`UAttackProfile::AbilityClass` is now typed as `TSubclassOf<UObject>` to avoid a GAS dependency.
- Existing `UGameplayAbility` classes still work.
- The GAS adapter validates the class and logs an error if it is not a `UGameplayAbility`.
- Re-save any AttackProfile assets to clear warnings.

## 4. Minimal Migration Steps
1. Enable adapter plugins you need (Combat GAS, Squad StateTree/Debug, HitRegister GAS).
2. Re-save assets that referenced moved classes (StateTree tasks/conditions, Squad debug widgets).
3. If using GAS combat, add `UCombatGASAttackAdapterComponent` to the actor owning `UAttackOrchestratorComponent`.
4. Update DebugFramework settings if you want old default visibility.
5. Update HitRegister collision resolver with the new typed setting.
