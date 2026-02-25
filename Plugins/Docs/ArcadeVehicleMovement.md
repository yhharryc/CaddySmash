# Arcade Vehicle Movement (Phase 1)

## Scope
- Top-down camera pawn for vehicle combat prototype.
- Input split: move intent direction vs throttle with explicit drift modifier.
- Arcade movement (no rigid-body simulation).
- Local multiplayer ready, server-authoritative network path reserved.

## Module Layout
- `UArcadeVehicleMovementComponent`
  - Owns gas/handling configs.
  - Owns dedicated collision config (`FCaddyVehicleCollisionConfig`) including smoothing and hit-register reporting.
  - Can source gas/handling values from `UCaddyVehicleTuningDataAsset`.
  - Simulates acceleration, coast deceleration, drag, lateral friction.
  - Rotates vehicle toward world move intent at steering rate.
  - Applies movement with collision-safe sweep/slide and configurable arcade wall-glide smoothing.
  - Emits collision events into HitRegister pipeline for centralized event gating.
  - Draws vehicle debug vectors (forward/target/velocity/lateral) in world.
- `ACaddyVehiclePawn`
  - Owns collision, mesh, spring arm, top-down camera, movement component.
  - Converts player 2D input into world-space move intent.
  - Keeps throttle independent from move intent.
  - Exposes `IAbilitySystemInterface` with built-in `UAbilitySystemComponent`.
  - Sends input to server through lightweight RPC for future online play.
  - Registers vehicle debug providers into DebugFramework (`Vehicle` tool with `Core/Input/Tuning/Collision/Debug Draw` panels).
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

## Collision Handling
- Collision flow:
  - `PerformMovement` does iterative sweep (`MaxCollisionIterations`).
  - On blocking hit, it resolves with `HandleBlockingCollision`.
  - Response mode decides velocity behavior:
    - `SlideOnly`: simple velocity projection on hit plane.
    - `ArcadeWallGlide`: projects to wall tangent, adds intent assist, head-on fallback glide, and soft push-out.
- Debug telemetry stored per last blocking hit:
  - hit actor/location/normal/tangent
  - total impact speed + normal impact speed
  - hit register trigger/result status

## Collision Tuning (Data Asset)
- `CollisionConfig.ResponseMode`: collision response style switch.
- `CollisionConfig.SpeedRetainRatio`: retained planar speed ratio after impact.
- `CollisionConfig.MaxCollisionIterations`: max sweeps per tick for corner stability.
- `CollisionConfig.WallGlideVelocityInterpSpeed`: how quickly velocity converges to tangent glide.
- `CollisionConfig.WallGlideInputAssist`: how much player intent steers along wall tangent.
- `CollisionConfig.MinNormalImpactSpeedForGlide`: minimum normal hit speed to enable strong glide assist.
- `CollisionConfig.MinWallGlideSpeed`: minimum preserved glide speed for heavy impacts.
- `CollisionConfig.HeadOnGlideSpeedScale`: converts head-on impact speed into tangent glide speed.
- `CollisionConfig.PushOutDistance`: tiny push away from wall to reduce sticky contacts.
- `CollisionConfig.DebugPersistSeconds`: persistence time for collision debug lines.

## Collision HitRegister Bridge
- Collision event publishing is configured under `CollisionConfig.HitRegister`.
- Event is emitted only when all gates pass:
  - `bEnableCollisionHitRegister`
  - speed thresholds (`MinSpeedForEvent`, `MinNormalImpactSpeedForEvent`)
  - cooldown (`EventCooldownSeconds`)
- Attack payload:
  - `BaseDamage = BaseDamageBias + NormalImpactSpeed * BaseDamageByNormalImpactSpeed`
  - optional tags:
    - base tags (`BaseTags`)
    - target object type tags (`WorldStaticTag`, `WorldDynamicTag`, `PawnTag`)
    - drift state tag (`DriftingTag`)
  - optional attributes:
    - speed (`SpeedAttributeTag`)
    - normal impact speed (`NormalImpactSpeedAttributeTag`)
    - drifting state (`DriftingAttributeTag`)
- Pipeline source:
  - uses `CollisionHitRegisterPipeline` from current tuning data asset (applied onto movement component)
  - otherwise falls back to `HitRegisterSettings.DefaultPipeline`

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
