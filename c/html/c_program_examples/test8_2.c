#include "stdio.h"
int main()
{	int a[]={1,2,3,4,5,6,7,8,9,10,11,12}, *p=a;
	p=a; 
	p+=2; printf("%d",*(p++));putchar('\n');
	p=a;
	p+=2; printf("%d",*++p);putchar('\n');
	p=a;
	p+=2; printf("%d",++(*p));putchar('\n');
	p=a;
	p+=2; printf("%d",++*p);putchar('\n');
	return 0;
}