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
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
