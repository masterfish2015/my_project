#include "stdio.h"
int main(void)
{	
	int rabbits, chicken;
	for(rabbits=0; rabbits<=35; rabbits++){
		chicken = 35 - rabbits;
		if( 94 == rabbits*4+chicken*2 ){
			printf("rabbits=%d, chicken=%d\n", rabbits, chicken);
		}
	}
	return 0;
}