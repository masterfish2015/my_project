#include <stdio.h>

int main(void)
{
    unsigned int f1 = 1, f2 = 1, f3;
    printf("[%3d]%12u\n[%3d]%12u\n", 1,f1, 2,f2);
    for (int i = 3; i <= 40; i++)
    {
        f3 = f1 + f2;
        printf("[%3d]%12u\n", i, f3);
        f1 = f2;
        f2 = f3;
    }
    return 0;
}