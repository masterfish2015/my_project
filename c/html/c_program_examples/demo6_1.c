#include "stdio.h"

int main()
{
	int n,d1[5]={1,6,2};
	scanf("%d",&n);
	double d2[n];
	for(int i=0;i<n;i++){
		d2[i] = i;
		printf("%.2lf\n", d[i]);
	}
	printf("%lu,%lu\n", sizeof(d), sizeof(d[0]));
	return 0;
}