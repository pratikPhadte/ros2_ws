
#include "xcontroller.hpp"
#include <algorithm>
#define COUNTS_PER_REV 16384  // 14-bit encoder
#define M_PI 3.14

static uint16_t prev_enc1 = 0; //right
static uint16_t prev_enc2 = 0; //left
uint16_t curr_enc1; //right
uint16_t curr_enc2; //left

int16_t get_encoder_delta_14bit(uint16_t current, uint16_t previous) {
    int16_t delta = current - previous;

    // Handle rollover (14-bit unsigned)
    if (delta > 8191)        // + half of 16384
        delta -= 16384;
    else if (delta < -8192)  // - half of 16384
        delta += 16384;

    return delta;
}


xcontroller::xcontroller(uint write_decimator_freq, uint monitor_freq) :
    XenoFrt20Sim(write_decimator_freq, monitor_freq, file, &data_to_be_logged),
    file(1,"./xrf2_logging/TEMPLATE","bin"), // change template to your project name
    controller()
{
     printf("%s: Constructing rampio\n", __FUNCTION__);
    // Add variables to logger to be logged, has to be done before you can log data
    logger.addVariable("this_is_a_int", integer);
    logger.addVariable("this_is_a_double", double_);
    logger.addVariable("this_is_a_float", float_);
    logger.addVariable("this_is_a_char", character);
    logger.addVariable("this_is_a_bool", boolean);
    
    // To infinite run the controller, uncomment line below
    controller.SetFinishTime(0.0);

    u[0] = 0.0;
    u[1] = 0.0;
    u[2] = 0.0;
    u[3] = 0.0;

}

xcontroller::~xcontroller()
{
    
}

int xcontroller::initialising()
{
    // Set physical and cyber system up for use in a 
    // Return 1 to go to initialised state

    evl_printf("Hello from initialising\n");      // Do something

    // The logger has to be initialised at only once
    logger.initialise();
    // The FPGA has to be initialised at least once
    ico_io.init();

    return 1;
}

int xcontroller::initialised()
{
    //i=0;
    // Keep the physical syste in a state to be used in the run state
    // Call start() or return 1 to go to run state
    evl_printf("Hello from initialised\n");       // Do something

    return 1;
}

int xcontroller::run()
{

    // Start logger
    logger.start();                             
    monitor.printf("Hello from run\n");  
    //  Change some data for logger            
    data_to_be_logged.this_is_a_bool = !data_to_be_logged.this_is_a_bool;
    data_to_be_logged.this_is_a_int++;
    if(data_to_be_logged.this_is_a_char == 'R')
        data_to_be_logged.this_is_a_char = 'A';
    else if (data_to_be_logged.this_is_a_char == 'A')
        data_to_be_logged.this_is_a_char = 'M';
    else
        data_to_be_logged.this_is_a_char = 'R';
    data_to_be_logged.this_is_a_float = data_to_be_logged.this_is_a_float/2;
    data_to_be_logged.this_is_a_double = data_to_be_logged.this_is_a_double/4; 
    // Do what you need to do
    // Return 1 to go to stopping state


    curr_enc1 = sample_data.channel1; //right
    curr_enc2 = sample_data.channel2; //left

    evl_printf("curr_enc1: %d\n", curr_enc1);
    evl_printf("curr_enc2: %d\n", curr_enc2);

    evl_printf("prev_enc1: %d\n", prev_enc1);
    evl_printf("prev_enc2: %d\n", prev_enc2);

    // Get rollover-aware deltas
    int16_t delta_enc1 = get_encoder_delta_14bit(curr_enc1, prev_enc1); //right
    int16_t delta_enc2 = get_encoder_delta_14bit(curr_enc2, prev_enc2); //left

    evl_printf("delta_enc1: %d\n", delta_enc1);
    evl_printf("delta_enc2: %d\n", delta_enc2);

   // Save for next run
    prev_enc1 = curr_enc1; //right
    prev_enc2 = curr_enc2; //left

  
    // Convert delta to wheel rotation in radians
    const float counts_per_wheel_rev =15.58* 1024 * 4;
    const float rad_per_count = (2 * M_PI) / counts_per_wheel_rev;

    u[1] += delta_enc1 * rad_per_count;  // right motor
    u[0] += delta_enc2 * rad_per_count;  // left motor
    u[3] = ros_msg.rightmotvel;
    u[2] = ros_msg.leftmotvel;
    

    if(controller.IsFinished())
	 return 1;


    evl_printf("publish val Left Mot From ROS: %f \n ", ros_msg.leftmotvel);
    evl_printf("publish val Right Mot From ROS: %f \n ", ros_msg.rightmotvel);
    
   evl_printf("publish val encoder u[0]: %f \n ", u[0]);
   evl_printf("publish val encoder u[1]: %f \n ", u[1]);
   evl_printf("publish val encoder u[2]: %f \n ", u[2]);
   evl_printf("publish val encoder u[3]: %f \n ", u[3]);

   controller.Calculate(u, y);

   evl_printf("publish val encoder y[0]: %f \n ", y[0]);
   evl_printf("publish val encoder y[1]: %f \n ", y[1]);


   double right_motor_vel = y[1];
   double left_motor_vel = y[0];

   //Clamp the values within -2047 and +2047
   right_motor_vel = std::clamp(right_motor_vel, -2047.0, 2047.0);
   left_motor_vel  = std::clamp(left_motor_vel, -2047.0, 2047.0);

   evl_printf("Clamped left motor vel : %f \n",left_motor_vel);
   evl_printf("Clamped right motor vel: %f \n",right_motor_vel);

   actuate_data.pwm1=right_motor_vel;
   actuate_data.pwm2=left_motor_vel;

   return 0;
}

int xcontroller::stopping()
{

    actuate_data.pwm1=0;
    actuate_data.pwm2=0;
    // Bring the physical system to a stop and set it in a state that the system can be deactivated
    // eturn 1 to go to stopped state
    logger.stop();                                // Stop logger
    evl_printf("Hello from stopping\n");          // Do something

    return 1;
}

int xcontroller::stopped()
{
    // A steady state in which the system can be deactivated whitout harming the physical system

    monitor.printf("Hello from stopping\n");          // Do something

    return 0;
}

int xcontroller::pausing()
{
    // Bring the physical system to a stop as fast as possible without causing harm to the physical system

    evl_printf("Hello from pausing\n");           // Do something
    return 1 ;
}

int xcontroller::paused()
{
    // Keep the physical system in the current physical state

    monitor.printf("Hello from paused\n");            // Do something
    return 0;
}

int xcontroller::error()
{
    // Error detected in the system 
    // Can go to error if the previous state returns 1 from every other state function but initialising 

    monitor.printf("Hello from error\n");             // Do something

    return 0;
}
