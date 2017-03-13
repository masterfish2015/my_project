#include <stdio.h>
#include <math.h>
int main(void)
{
    double value;
    do
    {
        printf("input a number, negative to quit:");
        scanf("%lf", &value);
        if (value < 0)
            break;
        printf("the sqrt(%.2lf)=%.2lf\n", value, sqrt(value));
    } while (1);
    return 0;
}