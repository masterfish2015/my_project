#include "stdio.h"
int sqr(int n) //函数的定义
{
	n = n*n;
	return n;
}
int main()
{
	int n=3, x=5;
	printf("%d, %d\n", sqr(x), x);
	printf("%d, %d\n", sqr(n), n);
	return 0;
}