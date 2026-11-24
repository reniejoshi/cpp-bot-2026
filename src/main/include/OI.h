#pragma once

#include <frc2/command/button/CommandXboxController.h>

#include "../cpp/arm/Arm.h"
#include "RobotContainer.h"
using CommandXboxController = frc2::CommandXboxController;

class OI {
   public:
    OI(RobotContainer& container);

   private:
    static constexpr int DRIVER_CONTROLLER_INDEX = 0;
    static constexpr int MANIP_CONTROLLER_INDEX = 1;
    CommandXboxController driverController{DRIVER_CONTROLLER_INDEX};
    CommandXboxController manipController{MANIP_CONTROLLER_INDEX};
    Arm& arm;
    void bindTeleopControls();
};
