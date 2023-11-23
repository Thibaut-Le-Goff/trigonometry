#include <stdlib.h>
#include "basic_fun.h"
/**/
float integral(float *min, float *max, float *precision) {
    float periode = *max - *min;
    printf("periode : %f \n", periode);

    float previous_result = 0.0;
    float integral = 0.0;

    printf("stepp == : %f \n", (periode / *precision));

    for (float step = 0.0; (step <= (periode / *precision)); step += *precision) {
        float index_in_periode = *precision * step;
        //printf("index_in_periode : %f \n", index_in_periode);

        float actual_result = sin_like_rad(&index_in_periode);

        float square_area = actual_result * *precision;

        // we can't calculate the triangle area at the first iteration because
        // we don't know previous_result. But, we have to keep in the for
        // loop the calculation of the triangle area, for the others iterations
        float triangle_area = ((abs(actual_result - previous_result) * *precision) / 2);

        // here a formula that gives 0 at the first iteration 
        // but gives 1 at the others.
        float zero = 0.0;
        float two = 2.0;

        float validator = pow_like(&zero, &step) - 1;
        float triangle_validation_number = pow_like(&validator, &two);

        // this number is use to "validate" every iteration but the first
        // with a multiplication.
        float triangle_validation = triangle_area * triangle_validation_number;

        integral += square_area + triangle_validation;
        //printf("integral : %f \n", integral);

        previous_result = actual_result;
    }

    return integral;
}
