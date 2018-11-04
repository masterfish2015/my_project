#include "stdio.h"

int main()
{
	char alpha[7][30]={
		"ABCD","EFGH","IJKL",
		"MNOP","QRST","UVWX","YZ"};
	int i;
	for(i=0;i<4;i++)
		printf("%c",alpha[i][i]);
	printf("\n");

	return 0;
}
	