#pragma once

#include <frc2/command/SubsystemBase.h>
#include <units/angle.h>
#include <wpi/DataLog.h>

#include <ctre/phoenix6/TalonFX.hpp>

#include "AbstractSubsystem.h"
#include "RobotMap.h"
#include "frc/DataLogManager.h"
using TalonFX = ctre::phoenix6::hardware::TalonFX;
using MotionMagicVoltage = ctre::phoenix6::controls::MotionMagicVoltage;
template <typename T>
using StatusSignal = ctre::phoenix6::StatusSignal<T>;
using turn_t = units::angle::turn_t;
using turns_per_second_t = units::angular_velocity::turns_per_second_t;
using ampere_t = units::current::ampere_t;
using volt_t = units::voltage::volt_t;
using DataLog = wpi::log::DataLog;
using DoubleLogEntry = wpi::log::DoubleLogEntry;

class ArmSubsystem : AbstractSubsystem {
   public:
    ArmSubsystem();
    void Periodic() override;
    units::current::ampere_t getTotalCurrent() override;
    enum class ArmState {
        BOTTOM_POSITION,
        MIDDLE_POSITION,
        TOP_POSITION,
        ZEROING
    };

   private:
    ArmState currentState = ArmState::ZEROING;

    TalonFX frontArmMotor{RobotMap::FRONT_ARM_MOTOR_ID, RobotMap::CANBus};
    TalonFX backArmMotor{RobotMap::BACK_ARM_MOTOR_ID, RobotMap::CANBus};

    MotionMagicVoltage positionRequest{0_tr};

    StatusSignal<turn_t>& frontArmPositionSignal = frontArmMotor.GetPosition();
    StatusSignal<turn_t>& backArmPositionSignal = backArmMotor.GetPosition();
    StatusSignal<turns_per_second_t>& frontArmVelocitySignal = frontArmMotor.GetVelocity();
    StatusSignal<turns_per_second_t>& backArmVelocitySignal = backArmMotor.GetVelocity();
    StatusSignal<ampere_t>& frontArmCurrentSignal = frontArmMotor.GetSupplyCurrent();
    StatusSignal<ampere_t>& backArmCurrentSignal = backArmMotor.GetSupplyCurrent();
    StatusSignal<volt_t>& frontArmVoltageSignal = frontArmMotor.GetMotorVoltage();
    StatusSignal<volt_t>& backArmVoltageSignal = backArmMotor.GetMotorVoltage();

    DataLog& log = frc::DataLogManager::GetLog();
    DoubleLogEntry frontArmPositionEntry = DoubleLogEntry(log, "/Arm/Front/PositionDegrees");
    DoubleLogEntry backArmPositionEntry = DoubleLogEntry(log, "/Arm/Back/PositionDegrees");
    DoubleLogEntry frontArmVelocityEntry = DoubleLogEntry(log, "/Arm/Front/VelocityRPS");
    DoubleLogEntry backArmVelocityEntry = DoubleLogEntry(log, "/Arm/Back/VelocityRPS");
    DoubleLogEntry frontArmCurrentEntry = DoubleLogEntry(log, "/Arm/Front/Current");
    DoubleLogEntry backArmCurrentEntry = DoubleLogEntry(log, "/Arm/Back/Current");
    DoubleLogEntry frontArmVoltageEntry = DoubleLogEntry(log, "/Arm/Front/Voltage");
    DoubleLogEntry backArmVoltageEntry = DoubleLogEntry(log, "/Arm/Back/Voltage");
};
