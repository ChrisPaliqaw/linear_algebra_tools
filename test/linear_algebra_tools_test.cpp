#include <cassert>
#include <cmath>
#include <iostream>
#include <gtest/gtest.h>
#include <geometry_msgs/msg/detail/vector3__struct.hpp>
#include "linear_algebra.hpp"

namespace linear_algebra_utilities {

class LinearAlgebraToolsTest : public ::testing::Test
{
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  LinearAlgebraToolsTest()
  {
    q.setRPY(roll, pitch, yaw);
    v3 = EulerFromQuaternion(q);
    five_eleven_twelve.set__x(a);
    five_eleven_twelve.set__y(b);
    five_eleven_twelve.set__z(0.0f);
  }

  ~LinearAlgebraToolsTest() override
  {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override
  {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override
  {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.
  float close_enough = 0.1f;

  float roll = 0.11f;
  float pitch = 0.21f;
  float yaw = 0.31f;
  geometry_msgs::msg::Vector3 v3;
  tf2::Quaternion q;

  float a = 5.0f;
  float b = 11.0f;
  float c = 12.0f;
  geometry_msgs::msg::Vector3 five_eleven_twelve;
};

TEST_F(LinearAlgebraToolsTest, EulerFromQuaternionReverseRollTest)
{
  EXPECT_NEAR(v3.x, roll, close_enough);
}

TEST_F(LinearAlgebraToolsTest, EulerFromQuaternionReversePitchTest)
{
  EXPECT_NEAR(v3.y, pitch, close_enough);
}

TEST_F(LinearAlgebraToolsTest, EulerFromQuaternionReverseYawTest)
{
  EXPECT_NEAR(v3.z, yaw, close_enough);
}

TEST_F(LinearAlgebraToolsTest, MagnitudeTest)
{
  EXPECT_NEAR(Magnitude(five_eleven_twelve), c, close_enough);
}

} // namespace linear_algebra_utilities