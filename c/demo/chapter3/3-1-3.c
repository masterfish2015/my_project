#include<stdio.h>
#include<limits.h>

int main()
{
    short a = SHRT_MAX+1;
    unsigned short b = USHRT_MAX+1;
    printf("max short = %d \n", SHRT_MAX);
    printf("max short + 1 = %d \n", a);
    printf("max unsigned short = %d\n", USHRT_MAX);
    printf("max unsigned short +1 = %d\n", b);
}