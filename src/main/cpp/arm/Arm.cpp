// Copyright (c) 2026 FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Arm.h"

#include <frc2/command/Commands.h>
using frc2::cmd::RunOnce;

frc2::CommandPtr Arm::MoveToTopPosition() {
    return RunOnce([this] { arm.SetState(ArmSubsystem::ArmState::TOP_POSITION); }, {&arm});
}

frc2::CommandPtr Arm::MoveToMiddlePosition() {
    return RunOnce([this] { arm.SetState(ArmSubsystem::ArmState::MIDDLE_POSITION); }, {&arm});
}

frc2::CommandPtr Arm::MoveToBottomPosition() {
    return RunOnce([this] { arm.SetState(ArmSubsystem::ArmState::BOTTOM_POSITION); }, {&arm});
}
