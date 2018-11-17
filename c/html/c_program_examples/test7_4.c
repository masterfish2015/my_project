#include"stdio.h"
#define N 5
void fun(int a[],int n)
{   int k, tmp;
    for (k=0; k<n/2; k++)
    {   tmp=a[k];  
		a[k]=a[n-k-1];  
		a[n-k-1]=tmp;
	}
}
int main()
{  int x[N]={1,3,4,2,5},i;
   fun(x,N);
   for(i=0;i<N;i++)
     printf("%d  ",x[i]);
   return 0; 
}



