#include<stdio.h>
int main(void)
{
    int a, b;
    float x, y;
    char c1, c2;
    scanf("a=%db=%d",&a,&b);
    scanf("%f%e",&x,&y);
    scanf("%c%c",&c1,&c2);
    printf("a=%d,b=%d,x=%g,y=%g,c1=%c,c2=%c\n", a,b,x,y,c1,c2);
    return 0;
}
