#include<stdio.h>
#define FALSE 0
#define TRUE  !FALSE

int is_even(int);

int main()
{
    int n , i;
    do{
        printf("input n(n>0):");
        scanf("%d", &n);
    }while(n<=0);

    for(i=1; i<=n; i++){
        if(is_even(i)==TRUE)
            printf("%d is even.\n", i);
    }
}

int is_even(int value)
{
    if(value % 2 == 0)
        return TRUE;
    else
        return FALSE;
}
