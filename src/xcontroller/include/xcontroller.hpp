#ifndef TEMPLATE20SIM_HPP
#define TEMPLATE20SIM_HPP

#include "XenoFrt20Sim.hpp"
#include "LoopController.h"
#include <algorithm>

#pragma pack (1)    //https://carlosvin.github.io/langs/en/posts/cpp-pragma-pack/#_performance_test
struct ThisIsAStruct
{
    int this_is_a_int = 0;
    double this_is_a_double = 100.0;
    float this_is_a_float = 10.0;
    char this_is_a_char = 'R';
    bool this_is_a_bool = false;
};

#pragma pack(0)

class xcontroller : public XenoFrt20Sim
{
public:
    xcontroller(uint write_decimator_freq, uint monitor_freq);
    ~xcontroller();


//    static uint16_t prev_enc1;
//    static uint16_t prev_enc2;

   uint16_t curr_enc1 ;
   uint16_t curr_enc2 ;
private:
    XenoFileHandler file;
    struct ThisIsAStruct data_to_be_logged;
    LoopController controller;

    double u[4];
    double y[2];

    // int initial_right;
    // int initial_left;
    // int previous_right;
    // int previous_left;
    // int delta_right;
    // int delta_left;

   int total_counts_left = 0;
   int total_counts_right = 0;




   int i;
protected:
    //Functions
    int initialising() override;
    int initialised() override;
    int run() override;
    int stopping() override;
    int stopped() override;
    int pausing() override;
    int paused() override;
    int error() override;
    void clip();

    // current error
    int current_error = 0;


};

#endif // TEMPLATE20SIM_HPP
