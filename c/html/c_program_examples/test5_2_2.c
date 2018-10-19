#include "stdio.h"
int main(void)
{	
	int m, n, gcd, r;
	puts("input 2 integer: ");
	scanf("%d,%d", &m, &n);
	if ( m < n ) {
		int t = m;
		m = n;
		n = t;
	}
	do{
		r = m % n;
		if ( r == 0 ) {
			printf("gcd=%d\n",n);
			break;
		}
		m = n; n = r;
	}while(1);
	return 0;
}