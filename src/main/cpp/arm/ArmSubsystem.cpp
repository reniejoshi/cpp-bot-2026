// Copyright (c) 2026 FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "ArmSubsystem.h"

#include <frc2/command/SubsystemBase.h>
#include <units/angle.h>

#include <ctre/phoenix6/TalonFX.hpp>

#include "ArmConstants.h"
#include "RobotMap.h"
#include "frc/DataLogManager.h"

using degree_t = units::angle::degree_t;

ArmSubsystem::ArmSubsystem() : AbstractSubsystem("Arm") {}

void ArmSubsystem::Periodic() {
    ctre::phoenix6::BaseStatusSignal::RefreshAll(frontArmPositionSignal, backArmPositionSignal, frontArmVelocitySignal, backArmVelocitySignal, frontArmCurrentSignal, backArmCurrentSignal, frontArmVoltageSignal, backArmVoltageSignal);

    frontArmPositionEntry.Append(units::angle::degree_t{frontArmPositionSignal.GetValue()}.value());
    backArmPositionEntry.Append(units::angle::degree_t{backArmPositionSignal.GetValue()}.value());
    frontArmVelocityEntry.Append(frontArmVelocitySignal.GetValue().value());
    backArmVelocityEntry.Append(backArmVelocitySignal.GetValue().value());
    frontArmCurrentEntry.Append(frontArmCurrentSignal.GetValue().value());
    backArmCurrentEntry.Append(backArmCurrentSignal.GetValue().value());
    frontArmVoltageEntry.Append(frontArmVoltageSignal.GetValue().value());
    backArmVoltageEntry.Append(backArmVoltageSignal.GetValue().value());
}

units::current::ampere_t ArmSubsystem::getTotalCurrent() {
    return frontArmCurrentSignal.GetValue() + backArmCurrentSignal.GetValue();
}

void ArmSubsystem::SetState(ArmState newState) {
    currentState = newState;
    degree_t targetAngle = [&]() -> degree_t {
        switch (currentState) {
            case ArmState::TOP_POSITION:
                return ArmConstants::TOP_POSITION;
            case ArmState::MIDDLE_POSITION:
                return ArmConstants::MIDDLE_POSITION;
            case ArmState::BOTTOM_POSITION:
                return ArmConstants::BOTTOM_POSITION;
        }
    }();
    frontArmMotor.SetControl(positionRequest.WithPosition(targetAngle));
}
