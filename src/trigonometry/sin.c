#include <stdlib.h>
#include "../../include/trigonometry/change_length.h"
#include "../../include/basic_functions/factorial.h"
#include "../../include/basic_functions/power.h"

/*
 * sinus
 */ 

float sin_like_rad(float *number) {    
/*
 * use of the taylor serie
 */ 
    float number_changed_length = change_length(number);
    //change_length(number);

    float result_sin = number_changed_length;
    //float result_sin = *number;
    float signe = -1.0;
    float change_signe = 1.0;

    for (float iterator = 3.0; (iterator <= 20); iterator += 2) {
        float powered = pow_like(&number_changed_length, &iterator);
        //float powered = pow_like(number, &iterator);
        float divised = powered / factorial_like(&iterator);

        float pre_result = pow_like(&signe, &change_signe) * divised;

        result_sin += pre_result;

        change_signe++;
    }

    return result_sin;
}

float sin_like_deg(float *number) {
    // conversion to radiant value :
    float one_turn = 360.0;
    float two_pi = 6.283185;
    float rad_convert = (*number * two_pi) / one_turn;
    
    float result_sin = sin_like_rad(&rad_convert);

    return result_sin;
}
