#include "stdio.h"

int main()
{
  signed char a = 65;
  int b = -32;
  float c = 3.14;
  double d = 6.18;
  printf("size of char = %lu \n", sizeof(a));
  printf("size of int = %lu \n", sizeof(b));
  printf("size of float = %lu \n", sizeof(c));
  printf("size of double = %lu \n", sizeof(d));

  a = a*a*a;
  printf("a*a*a = %d\n", a);
  return 0;
}