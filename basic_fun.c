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
    
    for (float iterator = 1.0; (iterator < power); iterator++) {
        result_pow *= number;
    }

    return result_pow;
}

float sin_like(float number) {
    float result_sin = number;
    
    for (float iterator = 3.0; (iterator <= number); iterator += 2) {
        result_sin += pow_like(-1.0, iterator) * iterator;
    }

    return result_sin;
}