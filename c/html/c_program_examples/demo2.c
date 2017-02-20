#include<stdio.h>
#define VERY_SMALL 1e-6

int main(void)
{
    if((0.3 -(0.2+0.1)) < VERY_SMALL){
        printf("same.\n");
    }else{
        printf("not same.\n");
    }
    return 0;
}