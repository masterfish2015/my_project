#include<stdio.h>

int main()
{
    char *week[]={"Monday",
                  "Tuesday",
                  "Wednesday",
                  "Thirsday",
                  "Friday",
                  "Saturday",
                  "Sunday"};
    int choice = -1 ;

    printf("input a day:");
    scanf("%d", &choice);

    if(choice >=1 && choice <=7)
        printf("It is %s.\n", week[choice-1]);
    else
        printf("Out of range. The input number must between [1,7].\n");

}
