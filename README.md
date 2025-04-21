Remember to "source install/setup.bash" post build. 

Assignment 3.1: ROS 2 on the Raspberry Pi of the RELbot
----------------------------------------------- 

1. Run 
        ros2 launch relbot_simulator relbot_simulator.launch.py
        Location in code:

2. Open another terminal and run htop to see performance metrics
        htop

Assignment 3.2 XRF2: the FRT software architecture on RELbot’s Raspberry Pi
-----------------------------------------------


1. Build XRF2 msgs package
    colcon build --packages-select xrf2_msgs

2. Run    
    sudo ./build/xcontroller/xcontroller

3. In another terminal run 
    ros2 run ros_xeno_bridge RosXenoBridge

4. In another terminal run 
    ros2 topic pub-once /XenoCmd std_msgs/msg/Int32 "{data: 1}"

   then run
    ros2 topic pub-once /XenoCmd std_msgs/msg/Int32 "{data: 2}"

5. In another terminal run 
    ros2 run xcontrasdfr_19 testing_node \
  --ros-args \
  -p mode:=velocity \
  -p leftmotvel:=8.5 \
  -p rightmotvel:=8.6

  OR (If the testing package couldn't run please run below command instead)

  ros2 topic pub-once /Ros2Xeno xrf2_msgs/msg/Ros2Xeno "(leftmotvel: 0.5, rightmotvel: 0.5)"


Assignment 3.3 Loop-Controller algorithm in FRT part
-----------------------------------------------

1. Run    
    sudo ./build/xcontroller/xcontroller

2. In another terminal run 
    ros2 run ros_xeno_bridge RosXenoBridge

3. In another terminal run 
    ros2 run xcontrasdfr_19 testing_node \
  --ros-args \
  -p mode:=state \
  -p state:=1

    ros2 run xcontrasdfr_19 testing_node \
  --ros-args \
  -p mode:=state \
  -p state:=2

---OR---If the testing node throws error---
    ros2 topic pub-once /XenoCmd std_msgs/msg/Int32 "{data: 1}"

    ros2 topic pub-once /XenoCmd std_msgs/msg/Int32 "{data: 2}"

4. In another terminal run 
    ros2 run xcontrasdfr_19 testing_node \
  --ros-args \
  -p mode:=velocity \
  -p leftmotvel:=8.5 \
  -p rightmotvel:=8.5

  ---OR---If the testing node throws error---

  ros2 topic pub-once /Ros2Xeno xrf2_msgs/msg/Ros2Xeno "(leftmotvel: 0.5, rightmotvel: 0.5)"

  Assignment 3.4 Final integration
-----------------------------------------------

1. Run    
    sudo ./build/xcontroller/xcontroller

2. In another terminal run 
    ros2 run ros_xeno_bridge RosXenoBridge

3. In another terminal run 
    ros2 run xcontrasdfr_19 testing_node \
  --ros-args \
  -p mode:=state \
  -p state:=1


---OR---If the testing node throws error---
    ros2 topic pub-once /XenoCmd std_msgs/msg/Int32 "{data: 1}"

4. In another terminal run 
    ros2 launch relbot_simulator relbot_simulator

---RelBot VIDEO LINK---
https://www.youtube.com/watch?v=MOrrzu2uxVM