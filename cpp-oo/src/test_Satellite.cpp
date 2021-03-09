#include "Satellite.h"
#include "Moon.h"
#include "gtest/gtest.h"

using namespace std;
using namespace moon;

TEST(Satellite, Constructor) {
      double distance = 3.14;
      string orbits("earth");
      int size = 1079.4;
      string color = "silver";
      int phase = 0;




      Moon satellite(distance,orbits, size, color, phase);
      ASSERT_EQ(satellite.distance(),distance);
      ASSERT_EQ(satellite.orbits(),orbits);
      double newDistance = 13;
      satellite.distance(newDistance);
      ASSERT_EQ(satellite.distance(),newDistance);
}

TEST(Satellite, Constness) {
      double distance = 3.14;
      string orbits("earth");
      int size = 1079.4;
      string color = "silver";
      int phase = 0;

      const Moon satellite(distance,orbits, size, color, phase);
      ASSERT_EQ(satellite.distance(),distance);
      ASSERT_EQ(satellite.orbits(),orbits);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
