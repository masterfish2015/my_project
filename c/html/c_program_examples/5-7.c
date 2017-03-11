#include <stdio.h>
#include <math.h>
#define MIN_TERM 1e-6

int main(void)
{
    double pi = 0.0, n = 1.0, term = 1.0;
    int sign = 1;

    while (fabs(term) >= MIN_TERM)
    {
        pi += term;
        n += 2;
        sign *= -1;
        term = sign / n;
    }
    pi = pi * 4;
    printf("pi=%.8lf\n", pi);
    return 0;
}