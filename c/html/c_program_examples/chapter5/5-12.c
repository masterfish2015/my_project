#include<stdio.h>
#include<math.h>
#define MIN_VALUE 10e-5

int main(void)
{
    double x, last_x, a;

    printf("input a real number:");
    scanf("%lf", &a);
    
    x=1; 
    do{
        last_x = x;
        x = 1.0/2.0*(x+a/x);
    }while(fabs(x-last_x)>MIN_VALUE);

    printf("sqrt(%lg) = %lg\n", a, x);
    return 0;
}