#include<stdio.h>
#include<math.h>
#define DELTA 1e-6

int main(void)
{
    double x, last_x, f, df;
    int i=1;

    x=1.0;
    do{
        last_x = x;
        f  = 2*x*x*x - 4*x*x + 3*x -6;
        df = 6*x*x   - 8*x   + 3;
        x  = x - f/df ;
        printf("[%3d]x=%10g, |x_new-x_old|=%15g\n", i++, x, fabs(last_x-x));
    }while(fabs(last_x-x)>DELTA);
    return 0;
}