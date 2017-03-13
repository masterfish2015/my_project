#include <stdio.h>
#include <math.h>
int main(void)
{
    double x = 0, y;

    do
    {
        printf("input a positive number:");
        scanf("%lf", &x);
    } while (x < 0);

    y = sqrt(x);
    printf("sqrt(%.2lf)=%.2lf\n", x, y);

    return 0;
}