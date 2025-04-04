cmake_minimum_required(VERSION 3.8)
project(relbot_simulator)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter)
endif()

# Try to force C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

add_compile_options(-Wno-psabi) # Suppress warnings about ABI changes in GCC 7.1

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS core highgui imgcodecs imgproc videoio)
find_package(cv_bridge REQUIRED)


include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  common
)

# RELbot Simulator executable
add_executable(relbot_simulator 
  src/relbot_simulator.cpp 
  src/Plant.cpp
  common/EulerAngles.cpp
  common/MotionProfiles.cpp
  common/xxfuncs.cpp
  common/xxinteg.cpp
  common/xxinverse.cpp
  common/xxmatrix.cpp
)

ament_target_dependencies(relbot_simulator 
  rclcpp 
  example_interfaces 
  sensor_msgs 
  geometry_msgs
  cv_bridge
)

target_include_directories(relbot_simulator PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/common>
  $<INSTALL_INTERFACE:include>
)
target_compile_features(relbot_simulator PUBLIC c_std_99 cxx_std_17)
target_link_libraries(relbot_simulator
  ${OpenCV_LIBS}
)

# Setpoint Generator executable
add_executable(sequence_controller 
  src/sequence_controller.cpp
)

ament_target_dependencies(sequence_controller 
  rclcpp 
  example_interfaces
  geometry_msgs
  cv_bridge
  sensor_msgs
)

target_include_directories(sequence_controller PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_features(sequence_controller PUBLIC c_std_99 cxx_std_17)

add_executable(colour_tracker 
  src/colour_tracker.cpp
)

ament_target_dependencies(colour_tracker 
  rclcpp 
  example_interfaces
  geometry_msgs
  cv_bridge
  sensor_msgs
  OpenCV
)

target_include_directories(colour_tracker PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_features(colour_tracker PUBLIC c_std_99 cxx_std_17)

target_link_libraries(colour_tracker ${OpenCV_LIBS})

# Install both executables
install(TARGETS relbot_simulator sequence_controller colour_tracker
  DESTINATION lib/${PROJECT_NAME}
)

# Install include and common directories
install(DIRECTORY include/ common/
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

# Install the launch directory
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)