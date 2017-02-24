#include<stdio.h>

const double PI = 3.14159;

int main(void)
{
    double r=1.5, h=3.0;
    double circumference_circle, area_circle,
    area_sphere, volume_sphere, volume_cylinder;

    circumference_circle = 2*PI*r;
    area_circle=PI*r*r;
    area_sphere=4.0*PI*r*r;
    volume_sphere=3.0/4.0*PI*r*r*r;
    volume_cylinder=PI*r*r*h;

    printf("circumference of circle is:%.2f\n", circumference_circle);
    printf("area of circle is:%.2f\n", area_circle);
    printf("area of sphere is:%.2f\n", area_sphere);
    printf("volume of sphere is:%.2f\n", volume_sphere);
    printf("volume of cylinder is:%.2f\n", volume_cylinder);

    return 0;
}
