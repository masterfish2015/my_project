#include "stdio.h"

int main()
{
  char c = 78, cc = c*c;
  printf("%d * %d = %d\n",c,c,cc);
  printf("%d / 10 = %d\n", c, c/10);
  printf("%d \% 10 = %d\n", c, c%10);
  return 0;
}