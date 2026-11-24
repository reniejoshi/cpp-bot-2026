#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <units/angle.h>
#include "RobotMap.h"
#include "frc/DataLogManager.h"
#include <wpi/DataLog.h>
using TalonFX = ctre::phoenix6::hardware::TalonFX;
using MotionMagicVoltage = ctre::phoenix6::controls::MotionMagicVoltage;

class ArmSubsystem : public frc2::SubsystemBase
{
public:
    ArmSubsystem();
    void Periodic() override;
    enum class ArmState
    {
        BOTTOM_POSITION,
        MIDDLE_POSITION,
        TOP_POSITION,
        ZEROING
    };

private:
    ArmState currentState = ArmState::ZEROING;

    TalonFX frontArmMotor{RobotMap::FRONT_ARM_MOTOR_ID, RobotMap::CANBus};
    TalonFX backArmMotor{RobotMap::BACK_ARM_MOTOR_ID, RobotMap::CANBus};

    MotionMagicVoltage m_armRequest{0_tr};

    ctre::phoenix6::StatusSignal<units::angle::turn_t> &frontArmPositionSignal =
        frontArmMotor.GetPosition();

    wpi::log::DataLog &log = frc::DataLogManager::GetLog();
    wpi::log::DoubleLogEntry m_rpmLog = wpi::log::DoubleLogEntry(log, "/Arm/FrontArmPositionDegrees");
};