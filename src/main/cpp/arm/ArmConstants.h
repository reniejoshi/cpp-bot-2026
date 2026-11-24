#pragma once

#include <units/angle.h>

using degree_t = units::angle::degree_t;

class ArmConstants {
   public:
    static constexpr degree_t TOP_POSITION = 32_deg;
    static constexpr degree_t MIDDLE_POSITION = -18_deg;
    static constexpr degree_t BOTTOM_POSITION = -23_deg;
};
