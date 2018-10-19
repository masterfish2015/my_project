#include "stdio.h"
#include "math.h"
int main()
{
	int n=100, i;
	do{
		i=2; 
		do{
			int r = n % i;
			if(r==0)
				break;
			else
				i++;
		}while(i<=sqrt(n));
		if(i>sqrt(n))
			printf("%10d\n",n); 
		n++;
	}while(n<=200);
	return 0; 
}