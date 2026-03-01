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
  - Owns collision, mesh, spring arm, top-down camera, movement component, camera manager component.
  - Owns skill component for modular vehicle abilities (first skill: brake-dash).
  - Converts player 2D input into world-space move intent.
  - Keeps throttle independent from move intent.
  - Exposes `IAbilitySystemInterface` with built-in `UAbilitySystemComponent`.
  - Sends input to server through lightweight RPC for future online play.
  - Registers vehicle debug providers into DebugFramework (`Vehicle` tool with `Core/Input/Tuning/Feel/Camera/Collision/Debug Draw` panels).
  - Supports runtime tuning preset list and switching via console commands.
- `UCaddyVehicleCameraComponent`
  - Camera management layer that wraps built-in spring-arm/camera features.
  - Drives speed-based pitch/arm/FOV offsets.
  - Applies look-ahead offset and lateral roll from movement telemetry.
  - Dynamically tunes camera lag/rotation lag to enhance speed feeling.
  - Sources parameters from `UCaddyVehicleTuningDataAsset::CameraConfig`.
- `UCaddyVehicleFeelComponent`
  - Game-feel layer for visual motion/deformation on the vehicle mesh.
  - Applies idle engine shake, acceleration squash/stretch, lateral lean, and collision pulse.
  - Works on mesh relative transform/scale now, designed to be replaced by morph/deformer drivers later.
  - Sources parameters from `UCaddyVehicleTuningDataAsset::FeelConfig`.
- `UCaddyVehicleSkillComponent`
  - Modular runtime skill layer for vehicle actions.
  - Current skill: configurable trigger (input action hold or brake+throttle combo) -> curved emergency brake -> charge/aim -> dash burst with cooldown.
  - Drives movement via external velocity override while reusing movement collision handling.
  - Sources parameters from standalone `UCaddyVehicleSkillConfigDataAsset` (decoupled from tuning presets).
- `ACaddyGameMode`
  - Sets default pawn and player controller.
- `ACaddyPlayerController`
  - Adds a utility function to spawn an extra local player.

## Input Contract
- `Caddy_MoveX` / `Caddy_MoveY`: left stick or WASD, direction only.
- `Caddy_Accelerate`: gas pedal behavior, no direct steering effect.
- `Caddy_BrakeReverse`: brakes when moving forward, drives reverse when speed reaches zero.
- `Caddy_Drift`: hold to reduce lateral grip and increase yaw steering rate.
- Skill trigger (Phase 1): from `Enhanced Input Action` by default, with optional brake+throttle combo mode.

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
  - movement publishes raw collision telemetry only (no local tier/damage adjudication).
  - base damage is initialized as `0` and expected to be decided in pipeline nodes.
  - tags:
    - base tags (`BaseTags`)
    - target object type tags (`WorldStaticTag`, `WorldDynamicTag`, `PawnTag`)
    - state tags (`VehicleTargetTag`, `DriftingTag`, `SkillDashTag`)
  - raw attributes:
    - `Attr.Collision.TotalSpeed` (`SpeedAttributeTag`)
    - `Attr.Collision.NormalImpactSpeed` (`NormalImpactSpeedAttributeTag`)
    - `Attr.Collision.TargetSpeed` (`TargetSpeedAttributeTag`)
    - `Attr.Collision.RelativeNormalImpactSpeed` (`RelativeNormalSpeedAttributeTag`)
    - `Attr.Collision.TargetIsVehicle` (`TargetVehicleAttributeTag`)
    - `Attr.Collision.IsDrifting` (`DriftingAttributeTag`)
    - `Attr.Collision.IsSkillDashing` (`SkillDashingAttributeTag`)
  - pipeline output attributes (optional, for telemetry/debug):
    - `Attr.Collision.EffectiveNormalImpactSpeed` (`EffectiveNormalSpeedAttributeTag`)
    - `Attr.Collision.ImpactScore` (`ImpactScoreAttributeTag`)
    - `Attr.Collision.ImpactTier` (`ImpactTierAttributeTag`)
- Pipeline source:
  - uses `CollisionHitRegisterPipeline` from current tuning data asset (applied onto movement component)
  - otherwise falls back to `HitRegisterSettings.DefaultPipeline`
- Recommended collision combat node:
  - `UHRN_AdjudicateVehicleCollision` in `HitRegisterCore` centralizes collision tiering, clash tagging, and damage derivation.

## Camera Management (Phase 1)
- Current approach:
  - Keep UE built-in camera stack (`USpringArmComponent + UCameraComponent`).
  - Add `UCaddyVehicleCameraComponent` as orchestration layer for tuning and runtime adaptation.
- Runtime camera effects:
  - speed tilt (`BasePitch + MaxSpeedPitchOffsetDeg`)
  - speed zoom-out (`BaseArmLength + MaxSpeedArmLengthOffset`)
  - speed FOV boost (`BaseFOV + MaxSpeedFOVOffset`)
  - velocity/move-intent look-ahead (`BaseWorldTargetOffset + Direction * LookAheadDistance`)
  - lateral roll from slip (`LateralSpeed -> MaxLateralRollDeg`)
  - speed-adaptive lag (`CameraLagSpeedAtLowSpeed -> CameraLagSpeedAtHighSpeed`)
- Data-driven tuning:
  - all camera parameters are in `FCaddyVehicleCameraConfig` on each tuning data asset.
  - preset switch immediately updates movement + camera style together.

## Vehicle Feel Foundation (Phase 1)
- `UCaddyVehicleFeelComponent` is added as an isolated runtime module.
- Current implementation targets static mesh (cube) and supports:
  - engine scale vibration (curve-driven variance/frequency)
  - acceleration deformation (forward stretch + side squash)
  - corner lean (roll by lateral speed)
  - collision pulse (kick + squash burst on impact)
- Why this path:
  - fast iteration for prototype game feel.
  - future replacement path is clear: keep high-level config/telemetry in feel component and swap only the output driver (e.g. morph targets, deformer graph, control rig).

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

## Detailed Parameter Reference
- `Plugins/Docs/VehicleTuningParameterReference.md`
