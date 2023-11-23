#include <stdlib.h>

float factorial_like(float *number) {
    float result_factorial = 1.0;

    for (int iterator = 1; (iterator <= *number); iterator++) {
        result_factorial *= iterator;
    }

    return result_factorial;
}

float pow_like(float *number, float *power) {
    float result_pow = *number;
    
    if (*power == 0.0 || *power == -0.0) {
        result_pow = 1.0;
    }
    else if  (*power > 0.0) {
        for (int iterator = 1; (iterator < abs(*power)); iterator++) {
            result_pow *= *number;
        }
    }
    else if (*power < 0.0) {
        for (int iterator = 1; (iterator < abs(*power) + 2.0); iterator++) {
            result_pow /= *number;
        }
    }

    return result_pow;
}

float change_length(float *number) {
    float two_pi = 6.283185;

    // if the *number as input is higher than 2*pi :
    // we will have to cut to the *number of excess circles
    // count the amount of turn made by the *number :
    float number_circle = *number / two_pi;

    // round down the *number of circle made (putting in an int)
    // and as this represent the *number of circle made
    // we have to remember it with * (two_pi)
    float number_circle_rounded_down = (int)number_circle * two_pi;

    // cutting the *number of excess circles
    // if the *number as input is lower than 2*pi
    // it will just do : *number -= 0.0;
    //number -= number_circle_rounded_down;
    float number_changed_length = *number - number_circle_rounded_down;

    return number_changed_length;
}

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

/*
 * cosinus
 */ 

float cos_like_rad(float *number) {    
/*
 * use of the taylor serie
 */ 
    float number_changed_length = change_length(number);
    //change_length(number);
    
    float result_sin = 1.0;
    float signe = -1.0;
    float change_signe = 1.0;

    for (float iterator = 2.0; (iterator <= 20); iterator += 2) {
        float powered = pow_like(&number_changed_length, &iterator);
        //float powered = pow_like(number, &iterator);
        float divised = powered / factorial_like(&iterator);

        float pre_result = pow_like(&signe, &change_signe) * divised;

        result_sin += pre_result;

        change_signe++;
    }

    return result_sin;
}

float cos_like_deg(float *number) {
    // conversion to radiant value :
    float one_turn = 360.0;
    float two_pi = 6.283185;
    float rad_convert = (*number * two_pi) / one_turn;
    
    float result_sin = cos_like_rad(&rad_convert);

    return result_sin;
}