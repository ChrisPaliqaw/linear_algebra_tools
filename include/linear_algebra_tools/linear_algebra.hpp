#ifndef LINEAR_ALGEBRA_UTILITIES_LINEAR_ALGEBRA_HPP_
#define LINEAR_ALGEBRA_UTILITIES_LINEAR_ALGEBRA_HPP_

//#include <rclcpp/rclcpp.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

namespace linear_algebra_utilities {

geometry_msgs::msg::Vector3 EulerFromQuaternion(tf2::Quaternion q);
float Magnitude(geometry_msgs::msg::Vector3 v3);

} // namespace linear_algebra_utilities
#endif // LINEAR_ALGEBRA_UTILITIES_LINEAR_ALGEBRA_HPP_