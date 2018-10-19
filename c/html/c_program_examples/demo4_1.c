#include "stdio.h"
#include "math.h"
#define DELTA 1e-10
int main()
{	
	double a,b,c,d, x1, x2;
	puts("input a,b,c:");
	scanf("%lf,%lf,%lf", &a,&b,&c);
	d = b*b-4*a*c;
	if ( d >= 0){
		if (fabs(d) < DELTA) {
			x1 = x2 = -b/(2*a);
			printf("x1=x2=%.2lf\n", x1);
		}
		else{
			double dd = sqrt(d);
			x1 = (-b+dd)/(2*a);
			x2 = (-b-dd)/(2*a);
			printf("x1=%.2lf,x2=%.2lf\n",x1,x2);
		}
	}
	else
		puts("there is no REAL roots.\n");
	
	return 0;
}