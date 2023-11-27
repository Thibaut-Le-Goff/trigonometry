#include <stdlib.h>

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
