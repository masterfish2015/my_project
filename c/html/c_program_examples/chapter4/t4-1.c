#include<stdio.h>

int main(void)
{
    int i=0;
repeat_it:

    switch (i)
    {
        case 1: printf("%d ", i);
        case 2: printf("%d ", i);
        default : printf("%d ", i);
    }
    i++;
    if( i <3 )goto repeat_it;

    return 0;
}
