#include "Satellite.h"

namespace moon {
    const std::string Satellite::DEFAULT_ORBITS("earth");
    
    Satellite::Satellite(double distance) 
      : m_distance(distance), m_orbits(DEFAULT_ORBITS)
    {
    }

    Satellite::Satellite(double distance, const std::string &orbits) 
     : m_distance(distance), m_orbits(orbits)
    {
    }

    double Satellite::distance() const { 
        return m_distance; 
    }
    void Satellite::distance(double value) { m_distance = value; }

    const std::string& Satellite::orbits() const { return m_orbits; }

}