#include <stdio.h>
#include <math.h>

int height_permutation(void);
int circum_ference(void);
int food_expance(void);


int main(void)
{
    printf("*************************\n"
                   "      Let's study C/C++ programming!!!\n"
    "*********************\n\n");


    double pi = 3.1438282;
    int num = 10;
    printf("pi= \t%0.2f \n",  pi);
    printf("num=\t%05d\n", num);

    scanf("%d %lf", &num, &pi); // %d: signed integer, %f: float, %lf: double type.

    // how to use printf with variables.
    printf("pi= \t%0.2f \n",  pi);      // show limited ciphers of float number 0.2 > 2 ciphers
    printf("num=\t%05d \n", num);       // match as given ciphers decimal number with '0's

    height_permutation();
    circum_ference();
    food_expance();

    return 0;
}

/*
 * practice problems
 */

int height_permutation(void)
{
    printf("input your height with \'cm\'\n");
    int height;
    scanf("%d", &height);
    printf("your height is %dm %dcm\n", height/100, height%100);
    return 0;
}

int circum_ference(void)
{
    printf("input radius\n");
    double radius;
    scanf("%lf", &radius);
    printf("circumference = %0.2lf\n", M_PI * radius);
    return 0;
}

int food_expance(void)
{
    int food_fee = 3000;
    int year = 365;
    int age;
    printf("input your current age\n");
    scanf("%d", &age);
    printf("your food expance for whole life is %d", age * food_fee * year);
    return 0;
}