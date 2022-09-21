// #include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <cassert>
#include <cmath>
#include <iostream>
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
#include "linear_algebra.hpp"

void AssertCloseEnough(float lhs, float rhs)
{
  float close_enough = 0.001;
  assert(abs(lhs - rhs) <= close_enough);
}

int main()
{
  float roll = 0.1f;
  float pitch = 0.2f;
  float yaw = 0.3f;
  
  tf2::Quaternion q;
  q.setRPY(roll, pitch, yaw);
  geometry_msgs::msg::Vector3 v3 =
    linear_algebra_utilities::euler_from_quaternion(q);
  std::cout << v3.x << std::endl;
  std::cout << v3.y << std::endl;
  std::cout << v3.z << std::endl;
  AssertCloseEnough(v3.x, roll);
  AssertCloseEnough(v3.y, pitch);
  AssertCloseEnough(v3.z, yaw);

  return 0;
}