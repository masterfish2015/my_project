#include<stdio.h>

int main()
{
    int a=3, b=4, c=5,x,y;

    printf("%d\n", a+b>c && b==c);
    printf("a=%d,b=%d,c=%d\n", a,b,c);

    printf("%d\n", a||b+c&&b-c);
    printf("a=%d,b=%d,c=%d\n", a,b,c);

    a=3, b=4, c=5;
    printf("%d\n", !(x=a)&&(y=b)&&0);
    printf("x=%d,y=%d\n", x,y);

    printf("%d\n", !(a+b)+c-1&&b+c/2);
    printf("a=%d,b=%d,c=%d\n", a,b,c);


    printf("%d\n", (c>=2 && c<=6) || (c!=3) || (c!=5));
    printf("c=%d\n", c);

}
