#pragma once

#include <string>
#include <memory>

#include "Satellite.h"

namespace moon {

    class Moon : public Satellite {
        private: const int m_size;
        private: std::string m_color;
        private: int m_phase;

        public: Moon();

        public: Moon(double distance, const std::string &orbits, 
                        int size, const std::string &color, int phase = 0);

        public: virtual ~Moon();

        public: bool isNewMoon() const;
        public: void cycle();
        public: int phase() const;
        public: const std::string& color() const;
        public: void color(std::string value);
        public: int size() const;

    };

    typedef std::shared_ptr < Moon > MoonPtr;
}