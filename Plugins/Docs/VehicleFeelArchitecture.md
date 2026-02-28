# Vehicle Feel Architecture (Foundation)

## Goal
- Build a reusable game-feel layer now (with a simple cube mesh), while keeping migration cost low when replacing visuals with final vehicle assets.

## Phase Plan
- Phase 1 (implemented):
  - `UCaddyVehicleFeelComponent` drives mesh relative transform and scale.
  - Data-driven config via `FCaddyVehicleFeelConfig` on `UCaddyVehicleTuningDataAsset`.
  - Runtime effects: scale-only engine vibration (curve-driven variance/frequency), acceleration squash/stretch, lateral lean, impact pulse.
- Phase 2 (planned):
  - Keep the same feel config + telemetry logic.
  - Replace output driver from "relative transform/scale" to:
    - morph targets / blend shapes,
    - deformer graph,
    - control rig channels,
    - or material WPO for subtle vibrations.

## Why This Works
- Works immediately with static mesh primitives.
- Keeps gameplay-feel logic centralized and independent from art pipeline.
- Preset switching naturally changes movement + camera + feel style together.

## UE 5.7 Feature Recommendations
- For subtle runtime jiggle on rigid meshes:
  - use scale-only vibration first (current approach), optionally mix with material WPO.
- For authored deformation on production cars:
  - morph target based squash/bend (if skeletal pipeline is available).
- For richer procedural deformation:
  - deformer graph pipeline (project-specific, heavier setup, best when art has stable topology and budgets).
- For impact-specific one-shots:
  - additive control rig or animation curves triggered from collision events.

## Integration Notes
- `ACaddyVehiclePawn` owns and binds `UCaddyVehicleFeelComponent` to:
  - `UArcadeVehicleMovementComponent` (telemetry source),
  - `VehicleMeshComponent` (visual output target).
- `ApplyRuntimeTuningPresetByIndex` applies `FeelConfig` together with movement/camera settings.
- DebugFramework adds `Vehicle.Feel` panel for live telemetry and tuning values.
