#include <frc2/command/CommandPtr.h>

class Arm
{
    frc2::CommandPtr MoveToTopPosition();
    frc2::CommandPtr MoveToMiddlePosition();
    frc2::CommandPtr MoveToBottomPosition();
};