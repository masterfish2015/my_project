#include "stdio.h"
#include "math.h"
#define DELTA 1e-6
int main()
{
	double	data_x[]={1.0, 1.1, 1.2, 1.3, 1.4, 
		1.50, 1.6, 1.7, 1.8, 1.9, 2.0},
			data_y[]={0, 0.0414, 0.0792, 0.1139, 
		0.1461, 0.1761, 0.2041, 0.2304, 
		0.2553, 0.2788, 0.3010};
	double x;
	int i, flag = 0, 
		n=sizeof(data_x)/sizeof(double);
	puts("input x:"); scanf("%lf", &x);
	for(i=0; i<n && flag==0; ){
		if( fabs(data_x[i] - x) < DELTA)
			flag = 1;
		else
			i++;
	}
	if(flag == 1)
		printf("%i, log(%.2lf)=%.4lf\n", i, 
			data_x[i], data_y[i]);
	else
		printf("not found.\n");
	return 0;
}