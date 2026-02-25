# Arcade Vehicle Movement (Phase 1)

## Scope
- Top-down camera pawn for vehicle combat prototype.
- Input split: move intent direction vs throttle with explicit drift modifier.
- Arcade movement (no rigid-body simulation).
- Local multiplayer ready, server-authoritative network path reserved.

## Module Layout
- `UArcadeVehicleMovementComponent`
  - Owns gas/handling configs.
  - Can source gas/handling values from `UCaddyVehicleTuningDataAsset`.
  - Simulates acceleration, coast deceleration, drag, lateral friction.
  - Rotates vehicle toward world move intent at steering rate.
  - Applies movement with collision-safe sweep/slide.
  - Draws vehicle debug vectors (forward/target/velocity/lateral) in world.
- `ACaddyVehiclePawn`
  - Owns collision, mesh, spring arm, top-down camera, movement component.
  - Converts player 2D input into world-space move intent.
  - Keeps throttle independent from move intent.
  - Exposes `IAbilitySystemInterface` with built-in `UAbilitySystemComponent`.
  - Sends input to server through lightweight RPC for future online play.
  - Registers vehicle debug providers into DebugFramework (`Vehicle` tool with multiple panels).
  - Supports runtime tuning preset list and switching via console commands.
- `ACaddyGameMode`
  - Sets default pawn and player controller.
- `ACaddyPlayerController`
  - Adds a utility function to spawn an extra local player.

## Input Contract
- `Caddy_MoveX` / `Caddy_MoveY`: left stick or WASD, direction only.
- `Caddy_Accelerate`: gas pedal behavior, no direct steering effect.
- `Caddy_BrakeReverse`: brakes when moving forward, drives reverse when speed reaches zero.
- `Caddy_Drift`: hold to reduce lateral grip and increase yaw steering rate.

## Multiplayer Notes
- Current movement simulation runs on authority only.
- Non-authority clients send move intent/throttle/drift via unreliable server RPC.
- Actor transform replication is enabled on the pawn.
- This keeps behavior deterministic for prototype and preserves migration path to client prediction later.

## Next Extensions
- Integrate movement modifiers via GAS effects/tags.
- Add runtime controls in debug panel to edit and persist tuning presets.

## Runtime Preset Switch Commands
- `caddy.vehicle.tuning.next`
- `caddy.vehicle.tuning.prev`
- `caddy.vehicle.tuning.set <index>`
