#include "Moon.h"
#include <stdexcept>
#include <iostream>
#include <math.h>

namespace moon {

    const double Moon::MOON_ORBIT_TIME=27.322;

    Moon::Moon()
      : Moon(239000.0, DEFAULT_ORBITS, 1079.4,"silver",0)
      {
      }

    Moon::Moon(double distance, const std::string &orbits,
                int size, const std::string &color, int phase) 
        : Satellite(distance,orbits), m_size(size), m_color(color), m_phase(phase),
        m_time((MOON_ORBIT_TIME/4.0)*(phase+0.5))
    {
          std::cout << "Moon@" << (void*) this << " constructed." << std::endl;
    }

    Moon::~Moon() {
          std::cout << "Moon@" << (void*) this << " destructed." << std::endl;
    }
    bool Moon::isNewMoon() const {
        return m_phase == 0;
    }
    void Moon::cycle() {
        m_phase = (m_phase + 1) % 4;
        m_time += MOON_ORBIT_TIME/4.0;
    }

    void Moon::advance(double amount) {
        m_time += amount;
        m_phase = int(4*(m_time/MOON_ORBIT_TIME)) % 4;
    }

    int Moon::phase() const {
        return m_phase;
    }
    const std::string& Moon::color() const {
        return m_color;
    }
    void Moon::color(std::string value) {
        if (!(value == "silver" || value == "white" )) {
            throw std::invalid_argument("invalide color");
        }
        m_color = value;
    }
    
    double Moon::time() const { return m_time; }

    int Moon::size() const {
        return m_size;
    }

}