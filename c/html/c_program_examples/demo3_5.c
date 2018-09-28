#include "stdio.h"
int main()
{
	int a = 3, b = 3;
	printf("a++ = %d, a = %d\n", a++ + ++b, a);
	printf("++b = %d, b = %d\n", ++b, b);
  return 0;
}