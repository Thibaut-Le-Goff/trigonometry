#include <stdio.h>
#include "basic_fun.h"

int main() {
    float number0 = 5.0;
    float number1 = 0.0;
    float factor1 = factorial_like(number0);
    float factor2 = factorial_like(number1);

    float number2 = -1.0;
    float number3 = 5.0;
    float power1 = pow_like(number2, number3);
    float power2 = pow_like(number3, number2);

    float number4 = 6.283185;
    //float number4 = 360.0;
    
    float sin_rad = sin_like_rad(number4);
    float sin_deg = sin_like_deg(number4);

    float cos_rad = cos_like_rad(number4);
    float cos_deg = cos_like_deg(number4);

    printf("\nfactorial of %f : %f \n", number0, factor1);
    printf("factorial of %f : %f \n\n", number1, factor2);
    
    printf("%f power of %f : %f \n", number2, number3, power1);
    printf("%f power of %f : %f \n\n", number3, number2, power2);
    
    printf("sin of %f rad : %f \n", number4, sin_rad);
    printf("sin of %f deg : %f \n\n", number4, sin_deg);

    printf("cos of %f rad : %f \n", number4, cos_rad);
    printf("cos of %f deg : %f \n", number4, cos_deg);

    return 0;
}