# Vehicle Tuning Parameter Reference (English)

This document covers every runtime tuning field exposed by `UCaddyVehicleTuningDataAsset`.
Units are Unreal default (`cm`, `cm/s`, `cm/s^2`, `degrees`, `seconds`) unless stated otherwise.

## Data Asset Fields

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `GasConfig` | Longitudinal speed/accel profile. | N/A | N/A | Define top speed and accel identity per vehicle. |
| `HandlingConfig` | Steering, grip, drift profile. | N/A | N/A | Define stable vs slippery handling style. |
| `CollisionConfig` | Collision smoothing and response profile. | N/A | N/A | Decide wall behavior and impact retention. |
| `CameraConfig` | Speed-feel camera behavior profile. | N/A | N/A | Per-vehicle camera personality. |
| `FeelConfig` | Visual game-feel profile. | N/A | N/A | Per-vehicle deformation/shake style. |
| `CollisionHitRegisterPipeline` | Optional explicit pipeline for collision events. | N/A | N/A | Route collision hits into a specific combat/event pipeline. |

## Gas (`FCaddyVehicleGasConfig`)

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `MaxForwardSpeed` | Maximum forward speed. | Higher top speed and longer straights. | Lower top speed, tighter control. | Fast archetype vs heavy/tank archetype. |
| `ForwardAcceleration` | Throttle acceleration strength. | Quicker launches and corner exits. | Smoother, less snappy start. | Arcade punchiness or beginner-friendly ease. |
| `CoastDeceleration` | Passive slowing when no input. | Car slows quickly off-throttle. | Car carries momentum longer. | Technical tracks vs flow tracks. |
| `BrakeDeceleration` | Braking force while moving forward. | Shorter stopping distance and sharper entries. | Softer braking, longer glide. | Precise braking zones vs casual feel. |
| `MaxReverseSpeed` | Maximum reverse speed. | Faster reverse recoveries. | Slower reverse, less abuse. | Arena maps that need quick backing out. |
| `ReverseAcceleration` | Reverse acceleration strength. | Reverse engages faster. | Reverse feels heavier. | Keep reverse responsive in close combat maps. |

## Handling (`FCaddyVehicleHandlingConfig`)

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `SteeringRateDegPerSec` | Yaw turn speed per second. | Faster direction changes. | Slower turn-in. | Agile car vs stable cruiser. |
| `MinSpeedForSteering` | Min speed required before steering affects yaw. | Less spin when near standstill. | More low-speed pivot ability. | Reduce jitter at very low speed. |
| `LateralFrictionInterpSpeed` | How quickly sideways speed is removed (normal). | More grip, less slide. | More drift-like side slip. | Tune planted vs loose handling. |
| `LinearDrag` | Continuous speed damping. | Vehicle loses speed faster overall. | Vehicle coasts longer. | Tight arenas often want slightly higher drag. |
| `StopSpeedThreshold` | Speed below which velocity snaps to zero. | Cleaner full-stop behavior. | More micro-motion at low speed. | Prevent tiny endless sliding. |
| `MoveIntentDeadZone` | Input magnitude threshold for valid move intent. | Filters noisy sticks more aggressively. | More sensitive to tiny input. | Controller deadzone stabilization. |
| `DriftLateralFrictionInterpSpeed` | Sideways damping while drifting. | Drift regains grip faster. | Drift stays loose longer. | Long drift chains vs controllable drift exits. |
| `DriftSteeringRateMultiplier` | Steering rate multiplier while drifting. | More drift rotation authority. | Drift turns flatter/wider. | Make drift feel expressive. |
| `DriftInputThreshold` | Drift input value needed to activate drift. | Harder to trigger accidental drift. | Easier to drift. | Balance accessibility vs precision. |

