// Copyright (c) 2026 FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "ArmSubsystem.h"

#include <frc2/command/SubsystemBase.h>
#include <units/angle.h>

#include <ctre/phoenix6/TalonFX.hpp>

#include "RobotMap.h"
#include "frc/DataLogManager.h"

ArmSubsystem::ArmSubsystem() {}

void ArmSubsystem::Periodic() {
    // Refresh and log status signals
}
