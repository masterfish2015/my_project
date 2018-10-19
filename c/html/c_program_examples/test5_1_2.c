#include "stdio.h"
int main(void)
{	
	int x, y, z=1;
	for(x=1;x<4;x++){
		for(y=1;y<4;y++){
			if(y >x) continue;
			printf("%d", x*y);
		}
		printf(",");
	}
	return 0;
}