## Collision Core (`FCaddyVehicleCollisionConfig`)

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `ResponseMode` | Collision response model (`SlideOnly`, `ArcadeWallGlide`). | N/A | N/A | Use `ArcadeWallGlide` for smooth arcade wall behavior. |
| `SpeedRetainRatio` | Speed preserved after impact (0..1). | Keep momentum after hits. | Bigger speed loss on collision. | Higher for forgiving arcade flow. |
| `MaxCollisionIterations` | Sweep/resolve loops per tick. | Better stability in corners/stacked contacts. | Cheaper but can feel stickier. | Increase if corner trapping occurs. |
| `WallGlideVelocityInterpSpeed` | Blend speed toward glide tangent velocity. | Snappier redirection after wall contact. | Softer transition. | Avoid “frozen on wall” feeling. |
| `WallGlideInputAssist` | Player input influence on wall glide direction. | More player control while scraping walls. | More physically neutral slide. | Keep agency during collisions. |
| `MinNormalImpactSpeedForGlide` | Normal impact threshold for strong glide logic. | Fewer impacts trigger strong glide behavior. | More impacts trigger glide smoothing. | Control when arcade smoothing activates. |
| `MinWallGlideSpeed` | Minimum preserved glide speed on heavy impact. | Fewer full stalls on wall hits. | Impacts can slow more aggressively. | Maintain race flow after mistakes. |
| `HeadOnGlideSpeedScale` | Head-on fallback conversion to tangent glide speed. | Better recovery for frontal wall hits. | Harsher punishment for head-on hits. | Set higher for party/arcade pacing. |
| `PushOutDistance` | Small normal push after impact. | Less sticky contact. | Can re-stick on geometry edges. | Raise slightly if wall cling appears. |
| `DebugPersistSeconds` | Debug line persistence time. | Longer debug visibility. | Cleaner viewport with less clutter. | Debug only. |
| `HitRegister` | Nested collision event emission settings. | N/A | N/A | Controls combat/event integration from collisions. |

## Collision HitRegister (`FCaddyVehicleCollisionHitRegisterConfig`)

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `bEnableCollisionHitRegister` | Master switch for collision event publishing. | N/A | N/A | Disable if you only want movement collisions. |
| `MinSpeedForEvent` | Minimum total speed to emit event. | Fewer low-speed events. | More low-speed bumps emit events. | Filter noise in tight spaces. |
| `MinNormalImpactSpeedForEvent` | Minimum normal impact speed to emit event. | Only stronger head-on hits trigger events. | More glancing hits can trigger. | Tune combat readability. |
| `EventCooldownSeconds` | Per-vehicle cooldown between emitted events. | Fewer repeated spam events. | More frequent events in rapid hits. | Stabilize damage/event frequency. |
| `BaseDamageByNormalImpactSpeed` | Damage slope vs normal impact speed. | Impact damage scales faster. | Impact damage scales slower. | Balance ramming builds. |
| `BaseDamageBias` | Flat damage added to each emitted event. | Higher guaranteed damage floor. | More speed-dependent damage only. | Ensure collisions always “matter.” |
| `BaseTags` | Tags always included in collision events. | N/A | N/A | Route logic in ability/effect systems. |
| `WorldStaticTag` | Added when hitting static world. | N/A | N/A | Distinguish wall hits from actor hits. |
| `WorldDynamicTag` | Added when hitting dynamic world objects. | N/A | N/A | Barrel/physics-object specific rules. |
| `PawnTag` | Added when hitting a pawn. | N/A | N/A | PvP impact reactions. |
| `DriftingTag` | Added when impact occurs during drift. | N/A | N/A | Drift-specific perks/skills. |
| `SpeedAttributeTag` | Optional payload attribute for total speed. | N/A | N/A | Downstream formulas that need speed input. |
| `NormalImpactSpeedAttributeTag` | Optional payload attribute for normal impact speed. | N/A | N/A | Distinguish scrape vs direct hit severity. |
| `DriftingAttributeTag` | Optional payload attribute (0/1 drifting state). | N/A | N/A | Event logic with binary drift condition. |

