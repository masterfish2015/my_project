#include "stdio.h"

int main()
{ 
	char *alpha[7]={
		"ABCD","EFGH","IJKL",
		"MNOP","QRST","UVWX","YZ"};
	char **p;
	int i;
	p=alpha;
	for(i=0;i<4;i++)
		printf("%c",*(p[i]));
	printf("\n");
}

