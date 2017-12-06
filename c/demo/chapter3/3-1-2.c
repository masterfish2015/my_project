#include<limits.h>
#include<stdio.h>

int main()
{
    printf("/*--------------- char ---------------*/\n");
    printf("signed char min = %d \n", SCHAR_MIN);
    printf("signed char max = %d \n", SCHAR_MAX);
    printf("unsigned char min = %d \n", 0);
    printf("unsigned char max = %d \n", UCHAR_MAX);
    printf("char min = %d \n", CHAR_MIN);
    printf("char max = %d \n", CHAR_MAX);
    printf("size of char = %lu \n", sizeof(char));

    printf("/*--------------- short ---------------*/\n");
    printf("signed short min = %d \n", SHRT_MIN);
    printf("signed short max = %d \n", SHRT_MAX);
    printf("unsigned short min = %d \n", 0);
    printf("unsigned short max = %d \n", USHRT_MAX);
    printf("size of short = %lu \n", sizeof(short));

    printf("/*--------------- int ---------------*/\n");
    printf("signed int min = %d \n", INT_MIN);
    printf("signed int max = %d \n", INT_MAX);
    printf("unsigned int min = %d \n", 0);
    printf("unsigned int max = %u \n", UINT_MAX);
    printf("size of int = %lu \n", sizeof(int));

    printf("/*--------------- long ---------------*/\n");
    printf("signed long min = %ld \n", LONG_MIN);
    printf("signed long max = %ld \n", LONG_MAX);
    printf("unsigned long min = %d \n", 0);
    printf("unsigned long max = %lu \n", ULONG_MAX);
    printf("size of long = %lu \n", sizeof(long));

    printf("/*--------------- long long ---------------*/\n");
    printf("signed long long min = %lld \n", LLONG_MIN);
    printf("signed long long max = %lld \n", LLONG_MAX);
    printf("unsigned long long min = %d \n", 0);
    printf("unsigned long long max = %llu \n", ULLONG_MAX);
    printf("size of long long = %lu \n", sizeof(long long));

    printf("/*--------------- float ---------------*/\n");
    printf("size of long long = %lu \n", sizeof(float));
}