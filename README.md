# linear_algebra_tools
Demonstrates the creation of a simple ROS2 package containing a math library, and testing it with GTest. Developed using a git feature branch

# Development process
- Checked the project out to ros2_ws
- Added the branch `add-google-test` to the package `linear_algebra_tools`
- When development of the tests was complete, I was able to run the tests

```
colcon test --packages-select linear_algebra_tools --event-handler=console_direct+
```

- I merged the branch into the main branch

```
user:~/ros2_ws/src/linear_algebra_tools$ git merge add-google-test
Updating 5983a39..b39f3b4
Fast-forward
 CMakeLists.txt                                  | 30 ++++++++++++++++++--
 include/linear_algebra_tools/linear_algebra.hpp |  7 ++---
 src/linear_algebra.cpp                          | 14 +++++----
 src/main.cpp                                    | 28 +++++++++++++++++-
 test/linear_algebra_tools_test.cpp              | 81 +++++++++++++++++++++++++++++++++++++++++++++++++++++
 test/main.cpp                                   |  6 ++++
 6 files changed, 154 insertions(+), 12 deletions(-)
 create mode 100644 test/linear_algebra_tools_test.cpp
 create mode 100644 test/main.cpp
```

- Here's my git log at that time

```
user:~/ros2_ws/src/linear_algebra_tools$ git log --graph --oneline
* b39f3b4 (HEAD -> main, origin/main, origin/add-google-test, add-google-test) feature: Magnitude uses float instead of double style: Some brackets moved
* dfa5d8c test fix: Main test uses fabs instead of abs refactor: Library functions use UpperCamelCase instead of snake_case
* 3261eab test: Test euler_to_quaternion using main function   and cassert test: Test using GTest, including a test fixture
* 3a6eade fix: Depend only on tf2_geometry_msgs feature: main binary tests euler_from_quaternion
* 5983a39 feature: ROS2 linear algebra package compiles successfully
```
