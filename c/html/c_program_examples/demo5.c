#include<stdio.h>

int main(void)
{    
    printf("%+d\n", 3);
    printf("%-4d, %4d\n", 3, 3);
    printf("%04d\n", 3);
    printf("%#x, %x\n", 30, 30);
    printf("%#o, %o\n", 30, 30);
    printf("%#g, %g\n", 3.14, 3.14);
    printf("%5d, %10f\n", 3, 3.14);
    printf("%-5s, %-5d\n","abc", 123);
    printf("%*d\n", 5, 3);
    printf("%05d, %05d\n", 3, -3);
    printf("%7.2f, %7.5f\n", 3.1416, 3.1416);
    printf("%.2g, %.9g\n", 3.1416, 3.1416);
    printf("%5.2d, %5.2d\n", 3, 1234);
    printf("%*.*d\n", 5, 3, 3);
    printf("%5.2s, %5.4s\n", "abc", "ab");
    printf("%e\n", 123.456);
    printf("%13.2e\n", 123.456);
    printf("%g\n", 123.456);
    printf("%g\n", 0.0000123456789);
    return 0;
}