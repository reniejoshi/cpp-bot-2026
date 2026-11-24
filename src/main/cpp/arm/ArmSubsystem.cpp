#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <units/angle.h>
#include "RobotMap.h"
#include "frc/DataLogManager.h"
#include "ArmSubsystem.h"

ArmSubsystem::ArmSubsystem() {}

void ArmSubsystem::Periodic()
{
    // Refresh and log status signals
}