## Camera (`FCaddyVehicleCameraConfig`)

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `bEnableDynamicCamera` | Master switch for dynamic updates. | N/A | N/A | Disable to lock camera at base settings. |
| `BaseArmLength` | Base spring-arm distance. | Wider situational awareness. | Closer, more intimate camera. | Large maps vs close combat maps. |
| `BasePitchDeg` | Base spring-arm pitch. | Closer to horizon (less top-down) if less negative. | More top-down if more negative. | Tune visibility vs speed sensation. |
| `BaseFOV` | Base field of view. | More speed sensation/peripheral view. | Less distortion, tighter framing. | Fast arcade often uses higher FOV. |
| `BaseWorldTargetOffset` | Constant world target offset. | Shift framing baseline. | Return toward actor center. | Keep car lower in frame, etc. |
| `MaxSpeedForEffects` | Speed where speed effects reach full alpha. | Effects ramp more slowly across speed range. | Effects ramp earlier/stronger at medium speed. | Normalize feel across faster/slower cars. |
| `MaxSpeedPitchOffsetDeg` | Pitch change at max speed alpha. | Stronger speed tilt. | Subtler pitch response. | Emphasize high-speed push. |
| `MaxSpeedArmLengthOffset` | Extra arm length at max speed alpha. | More zoom-out at speed. | Less zoom change. | Improve high-speed readability. |
| `MaxSpeedFOVOffset` | Extra FOV at max speed alpha. | Stronger speed tunnel effect. | Calmer speed presentation. | Arcade punch vs comfort. |
| `LookAheadDistance` | Look-ahead offset distance. | Camera leads movement more. | Camera stays centered more. | Better upcoming path visibility. |
| `LookAheadInterpSpeed` | Smoothing speed of look-ahead motion. | Snappier camera lead changes. | Smoother but laggier transitions. | Reduce jitter vs increase responsiveness. |
| `MaxLateralRollDeg` | Max camera roll from lateral slip. | Stronger cornering drama. | Flatter, calmer image. | Add arcade energy in turns. |
| `LateralSpeedForMaxRoll` | Lateral speed needed for full roll. | Roll responds less at moderate slip. | Roll reaches max earlier. | Prevent over-roll on small corrections. |
| `RollInterpSpeed` | Roll interpolation speed. | Faster roll reactions. | Slower, softer roll. | Tune comfort vs punchiness. |
| `bEnableCameraLag` | Enables spring-arm location lag. | N/A | N/A | Core “weight” feel for speed. |
| `CameraLagSpeedAtLowSpeed` | Lag speed near zero speed. | Camera catches up faster (less lag). | More low-speed float. | Keep idle maneuvering readable. |
| `CameraLagSpeedAtHighSpeed` | Lag speed at high speed. | Camera catches up faster at speed. | More high-speed drag/weight. | Add speed weight without over-sway. |
| `CameraLagMaxDistance` | Max allowed lag displacement. | Allows larger lag arcs. | Tighter follow behavior. | Control extreme lag artifacts. |
| `bEnableCameraRotationLag` | Enables rotation lag. | N/A | N/A | Smooth rapid heading changes. |
| `CameraRotationLagSpeed` | Rotation lag catch-up speed. | Faster rotation follow. | Slower yaw/roll catch-up. | Reduce motion sickness vs add weight. |
| `TransformInterpSpeed` | Smoothing for dynamic transform targets. | More responsive camera. | More damped, cinematic camera. | Global smoothness control. |

## Feel (`FCaddyVehicleFeelConfig`)

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `bEnableFeel` | Master switch for feel output. | N/A | N/A | Disable for clean baseline tests. |
| `bEnableIdleEngineShake` | Enables idle shake layer. | N/A | N/A | Add life when vehicle is still. |
| `IdleShakeMaxSpeed` | Speed where idle shake fades out. | Idle shake remains active at higher speed. | Idle shake disappears earlier. | Keep shake mostly near standstill. |
| `IdleShakeLocationAmplitude` | Max translational idle shake amplitude. | Stronger positional vibration. | Subtler vibration. | Engine rumble exaggeration. |
| `IdleShakeRotationAmplitudeDeg` | Max rotational idle shake amplitude. | Stronger rotational wobble. | Subtler wobble. | Stylized idle personality. |
| `IdleShakeFrequency` | Idle shake oscillation frequency. | Faster “buzz.” | Slower “rocking” shake. | Tune engine type fantasy. |
| `IdleInputBoost` | Added shake strength from active input. | Input-driven shake is more obvious. | Less change when pressing controls. | Make throttle blips visible. |
| `bEnableAccelerationDeform` | Enables accel/speed squash-stretch. | N/A | N/A | Turn off for realistic rigid body style. |
| `MaxForwardAccelForDeform` | Accel needed for full deform alpha. | Requires harder accel to hit max effect. | Effect reaches max more easily. | Normalize across different accel profiles. |
| `MaxAccelSquashStretch` | Max accel-driven scale deformation amount. | Stronger launch/compression effect. | Milder deformation. | Cartoon vs grounded style. |
| `MaxSpeedStretch` | Max extra stretch from speed itself. | More elongation at high speed. | Flatter silhouette at speed. | Emphasize velocity impression. |
| `MaxSpeedForStretch` | Speed needed for full speed-stretch alpha. | Stretch ramps more gradually. | Stretch appears earlier. | Balance across fast/slow classes. |
| `bEnableLateralLean` | Enables lean roll from lateral speed. | N/A | N/A | Disable for rigid visual style. |
| `LateralSpeedForMaxLean` | Lateral speed for full lean alpha. | Lean requires bigger slides. | Lean responds at smaller slides. | Control sensitivity in cornering. |
| `MaxLateralLeanRollDeg` | Maximum lean roll angle. | More dramatic corner lean. | More restrained lean. | Arcade exaggeration control. |
| `bEnableImpactPulse` | Enables impact pulse one-shot layer. | N/A | N/A | Disable if collision readability already noisy. |
| `ImpactPulseDuration` | Duration of impact pulse. | Longer hit after-effect. | Snappier, punchier impact. | Heavy vs crisp hit style. |
| `ImpactNormalSpeedForMaxPulse` | Impact speed needed for full pulse. | Only very strong hits reach max pulse. | Moderate hits can reach max pulse. | Prevent overreaction on small bumps. |
| `ImpactPulseScale` | Scale burst amount during impact. | Stronger squash/pop on hit. | Softer hit deformation. | Communicate impact severity. |
| `ImpactPulseLocationKick` | Positional kick distance from impact. | Stronger knockback illusion. | Smaller kick. | Improve tactile hit feel. |
| `ImpactPulseRotationKickDeg` | Rotational kick magnitude on impact. | More angular hit snap. | Less rotational disturbance. | Add “slam” energy to collisions. |
| `OffsetInterpSpeed` | Interp speed for offset/rotation channels. | Faster response, less smoothing. | Smoother, floatier transitions. | Balance responsiveness and jitter. |
| `ScaleInterpSpeed` | Interp speed for scale channel. | Faster scale snaps. | Softer scale transitions. | Control deformation sharpness. |
| `MorphConfig` | Morph target output mapping for feel signals. | N/A | N/A | Enable mesh-shape driven feel on skeletal vehicles. |

