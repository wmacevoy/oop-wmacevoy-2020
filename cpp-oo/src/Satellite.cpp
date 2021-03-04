#include "Satellite.h"

#include <iostream>

namespace moon {
    const std::string Satellite::DEFAULT_ORBITS("earth");
    
    Satellite::Satellite(double distance) 
      : m_distance(distance), m_orbits(DEFAULT_ORBITS)
    {
      std::cout << "Satellite@" << (void*) this << " constructed." << std::endl;
    }

    Satellite::Satellite(double distance, const std::string &orbits) 
     : m_distance(distance), m_orbits(orbits)
    {
      std::cout << "Satellite@" << (void*) this << " constructed." << std::endl;
    }

    double Satellite::distance() const { 
        return m_distance; 
    }
    void Satellite::distance(double value) { m_distance = value; }

    const std::string& Satellite::orbits() const { return m_orbits; }

    Satellite::~Satellite() {
      std::cout << "Satellite@" << (void*) this << " destructed." << std::endl;
      

    }

}