# Vehicle Camera Architecture (Proposal)

## Goal
- Build speed-feeling camera behavior now (tilt + lag), while keeping a clean migration path to a dedicated camera system later.

## Decision
- Use a hybrid approach:
  - Phase 1 (implemented): keep UE built-ins (`USpringArmComponent`, `UCameraComponent`) and add `UCaddyVehicleCameraComponent` as the manager/orchestrator.
  - Phase 2 (optional): if camera logic expands (combat lock, replay, cinematic cuts, target framing), evolve into a `PlayerCameraManager` or a higher-level camera state machine.

## Why This Tradeoff
- Pros:
  - very fast to iterate for gameplay feel.
  - data-driven per vehicle via `FCaddyVehicleCameraConfig`.
  - no hard lock-in: orchestration logic is already isolated in one component.
- Cons:
  - for complex multi-camera blending, this will eventually be less scalable than a full camera manager/state graph.

## Current Camera Stack
- `ACaddyVehiclePawn`
  - owns `USpringArmComponent` + `UCameraComponent` + `UCaddyVehicleCameraComponent`.
- `UCaddyVehicleCameraComponent`
  - reads movement telemetry (`speed`, `lateral speed`, `move intent`) from `UArcadeVehicleMovementComponent`.
  - writes camera rig targets (arm length, pitch, FOV, lag, look-ahead offset, roll).
- `UCaddyVehicleTuningDataAsset`
  - owns `CameraConfig` so each vehicle preset can have distinct camera style.

## Runtime Behaviors (Phase 1)
- Speed tilt and zoom:
  - pitch shifts toward horizon at high speed.
  - arm length and FOV increase with speed.
- Speed/look-ahead:
  - world offset follows move intent/velocity direction.
- Cornering roll:
  - camera roll reacts to lateral slip.
- Lag tuning:
  - camera lag speed changes by speed alpha.

## Upgrade Path (Phase 2+)
- Keep `FCaddyVehicleCameraConfig` as low-level tuning payload.
- Add camera states (e.g. `Exploration`, `CombatAim`, `HitReaction`, `Cinematic`).
- Move blending/policy layer either to:
  - `APlayerCameraManager` subclass, or
  - dedicated `UCaddyCameraDirectorComponent`.

## Gemini Review Package
- Please review:
  - separation of concerns (`pawn` vs `camera component` vs `movement`).
  - data-asset ownership of camera config.
  - extensibility path toward multi-state camera system.
  - any anti-pattern in using spring-arm world target offset for look-ahead.

- Suggested Gemini prompt:
  - "I have a UE5 vehicle camera setup with `SpringArm + Camera` and a `VehicleCameraComponent` that computes speed-based pitch/arm/FOV/look-ahead/roll and applies lag. Config lives in per-vehicle data assets. Please review this architecture for scalability and suggest a migration path to camera states/PlayerCameraManager without rewriting current tuning assets."
