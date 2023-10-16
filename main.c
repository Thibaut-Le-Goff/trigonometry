#include <stdio.h>
#include "basic_fun.h"

int main() {
    float number1 = 1.0;
    float factor = factorial_like(number1);

    float number2 = -7.0;
    float number3 = 5.0;
    float power = pow_like(number2, number3);

    float number4 = -777.0;
    float sin = sin_like_rad(number4);

    printf("factorial of %f : %f \n", number1, factor);
    printf("%f power of %f : %f \n", number2, number3, power);
    printf("sin of %f : %f \n", number4, sin);

    return 0;
}