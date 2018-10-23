#include "stdio.h"
#define show_data(d, n) for(int t=0;t<n;t++) \
							printf("%4d",d[t]); \
						putchar('\n');
int main()
{
	int data[] = {7,2,3,5,11,6,8,4,9};
	int n = sizeof(data)/sizeof(int);
	int i,j,flag=1;
	show_data(data, n);
	
	for(i=n-1;i>0 && flag!=0;i--){
		flag = 0;
		for(j=0;j<i;j++){
			if(data[j]>data[j+1]){
				int t=data[j];
				data[j]=data[j+1];
				data[j+1]=t;
				flag=1;
			}
		}
		show_data(data, n);
	}
	show_data(data, n);
	return 0;
}