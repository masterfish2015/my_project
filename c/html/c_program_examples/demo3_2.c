#include "stdio.h"
int a = 4;
int main()
{
  int b = 3;
  printf("a = %d, b = %d\n", a, b); //输出 a=4, b=3
  {
    int a = 5;
    printf("a = %d, b = %d\n", a, b); //输出 a=5, b=3
  }
  printf("a = %d, b = %d\n", a, b); //输出 a=4, b=3
  return 0;
}