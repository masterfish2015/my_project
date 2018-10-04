#include "stdio.h"

int main()
{
  float a=3.14;
  double b=0.00123456789;
  printf("0123456789\t0123456789\t0123456789\n");
  printf("%f\t%10.2f\t%-10.2f\n",a,a,a);
  printf("%le\t%10.2le\t%.2le\n",b,b,b);
  return 0;
}