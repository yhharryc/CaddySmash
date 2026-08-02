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
| `WallGlideVelocityInterpSpeed` | Blend speed toward glide tangent velocity. | Snappier redirection after wall contact. | Softer transition. | Avoid 窶彷rozen on wall窶・feeling. |
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
| `BaseTags` | Tags always included in collision events. | N/A | N/A | Route logic in ability/effect systems. |
| `WorldStaticTag` | Added when hitting static world. | N/A | N/A | Distinguish wall hits from actor hits. |
| `WorldDynamicTag` | Added when hitting dynamic world objects. | N/A | N/A | Barrel/physics-object specific rules. |
| `PawnTag` | Added when hitting a pawn. | N/A | N/A | PvP impact reactions. |
| `VehicleTargetTag` | Added when target is another arcade vehicle. | N/A | N/A | Route vehicle-vs-vehicle specific logic. |
| `DriftingTag` | Added when impact occurs during drift. | N/A | N/A | Drift-specific perks/skills. |
| `SkillDashTag` | Added when impact occurs during skill dash state. | N/A | N/A | Route dash-specific collision logic. |
| `SpeedAttributeTag` | Raw payload attribute for total speed (fallback: `Attr.Collision.TotalSpeed`). | N/A | N/A | Input for collision adjudication node. |
| `NormalImpactSpeedAttributeTag` | Raw payload attribute for normal impact speed (fallback: `Attr.Collision.NormalImpactSpeed`). | N/A | N/A | Direct-hit severity input. |
| `TargetSpeedAttributeTag` | Raw payload attribute for target speed (fallback: `Attr.Collision.TargetSpeed`). | N/A | N/A | Needed for clash/speed-ratio style rules. |
| `RelativeNormalSpeedAttributeTag` | Raw payload attribute for relative normal impact speed (fallback: `Attr.Collision.RelativeNormalImpactSpeed`). | N/A | N/A | Better vehicle-vs-vehicle impact strength input. |
| `TargetVehicleAttributeTag` | Raw payload attribute (0/1) for whether target is vehicle (fallback: `Attr.Collision.TargetIsVehicle`). | N/A | N/A | Gate collision combat to vehicle targets. |
| `SkillDashingAttributeTag` | Raw payload attribute (0/1) for dash state (fallback: `Attr.Collision.IsSkillDashing`). | N/A | N/A | Enable dash collision bonuses in pipeline. |
| `DriftingAttributeTag` | Raw payload attribute (0/1) for drifting state (fallback: `Attr.Collision.IsDrifting`). | N/A | N/A | Enable drift collision bonuses in pipeline. |
| `EffectiveNormalSpeedAttributeTag` | Pipeline output attribute for effective normal speed (fallback: `Attr.Collision.EffectiveNormalImpactSpeed`). | N/A | N/A | Debug/telemetry of adjudicated impact speed. |
| `ImpactScoreAttributeTag` | Pipeline output attribute for impact score (fallback: `Attr.Collision.ImpactScore`). | N/A | N/A | Debug and downstream event branching. |
| `ImpactTierAttributeTag` | Pipeline output attribute for impact tier (fallback: `Attr.Collision.ImpactTier`). | N/A | N/A | Debug and tier-based follow-up logic. |

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
| `bEnableCameraLag` | Enables spring-arm location lag. | N/A | N/A | Core 窶忤eight窶・feel for speed. |
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
| `EngineScaleVibration` | Nested engine scale vibration profile. | N/A | N/A | Configure non-linear idle-to-cruise engine pulse behavior. |
| `EngineScaleVibration.bEnableEngineScaleVibration` | Enables scale-only engine vibration. | N/A | N/A | Keep car alive at idle without location jitter. |
| `EngineScaleVibration.BaseVariance` | Base size variance at low speed (engine running state). | Stronger idle pulse. | Softer idle pulse. | Set static idle personality. |
| `EngineScaleVibration.BaseFrequencyHz` | Base pulse frequency at low speed. | Faster pulse. | Slower pulse. | Tune engine rhythm. |
| `EngineScaleVibration.SpeedForCurveNormalization` | Speed mapped to curve X=1.0. | Curve transition stretches over larger speed range. | Transition happens earlier. | Align curve behavior to vehicle class speed. |
| `EngineScaleVibration.VarianceBySpeedCurve` | Optional curve for variance multiplier by speed alpha. | Depends on curve shape. | Depends on curve shape. | Build non-linear rise-then-fall variance profile. |
| `EngineScaleVibration.FrequencyBySpeedCurve` | Optional curve for frequency multiplier by speed alpha. | Depends on curve shape. | Depends on curve shape. | Build non-linear frequency profile. |
| `EngineScaleVibration.ThrottleVarianceBoost` | Extra variance from active throttle/brake input. | Stronger pulse when player starts accelerating. | Less start-up punch. | Emphasize launch feel. |
| `EngineScaleVibration.ThrottleFrequencyBoostHz` | Extra frequency from active throttle/brake input. | Faster pulse during input. | Smaller frequency reaction. | Add urgency on acceleration onset. |
| `EngineScaleVibration.VarianceInterpSpeed` | Smoothing speed for variance changes. | More responsive variance changes. | Smoother transitions. | Reduce choppiness or add snappiness. |
| `EngineScaleVibration.FrequencyInterpSpeed` | Smoothing speed for frequency changes. | More responsive frequency changes. | Smoother transitions. | Stabilize frequency movement. |
| `EngineScaleVibration.MaxVariance` | Upper clamp for final variance. | Allows larger scale oscillation. | Caps pulse earlier. | Prevent over-exaggeration. |
| `EngineScaleVibration.MinFrequencyHz` | Lower clamp for frequency. | Keeps minimum pulse rate higher. | Allows very slow pulse. | Ensure engine never feels fully dead. |
| `EngineScaleVibration.MaxFrequencyHz` | Upper clamp for frequency. | Allows very rapid pulse at launch. | Restrains peak pulse speed. | Avoid noisy high-frequency vibration. |
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
| `ImpactPulseRotationKickDeg` | Rotational kick magnitude on impact. | More angular hit snap. | Less rotational disturbance. | Add slam energy to collisions. |
| `OffsetInterpSpeed` | Interp speed for offset/rotation channels. | Faster response, less smoothing. | Smoother, floatier transitions. | Balance responsiveness and jitter. |
| `ScaleInterpSpeed` | Interp speed for scale channel. | Faster scale snaps. | Softer scale transitions. | Control deformation sharpness. |

