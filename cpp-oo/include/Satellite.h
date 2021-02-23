#pragma once

#include <string>

namespace moon {

class Satellite {
    double m_distance;
    std::string m_orbits;
    Satellite(double distance, std::string orbits);

    double distance();
    std::string orbits();
};


}