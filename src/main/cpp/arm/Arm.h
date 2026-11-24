#pragma once

#include <frc2/command/CommandPtr.h>

#include "ArmSubsystem.h"

class Arm {
   public:
    Arm() = default;
    frc2::CommandPtr MoveToTopPosition();
    frc2::CommandPtr MoveToMiddlePosition();
    frc2::CommandPtr MoveToBottomPosition();

   private:
    ArmSubsystem arm;
};
