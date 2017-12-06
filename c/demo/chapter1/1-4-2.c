#include<stdio.h>
#define THIS_YEAR 2017

int main()
{
    int birth_year=0, age=0;
    printf("input the birth year:");
    scanf("%d", &birth_year);

    age = THIS_YEAR - birth_year;
    printf("your age is %d\n", age);

}
