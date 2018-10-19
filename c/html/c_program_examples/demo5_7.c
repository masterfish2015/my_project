#include "stdio.h"
#include "math.h"
#define DELTA 1e-6
#define F(x) 2*pow((x),3)-4*(x)*(x)+3*(x)-6
int main()
{
	double x0,x1=-10,x2=10,f0,f1,f2;
	int i=0;
	printf("%4s%13s%13s%13s%13s%13s%13s\n",
		"No."," x1 "," f(x1) "," x0 "," f(x0) ",
		" x2 "," f(x2) ");
	do{
		x0 = (x1+x2)/2;
		f0 = F(x0);	f1 = F(x1);	f2 = F(x2);
		printf(
		"%4d%13.6lf%13.6lf%13.6lf%13.6lf%13.6lf%13.6lf\n",
			++i,x1,f1,x0,f0,x2,f2);
		if(f1*f0>=0) x1=x0; else x2=x0;
	}while((x2-x1)>DELTA);
	printf("[%d] root = %lf\n", i, x0);
	return 0;
}