## Skill (`UCaddyVehicleSkillConfigDataAsset` -> `FCaddyVehicleBrakeDashSkillConfig`)

Skill config is intentionally separate from `UCaddyVehicleTuningDataAsset` to keep movement tuning and abilities decoupled.

| Parameter | Meaning | Increase | Decrease | Typical Use |
| --- | --- | --- | --- | --- |
| `bEnableBrakeDashSkill` | Enables brake-dash skill. | N/A | N/A | Toggle skill usage per vehicle archetype. |
| `TriggerMode` | Chooses trigger source (`InputActionHold` or `BrakeThrottleCombo`). | N/A | N/A | Swap between dedicated skill key and combo trigger. |
| `TriggerThrottleThreshold` | Throttle threshold for trigger combo. | Harder to trigger accidentally. | Easier to trigger. | Raise for precision-oriented cars. |
| `TriggerBrakeThreshold` | Brake threshold for trigger combo. | Harder to trigger accidentally. | Easier to trigger. | Prevent misfires from soft brake taps. |
| `TriggerInputHoldSeconds` | Required hold time before entering brake phase. | More deliberate activation. | Faster activation. | Prevent accidental spam. |
| `CooldownSeconds` | Cooldown after dash. | Less frequent skill usage. | More frequent skill usage. | Balance power budget. |
| `BrakeDuration` | Emergency brake phase duration. | Longer and smoother setup. | Snappier setup. | Tune readability vs responsiveness. |
| `BrakeSpeedAlphaCurve` | Retained-speed curve during brake phase. | Depends on curve shape. | Depends on curve shape. | Non-linear brake feel. |
| `MaxChargeSeconds` | Maximum hold time for charging. | Longer potential charge window. | Faster forced release. | Cap setup time and pacing. |
| `MinChargeSeconds` | Minimum charge required before release can dash. | More commitment before release. | Faster release response. | Avoid instant micro-dash. |
| `ChargeAlphaCurve` | Charge remap curve from hold-time alpha. | Depends on curve shape. | Depends on curve shape. | Make charge growth front-loaded or back-loaded. |
| `AimInputDeadZone` | Min input needed to update aim. | More stable aim. | More sensitive aim. | Filter stick noise. |
| `bRotateOwnerToAimDuringCharge` | Rotate vehicle toward aim while braking/charging. | N/A | N/A | Improve telegraph and player readability. |
| `AimRotationRateDegPerSec` | Rotation speed while aiming. | Faster visual alignment. | Slower alignment. | Weighty vs snappy style. |
| `DashDurationAtMinCharge` | Dash duration when released at minimum charge. | Longer baseline lunge. | Shorter baseline burst. | Tune low-commit usage. |
| `DashDurationAtMaxCharge` | Dash duration at full charge. | Larger distance at full charge. | Smaller distance at full charge. | Control charged skill payoff. |
| `DashPeakSpeedAtMinCharge` | Dash peak speed at minimum charge. | Stronger low-charge burst. | Softer low-charge burst. | Balance quick taps. |
| `DashPeakSpeedAtMaxCharge` | Dash peak speed at full charge. | Stronger full-charge burst. | Softer full-charge burst. | Balance high-commit burst strength. |
| `DashSpeedAlphaCurve` | Dash speed curve over dash duration. | Depends on curve shape. | Depends on curve shape. | Front-loaded or sustained dash character. |
| `PostDashCarryRatio` | Carry-over speed ratio after dash exits. | More post-dash momentum. | Sharper stop after dash. | Control recoverability and commitment. |
