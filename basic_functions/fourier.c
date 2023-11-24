#include <stdlib.h>
#include <stdio.h>
#include "basic_fun.h"

float integral(float *min, float *max) {
    float periode = *max - *min;
    float integral = 0.0;
    float precision = 0.001;

    for (float step = 0.0; (step <= periode); step += precision) {
        
        float actual_result = sin_like_rad(&step);
        float square_area = actual_result * precision;

        integral += square_area;
    }

    return integral;
}
