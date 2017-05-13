#include<stdio.h>
#include<math.h>

int main()
{
    printf( "the integral of normal(0,1) distribution "
            "between -1.96 and 1.96 is: %g\n", erf(1.96*sqrt(1.0/2.0)));
    return 0;
}