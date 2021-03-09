#pragma once

#include <string>
#include <memory>


namespace moon {

class Satellite {
    public: static const std::string DEFAULT_ORBITS;  // 1.
    private: double m_distance; // 1 per instance
    private: const std::string m_orbits; // 1 per instance
    public: Satellite(double distance);
    public: Satellite(double distance, const std::string &orbits);

    public: double distance() const;
    public: void distance(double value);
    public: const std::string& orbits() const;
    public: virtual void advance(double duration); 
    public: virtual ~Satellite();
};

typedef std::shared_ptr < Satellite > SatellitePtr;


}