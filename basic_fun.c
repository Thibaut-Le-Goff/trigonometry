#include <stdio.h>
#include <stdlib.h>

#include "basic_fun.h"


float factorial_like(float number) {
    float result_factorial = 1.0;

    for (float iterator = 1.0; (iterator <= number); iterator++) {
        result_factorial *= iterator;
    }

    return result_factorial;
}

float pow_like(float number, float power) {
    float result_pow = number;
    
    for (float iterator = 1.0; (iterator < abs(power)); iterator++) {
        if (power < 0.0) {
            result_pow *= number;
        } else {
            result_pow *= number;
        }
    }

    return result_pow;
}

/*
float taylor_serie_sin(float number) {
    for (float iterator = 3.0; (iterator <= 40); iterator += 2) {
        float powered = pow_like(number, iterator);
        float divised = powered / factorial_like(iterator);

        float pre_result = pow_like(-1.0, change_signe) * divised;

        result_sin += pre_result;

        change_signe = change_signe + 1.0;
    }

}
*/

float sin_like_rad(float number) {
    float change_signe = 1.0;

    float two_pi = 6.283185;

    // if the number as input is higher than 2*pi :
    // we will have to cut to the number of excess circles
    if (number > two_pi || number < -two_pi) {
        // count the amount of turn made by the number :
        float number_circle = number / (two_pi);
        // round down the number of circle made (putting in an int)
        // and as this represent the number of circle made
        // we have to remember it with * (two_pi)
        float number_circle_rounded_down = (int)number_circle * (two_pi);

        // cutting the number of excess circles
        number = number - number_circle_rounded_down;
    }
    
    float result_sin = number;

/*
 * use of the taylor serie
 */ 
    for (float iterator = 3.0; (iterator <= 40); iterator += 2) {
        float powered = pow_like(number, iterator);
        float divised = powered / factorial_like(iterator);

        float pre_result = pow_like(-1.0, change_signe) * divised;

        result_sin += pre_result;

        change_signe = change_signe + 1.0;
    }

    return result_sin;
}