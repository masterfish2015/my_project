#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE !FALSE

int main(void)
{
    int i, j, is_prime;
    for (i = 2; i <= 10; i++)
    {
        is_prime = TRUE;
        for (j = 2; j < sqrt(i)+1 && TRUE == is_prime; j++)
            if (i % j == 0)
                is_prime = FALSE;
        if (TRUE == is_prime)
            printf("%d is prime number.\n", i);
    }
    return 0;
}