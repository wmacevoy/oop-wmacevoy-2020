#include "Moon.h"
#include <stdexcept>
#include <iostream>

namespace moon {

    Moon::Moon()
      : Satellite(239000.0), m_size(1079.4)
      {
          m_color = "silver";
          m_phase = 0;
          std::cout << "Moon@" << (void*) this << " constructed." << std::endl;

      }

    Moon::Moon(double distance, const std::string &orbits,
                int size, const std::string &color, int phase) 
        : Satellite(distance,orbits), m_size(size)
    {
        m_color = color;
        m_phase = phase;
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
    
    int Moon::size() const {
        return m_size;
    }

}