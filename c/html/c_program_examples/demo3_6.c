#include "stdio.h"
int main()
{
	char a = 'A'; 
  printf("%c -> %c\n", a, a+32); //大写字母转为小写
  
  double f = 64.0, c;
  printf("c = %lf\n", (double)5/9*(f-32)); //输出 c = 0.000000
  printf("c = %lf\n", (f-32)*5/9); //输出 c = 17.777778
  return 0;
}