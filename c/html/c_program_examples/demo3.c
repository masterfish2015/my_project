#include<stdio.h>

int main(void)
{
    int a=3;
    char b='%';  //ASCII码为 37
    float c=3.14f;
    double d=0.11e-1;
    double e;
    printf("%d\n", a/5); //显示：0              
    printf("%f\n", a/5.0); //显示：0.600000
    printf("%f\n", 1.*a/5); //显示：0.600000
    e = a/b;
    printf("%f\n", e); //显示：0
    printf("%f\n", a/c); //显示：0.955414
    printf("%f\n", d+a/b);

    int t=40;
    printf("%d\n", t);
    return 0;
}