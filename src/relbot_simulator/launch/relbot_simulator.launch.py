from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node

def generate_launch_description():
    # Launch argument for Twist command mode
    use_twist_cmd_arg = DeclareLaunchArgument(
        name="use_twist_cmd",
        default_value="false",
        description="Whether to use Twist command mode. If set to false, uses individual motor command mode.",
    )   

    # Launch argument for mode selection (tracking/testing)
    mode_arg = DeclareLaunchArgument(
        name="mode",
        default_value="tracking",
        description="Mode selection: tracking or testing",
    )

    return LaunchDescription([
        use_twist_cmd_arg,
        mode_arg,

        # relbot_simulator Node
        Node(
            package='relbot_simulator',
            executable='relbot_simulator',
            name='relbot_simulator',
            parameters=[
                {"use_twist_cmd": LaunchConfiguration("use_twist_cmd")},
            ],
        ),

        # ColourTracker Node with cam_input argument
        Node(
            package='relbot_simulator',
            executable='colour_tracker',
            name='colour_tracker',
            output="screen",
            
        ),

        Node(
            package='image_tools',
            executable='cam2image',
            name='cam2image',
            output='screen',
        ),

        # SequenceController Node
        Node(
            package='relbot_simulator',
            executable='sequence_controller',
            name='sequence_controller',
            output='screen',
            parameters=[
                {"mode": LaunchConfiguration("mode")},
                
            ],
        ),
    ])
