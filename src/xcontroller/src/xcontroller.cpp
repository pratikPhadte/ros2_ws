
#include "xcontroller.hpp"
#include <algorithm>

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
   i=0;
    // Keep the physical syste in a state to be used in the run state
    // Call start() or return 1 to go to run state
       evl_printf("Hello from initialised\n");       // Do something

    return 0;
}

int xcontroller::run()
{
    // Do what you need to do
    // Return 1 to go to stopping state
    initial_u0 = sample_data.channel1;
   initial_u1 = sample_data.channel2;
   evl_printf("inital value right mot: %f\n", initial_u0);
   evl_printf("inital value left mot: %f\n", initial_u1);


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

    controller.Calculate(u, y);
    if(controller.IsFinished())
	 return 1;
// Printf encoder 1 to 4 data
    evl_printf("Encoder 1 value : %d\n",sample_data.channel1);
    evl_printf("Encoder 2 value : %d\n",sample_data.channel2);
//    evl_printf("Encoder 3 value : %d\n",sample_data.channel3);
//    evl_printf("Encoder 4 value : %d\n",sample_data.channel4);

    
    evl_printf("publish val Left Mot: %f \n ", ros_msg.leftmotvel);
    evl_printf("publish val Right Mot: %f \n ", ros_msg.rightmotvel);
    
// Set motor outputs to 25% of max
//XXDouble y;
//controller.Calculate(0.25, &y);
if(i == 0)
{

   u[0] = (sample_data.channel1-initial_u0)*((2*3.14)/(16384*4)); //right
   u[1] = (sample_data.channel2-initial_u1)*((2*3.14)/(16384*4)); //left
   u[2] = ros_msg.rightmotvel;
   u[3] = ros_msg.leftmotvel;
   i=1;
}
else
{
   float new_initial_u0 = initial_u0 + 16383;
   float new_initial_u1 = initial_u1 + 16383;
   u[0] = (sample_data.channel1 - new_initial_u0)*((2*3.14)/(16384*4)); //right
   u[1] = (sample_data.channel2 - new_initial_u1)*((2*3.14)/(16384*4)); //left
   u[2] = ros_msg.rightmotvel;
   u[3] = ros_msg.leftmotvel;

   initial_u0  = new_initial_u0;
   initial_u1 = new_initial_u1;
    
}

    evl_printf("publish val encoder u[0]: %f \n ", u[0]);
    evl_printf("publish val encoder u[1]: %f \n ", u[1]);
   controller.Calculate(u,y);

   double right_motor_vel = y[0];
   double left_motor_vel = y[1];
   //Clip the values within -2047 and +2047
   right_motor_vel = std::clamp(right_motor_vel, -2047.0, 2047.0);
   left_motor_vel  = std::clamp(left_motor_vel, -2047.0, 2047.0);
   evl_printf("Calculated left motor vel : %f \n",left_motor_vel);
   evl_printf("Calculated right motor vel: %f \n",right_motor_vel);

      
//   actuate_data.pwm1 = right_motor_vel;
//  actuate_data.pwm2 = left_motor_vel;


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
