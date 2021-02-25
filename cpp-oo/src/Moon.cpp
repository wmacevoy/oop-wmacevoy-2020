#include "Moon.h"
#include <stdexcept>

namespace moon {

    Moon::Moon()
      : Satellite(239000.0)
      {
          m_size = 1079.4;
          m_color = "silver";
          m_phase = 0;
      }

    Moon::Moon(double distance, std::string orbits,
                int size, std::string color, int phase) 
        : Satellite(distance,orbits)
    {
        m_size = size;
        m_color = color;
        m_phase = phase;
    }
    bool Moon::isNewMoon() {
        return m_phase == 0;
    }
    void Moon::cycle() {
        m_phase = (m_phase + 1) % 4;
    }
    int Moon::phase() {
        return m_phase;
    }
    std::string Moon::color() {
        return m_color;
    }
    void Moon::color(std::string value) {
        if (!(value == "silver" || value == "white" )) {
            throw std::invalid_argument("invalide color");
        }
        m_color = value;
    }
    
    int Moon::size() {
        return m_size;
    }

}