#include "Moon.h"
#include "gtest/gtest.h"

using namespace std;
using namespace moon;

TEST(Moon, Constructor) {
      double distance = 3.14;
      std::string orbits = "earth";
      int size = 3;
      string color = "blue";
      int phase = 0;
      Moon moon(distance, orbits, size, color, phase);
      ASSERT_EQ(moon.distance(),distance);
      ASSERT_EQ(moon.orbits(),orbits);
      ASSERT_EQ(moon.phase(),phase);
      ASSERT_EQ(moon.color(),color);
      ASSERT_EQ(moon.size(),size);
}


TEST(Moon, DefaultConstructor) {
      double distance = 239000.0;
      std::string orbits = "earth";
      int size = 1079.4;
      string color = "silver";
      int phase = 0;
      Moon moon;
      ASSERT_EQ(moon.distance(),distance);
      ASSERT_EQ(moon.orbits(),orbits);
      ASSERT_EQ(moon.phase(),phase);
      ASSERT_EQ(moon.color(),color);
      ASSERT_EQ(moon.size(),size);
}

TEST(Moon, MoonAsSatellite) {
      std::shared_ptr < Satellite > pSat (new Moon());

      std::shared_ptr < Satellite > qSat (new Satellite(33.3));

      ASSERT_EQ(pSat->orbits(), Satellite::DEFAULT_ORBITS);
      ASSERT_EQ(qSat->orbits(), Satellite::DEFAULT_ORBITS);
}

TEST(Moon, MoonAsSatelliteBad1) {
      Satellite *pSat=new Moon();
      Satellite *qSat=new Satellite(33.3);

      ASSERT_EQ(pSat->orbits(), Satellite::DEFAULT_ORBITS);
      ASSERT_EQ(qSat->orbits(), Satellite::DEFAULT_ORBITS);
}

TEST(Moon,phaseAndTime) {
      Moon moon;
      double eps=1e-9;
      ASSERT_EQ(moon.phase(),0);
      ASSERT_NEAR(moon.time(),Moon::MOON_ORBIT_TIME/8.0,eps);
      double time0=moon.time();
      moon.advance(Moon::MOON_ORBIT_TIME/2);
      ASSERT_NEAR(moon.time(),5*Moon::MOON_ORBIT_TIME/8.0,eps);
      ASSERT_EQ(moon.phase(),2);
      moon.cycle();
      ASSERT_NEAR(moon.time()-time0,0.75*Moon::MOON_ORBIT_TIME,eps);
}

TEST(Moon, MoonAsSatelliteBad2) {
      Satellite *pSat=new Moon();
      Satellite *qSat=new Satellite(33.3);

      ASSERT_EQ(pSat->orbits(), Satellite::DEFAULT_ORBITS);
      ASSERT_EQ(qSat->orbits(), Satellite::DEFAULT_ORBITS);

      delete pSat; // only cleans satelliteness!!!! 
      delete qSat;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
