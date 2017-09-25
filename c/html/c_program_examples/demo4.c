#include<stdio.h>
int main(void)
{
  float a, b;
  double c = 123.456789e100, d=3.4e-4;
  a=c; b=d;
  printf("%f\n", a);  //输出 : inf
  printf("%f\n", b);  //输出 : 0.000340
  return 0;
}
