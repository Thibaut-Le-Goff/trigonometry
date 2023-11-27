#include <stdlib.h>

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
