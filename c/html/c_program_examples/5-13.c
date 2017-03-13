#include<stdio.h>
#include<math.h>
#define MIN_VALUE 1e-6

int main(void)
{
    double x, last_x, f, df;
    int i=0;
    x=1.0;
    do{
        last_x = x;
        f=2*x*x*x-4*x*x+3*x-6;
        df=6*x*x-8*x+3;
        x=x-f/df;
        printf("[%3d]x=%10g, dx=%15g\n", i++, x, fabs(x-last_x));
    }while(fabs(x-last_x)>MIN_VALUE);
    return 0;
}