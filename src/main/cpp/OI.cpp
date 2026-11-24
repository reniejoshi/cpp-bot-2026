// Copyright (c) 2026 FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "OI.h"

OI::OI(RobotContainer& container) : arm(container.arm) {
    bindTeleopControls();
}

void OI::bindTeleopControls() {
    manipController.POVUp().OnTrue(arm.MoveToTopPosition());
    manipController.POVLeft().OnTrue(arm.MoveToMiddlePosition());
    manipController.POVRight().OnTrue(arm.MoveToMiddlePosition());
    manipController.POVDown().OnTrue(arm.MoveToBottomPosition());
}
