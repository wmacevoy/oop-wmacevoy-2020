#include "Moon.h"
#include "gtest/gtest.h"

using namespace std;
using namespace moon;

TEST(Moon, Constructor) {
      int size = 3;
      string color = "blue";
      int phase = 0;
      Moon moon(size, color, phase);
      ASSERT_EQ(moon.phase(),phase);
      ASSERT_EQ(moon.color(),color);
      ASSERT_EQ(moon.size(),size);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
