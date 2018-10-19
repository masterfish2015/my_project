#include "stdio.h"
int main(void)
{	
	char c, alpha=0, digit=0, other=0;
	do{
		puts("input a charactor:");
		c = getchar();
		//while(getchar()!='\n');
		
		if ( c == 10 )
			break;
		else if (('a'<=c && c<='z') || ('A' <= c && c<='Z'))
			alpha++;
		else if( '0'<=c && c<='9')
			digit++;
		else
			other++;
		printf("alpha=%d, digit=%d, other=%d\n", alpha, digit, other);
	}while(1);
	return 0;
}