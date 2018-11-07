#include "stdio.h"
#define MAX_N 15

int main()
{
	int magic[MAX_N][MAX_N]={0}, 
		row, col, old_row, old_col, 
		i=1, n;
	
	do{
		printf("input n (0<=n<=%d):", MAX_N);
		scanf("%d",&n);
	}while(n<=0 || n>MAX_N);
	n--;
	row = n; col = n/2; 
	magic[row][col]=i;
	
	while(i<(n+1)*(n+1)){
		old_row=row; old_col=col;
		row = (row+1>n)?0:row+1;
		col = (col+1>n)?0:col+1;
		if(magic[row][col]==0){
			magic[row][col]=++i;
		}
		else{
			row = (old_row-1<0)?0:(old_row-1);
			col = old_col;
			magic[row][col]=++i;
		}
	}
	for(row=0;row<=n;row++){
		int s=0;
		for(col=0;col<=n;col++){
			printf("%6d",magic[row][col]);
			s+=magic[row][col];
		}
		printf("\t|%d\n", s);
	}
	printf("-----------------------\n");
	for(col=0;col<=n;col++){
		int s=0;
		for(row=0;row<=n;row++){
			s+=magic[row][col];
		}
		printf("%6d",s);
	}putchar('\n');
	return 0;
}