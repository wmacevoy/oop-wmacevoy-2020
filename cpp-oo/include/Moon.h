#pragma once

#include <string>

namespace moon {

    class Moon {
        private: int m_size;
        private: std::string m_color;
        private: int m_phase;

        public: Moon(int size, std::string color, int phase = 0);

        public: bool isNewMoon();
        public: void cycle();
        public: int phase();
        public: std::string color();
        public: void color(std::string value);
        public: int size();

    };
}