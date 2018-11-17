#include"stdio.h"
#include"math.h"
#define delta 1e-6
double f(double x)
{
	return 3*x*x*x-2*x-4;
}
double df(double x)
{
	return 9*x*x-2;
}
double newton(double x0)
{
	double x=x0, oldx;
	do{
		oldx=x;
		x=x-f(x)/df(x);
	}while(fabs(x-oldx)>delta);
	return x;
}
void main()
{
  double x=1;
  printf("root = %lf\n", newton(x));
}





