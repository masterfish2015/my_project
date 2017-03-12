#include <stdio.h>
int main(void)
{
    int i;
    for (i = 100; i <= 200; i++)
    {
        if (i % 3 == 0)
            continue;
        printf("%d ", i);
    }
    putchar('\n');
    return 0;
}