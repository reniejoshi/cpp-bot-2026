#pragma once

#include <ctre/phoenix6/CANBus.hpp>

class RobotMap
{
public:
    static constexpr ctre::phoenix6::CANBus CANBus = ctre::phoenix6::CANBus::RoboRIO();

    static constexpr int FRONT_ARM_MOTOR_ID = 10;
    static constexpr int BACK_ARM_MOTOR_ID = 20;
};
