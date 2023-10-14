#include <stdio.h>
#include "basic_fun.h"

int main() {
    float number1 = 8.0;
    float factor = factorial_like(number1);

    float number2 = 7.0;
    float number3 = 4.0;
    float power = pow_like(number2, number3);

    //float sin = sin_like(number3);

    printf("factorial of %f : %f \n", number1, factor);
    printf("%f power of %f : %f \n", number2, number3, power);

    return 0;
}