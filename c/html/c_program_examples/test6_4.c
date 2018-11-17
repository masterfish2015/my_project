#include "stdio.h"

void print_data(double d[], int n);
void sort_bubble(double d[], int n);

int main()
{
	double d[]={7.5, 6.2, 3.18, 9.6, 12.4, 
		9.3, 10.8, 13.4, 90.6, 7.33};
	int n = sizeof(d)/sizeof(d[0]);
	print_data(d, n);
	sort_bubble(d, n);
	print_data(d, n);
	return 0;
}

void print_data(double d[], int n)
{
	for(int i=0;i<n; i++){
		int c=(i==n-1)?'\n':',';
		printf("%.2lf%c",d[i], c);
	}
}

void sort_bubble(double d[], int n)
{
	int row, col, flag=1;
	for(row=n-1;row>0 && flag==1; row--){
		flag=0;
		for(col=0;col<row;col++){
			if(d[col]>d[col+1]){
				double t=d[col];
				d[col]=d[col+1];
				d[col+1]=t;
				flag=1;
			}
		}
	}
}