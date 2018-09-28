#include "stdio.h"
int main()
{
  float f, c; //定义变量
  printf("input f=");
  scanf("%f", &f);
  c = (f-32)*5/9;
  printf("f=%f\nc=%f\n",f,c);
  return 0;
}