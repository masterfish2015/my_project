#include "stdio.h"
#include "math.h"
int main()
{
	int n=100, i, flag;
	do{
		i=2; flag = 0;
		do{
			int r = n % i;
			if(r==0)
				flag=1;
			else
				i++;
		}while(flag==0 && i<=sqrt(n));
		if(flag==0)
			printf("%10d\n",n); 
		n++;
	}while(n<=200);
	return 0; 
}