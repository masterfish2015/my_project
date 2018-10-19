#include "stdio.h"
int main()
{
	int row, col;
	for(row=1; row<10; row++){
		for(col=1; col<10; col++)
			printf("%4d", row*col);
		putchar('\n');
	}
	return 0;
}