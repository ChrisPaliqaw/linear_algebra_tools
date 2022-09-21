cmake_minimum_required(VERSION 3.5)
project(linear_algebra_tools)
set(LIBRARY_NAME linear_algebra_lib)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# tell CMake to add this directory to the target's include path
include_directories(include/${PROJECT_NAME})
# you can use just the file you're using but this is mostly used for multiple header files
set(HEADER_FILES include/${PROJECT_NAME}/linear_algebra.hpp)
add_library(${LIBRARY_NAME} src/linear_algebra.cpp ${HEADER_FILES})


add_executable(main src/main.cpp)
 # this is important to tell CMake that the executable "main" depends on the library "my_lib"
target_link_libraries(main PUBLIC ${LIBRARY_NAME})

# this installs the executable in the lib folder to be seen by setup.bash to be seen by ros2
install(TARGETS 
  main
  DESTINATION lib/${PROJECT_NAME}/
)

# this line to export the targets, in our case it's a library
ament_export_targets(${LIBRARY_NAME} HAS_LIBRARY_TARGET)

ament_target_dependencies(${LIBRARY_NAME}
	rclcpp
)

# install the include/my_cpp_library directory to the install/include/my_cpp_library
install(
  DIRECTORY include/${PROJECT_NAME}
  DESTINATION include
)

install(
  TARGETS ${LIBRARY_NAME}
  EXPORT ${LIBRARY_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

ament_package()
