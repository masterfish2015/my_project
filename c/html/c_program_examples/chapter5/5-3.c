#include <stdio.h>

int main(void)
{
    int row, column; //行、列
    for (row = 1; row <= 9; row++)
    {
        for (column = 1; column <= 9; column++)
        {
            printf("%2d*%2d=%2d  ", row, column, row * column);
        }
        putchar('\n');
    }
    return 0;
}