// Copyright (c) 2026 FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/CommandPtr.h>

class Arm {
    frc2::CommandPtr MoveToTopPosition();
    frc2::CommandPtr MoveToMiddlePosition();
    frc2::CommandPtr MoveToBottomPosition();
};
