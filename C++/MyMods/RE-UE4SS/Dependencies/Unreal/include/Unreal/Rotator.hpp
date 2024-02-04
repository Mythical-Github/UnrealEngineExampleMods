#ifndef RC_UNREAL_ROTATOR_HPP
#define RC_UNREAL_ROTATOR_HPP

#define _USE_MATH_DEFINES
#include <math.h>

#include <Unreal/UObject.hpp>
#include <Unreal/Quat.hpp>

#pragma warning(disable: 4305)

namespace RC::Unreal
{
    struct RC_UE_API FRotator
    {
        float Pitch;
        float Yaw;
        float Roll;

        inline FRotator() : Pitch(0.0f), Yaw(0.0f), Roll(0.0f) {}
        inline FRotator(float pitch, float yaw, float roll) : Pitch(pitch), Yaw(yaw), Roll(roll) {}

        inline FQuat Quaternion() const
        {
            const float DEG_TO_RAD = M_PI/(180.f);
            const float RADS_DIVIDED_BY_2 = DEG_TO_RAD/2.f;
            float SP, SY, SR;
            float CP, CY, CR;

            const float PitchNoWinding = std::fmod(Pitch, 360.0f);
            const float YawNoWinding = std::fmod(Yaw, 360.0f);
            const float RollNoWinding = std::fmod(Roll, 360.0f);

            SP = std::sin(PitchNoWinding * RADS_DIVIDED_BY_2);
            CP = std::cos(PitchNoWinding * RADS_DIVIDED_BY_2);
            SY = std::sin(YawNoWinding * RADS_DIVIDED_BY_2);
            CY = std::cos(YawNoWinding * RADS_DIVIDED_BY_2);
            SR = std::sin(RollNoWinding * RADS_DIVIDED_BY_2);
            CR = std::cos(RollNoWinding * RADS_DIVIDED_BY_2);

            FQuat RotationQuat;
            RotationQuat.SetX(CR*SP*SY - SR*CP*CY);
            RotationQuat.SetY(CR*SP*CY - SR*CP*SY);
            RotationQuat.SetZ(CR*CP*SY - SR*SP*CY);
            RotationQuat.SetW(CR*CP*CY + SR*SP*SY);

            return RotationQuat;
        }
    };
}

#pragma warning(default: 4305)

#endif // RC_UNREAL_ROTATOR_HPP