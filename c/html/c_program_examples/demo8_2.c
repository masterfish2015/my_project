#include "stdio.h"
void print_array(int **d, int n)
{
	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
		{
			if(j<=i)
				printf("%4d",d[i][j]);
		}putchar('\n');
	}
}
int main()
{
	int a[]={1}, b[]={1,2}, c[]={1,2,3};
	int *tri[3]={a,b,c};
	print_array(tri, 3);
	return 0;
}





