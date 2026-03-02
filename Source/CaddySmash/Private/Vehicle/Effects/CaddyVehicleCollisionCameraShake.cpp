#include "Vehicle/Effects/CaddyVehicleCollisionCameraShake.h"

UCaddyVehicleCollisionCameraShake::UCaddyVehicleCollisionCameraShake()
{
    OscillationDuration = 0.22f;
    OscillationBlendInTime = 0.04f;
    OscillationBlendOutTime = 0.10f;

    RotOscillation.Pitch.Amplitude = 2.2f;
    RotOscillation.Pitch.Frequency = 18.0f;
    RotOscillation.Yaw.Amplitude = 1.6f;
    RotOscillation.Yaw.Frequency = 16.0f;
    RotOscillation.Roll.Amplitude = 1.2f;
    RotOscillation.Roll.Frequency = 14.0f;

    LocOscillation.X.Amplitude = 2.5f;
    LocOscillation.X.Frequency = 18.0f;
    LocOscillation.Y.Amplitude = 2.0f;
    LocOscillation.Y.Frequency = 16.0f;
    LocOscillation.Z.Amplitude = 1.5f;
    LocOscillation.Z.Frequency = 20.0f;
}
