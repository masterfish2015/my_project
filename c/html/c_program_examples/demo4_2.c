#include "stdio.h"				
int main()
{	
	char s; int score;
	puts("input s(A,B,C,D,E):");
	s = getchar();
	switch(s){
		case 'A': case 'a': score = 90; break;
		case 'B': case 'b': score = 80; break;
		case 'C': case 'c': score = 70; break;
		case 'D': case 'd': score = 60; break;
		case 'E': case 'e': score = 50; break;
		default:
			puts("input error.\n");
			return -1;
	}
	printf("score = %d\n",score);
	return 0;
}