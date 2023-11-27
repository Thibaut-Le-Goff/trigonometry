#include <stdlib.h>
#include <stdio.h>
#include "../../include/trigonometry/sin.h"
#include "../../include/trigonometry/cos.h"

float integral(float *min, float *max) {
    float integral = 0.0;
    float precision = 0.01;

    if (*min < *max) {
        for (float step = *min; (step <= *max); step += precision) {
        
            float actual_result = sin_like_rad(&step);
            float rectangle_area = actual_result * precision;

            integral += rectangle_area;
        }
    } else if (*min > *max) {
        for (float step = *min; (step >= *max); step -= precision) {
        
            float actual_result = sin_like_rad(&step);
            float rectangle_area = actual_result * precision;

            integral -= rectangle_area;
        }
    }

    return integral;
}