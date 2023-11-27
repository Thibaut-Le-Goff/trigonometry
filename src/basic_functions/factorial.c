#include <stdlib.h>

float factorial_like(float *number) {
    float result_factorial = 1.0;

    for (int iterator = 1; (iterator <= *number); iterator++) {
        result_factorial *= iterator;
    }

    return result_factorial;
}