## Feel Morph Core (`FCaddyVehicleMorphConfig`)

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `bEnableMorphTargets` | Master switch for morph output. | N/A | N/A | Turn on only for skeletal mesh based vehicles. |
| `bApplyTransformFeelAlongsideMorph` | Whether transform feel and morph feel run together. | More layered/exaggerated feel. | Cleaner morph-only output. | Use `true` while migrating from cube prototype. |
| `bWarnMissingMorphTargets` | Logs warning once per missing morph name. | More diagnostics. | Less log noise. | Keep on during setup, off for shipping noise control. |
| `GlobalWeightScale` | Global multiplier applied to all channel outputs. | Stronger overall morph effect. | Softer overall morph effect. | Quick global intensity knob per vehicle. |
| `IdleChannel` | Channel mapping from idle signal (0..1). | N/A | N/A | Engine rumble shape morph. |
| `AccelerationChannel` | Channel mapping from accel signal (0..1). | N/A | N/A | Launch squash/stretch shape. |
| `SpeedChannel` | Channel mapping from speed signal (0..1). | N/A | N/A | High-speed elongation shape. |
| `LeanLeftChannel` | Channel mapping from left lean signal (0..1). | N/A | N/A | Corner lean to left side shape. |
| `LeanRightChannel` | Channel mapping from right lean signal (0..1). | N/A | N/A | Corner lean to right side shape. |
| `ImpactChannel` | Channel mapping from impact pulse signal (0..1). | N/A | N/A | One-shot collision shape pulse. |

## Feel Morph Channel (`FCaddyVehicleMorphChannelConfig`)

These fields are shared by each channel entry above.

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `bEnabled` | Enables this specific channel mapping. | N/A | N/A | Toggle a channel without clearing the configured name. |
| `MorphTargetName` | Morph target name to drive on skeletal mesh. | N/A | N/A | Bind channel to authored morph target. |
| `InputScale` | Multiplier for source signal before clamp. | Stronger response to signal changes. | Weaker response to signal changes. | Fine control per channel intensity. |
| `InputBias` | Constant added after scaling source signal. | Raises baseline weight. | Lowers baseline weight. | Keep slight deformation even at low signal. |
| `OutputMin` | Minimum output after processing. | Higher floor value. | Lower floor value. | Avoid complete zeroing for subtle persistent shape. |
| `OutputMax` | Maximum output after processing. | Higher peak allowance. | Lower peak cap. | Prevent over-deformation spikes. |
| `InterpSpeed` | Smoothing speed of current weight toward target. | Faster/snappier morph updates. | Slower/smoother morph updates. | Remove jitter vs add responsiveness. |
