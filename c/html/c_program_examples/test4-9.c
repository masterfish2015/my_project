#include<stdio.h>
#include<math.h>

int main()
{
    long int a, t;
    int i=0, d, d1, d2, d3, d4, d5;

input_data:
    printf("input a positive integer number < 100000 :");
    scanf("%d", &a);

    if(a<0 || a>=100000){
        printf("error input.\n");
        goto input_data;
    }

    int digit_number;
    digit_number = log10(a)+1;
    printf("%d\n", digit_number);

    d5 = a / 10000;
    d4 = (a - d5*10000)/1000;
    d3 = (a - d5*10000 - d4*1000)/100;
    d2 = (a - d5*10000 - d4*1000 - d3*100)/10;
    d1 = a % 10;

    switch(digit_number){
        case 5: printf("%d%d%d%d%d\n", d5,d4,d3,d2,d1);
                printf("%d%d%d%d%d\n", d1,d2,d3,d4,d5);
                break;
        case 4: printf("%d%d%d%d\n", d4,d3,d2,d1);
                printf("%d%d%d%d\n", d1,d2,d3,d4);
                break;
        case 3: printf("%d%d%d\n", d3,d2,d1);
                printf("%d%d%d\n", d1,d2,d3);
                break;
        case 2: printf("%d%d\n", d2,d1);
                printf("%d%d\n", d1,d2);
                break;
        case 1: printf("%d\n", d1);
                printf("%d\n", d1);
                break;
    }

    return 0;
}
