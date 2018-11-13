//例：数组的元素通过传值作为函数的参数
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int max(int x, int y);
	void printd(int data[], int n);
	
	int a[10], m, n, i;
	
	for(i=0;i<10;i++)
		a[i]=rand() % 100;
	for(i=1, m=a[0],n=0;i<10;i++){
		if(max(m, a[i])>m){
			m = max(m, a[i]);
			n=i;
		}
	}
	printd(a, 10);
	printf("max = %d, number=%d\n", m, n+1);
	return 0;
}

int max(int x, int y){
	return (x>y)?x:y;
}

void printd(int data[], int n){
	for(int i=0;i<n;i++){
		printf("%6d", data[i]);
	}
	putchar('\n');
}