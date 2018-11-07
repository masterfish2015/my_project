#include "stdio.h"

void hanoi(int n, char source, char help, char dest);
int main()
{
	int n ; //盘子的数目
	printf("input n:"); scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
	
void hanoi(int n, char source, char help, char dest)
{
	if( n ==1 )
		printf("move %c --> %c\n", source, dest);
	else{
		hanoi(n-1, source, dest, help);
		printf("move %c --> %c\n", source, dest);
		hanoi(n-1, help, source, dest);
	}
}