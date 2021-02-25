#pragma once

#include <string>


namespace moon {

class Satellite {
    private: double m_distance;
    private: std::string m_orbits;
    public: Satellite(double distance);
    public: Satellite(double distance, const std::string &orbits);

    public: double distance();
    public: void distance(double value);
    public: std::string orbits();
};


}