#ifndef LINEAR_ALGEBRA_UTILITIES_LINEAR_ALGEBRA_HPP_
#define LINEAR_ALGEBRA_UTILITIES_LINEAR_ALGEBRA_HPP_

//#include <rclcpp/rclcpp.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

namespace linear_algebra_utilities {

geometry_msgs::msg::Vector3 euler_from_quaternion(tf2::Quaternion q);
double magnitude(geometry_msgs::msg::Vector3 v3);

} // namespace linear_algebra_utilities
#endif // LINEAR_ALGEBRA_UTILITIES_LINEAR_ALGEBRA_HPP_