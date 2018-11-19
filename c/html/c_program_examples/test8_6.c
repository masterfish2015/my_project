#include "stdio.h"
int main()
{
	char p[3][20]={"I", "Love", "China!"};
	printf("%c\n", p[2][2]);
	printf("%c\n", (*p+1)[1]);
	printf("%c\n", *(*(p+1)+2));
	printf("%c\n", *(*(p+1)+1));
	return 0;
}


