#include "stdio.h"
#include "stdlib.h"
#define NOT_FIND -1
int search_string(char *old, char *find)
{	int i, j, flag;
	for(i=0; *(old+i)!='\0'; i++){
		if(*(old+i)==*find){
			flag=0;
			for(j=0; *(find+j)!='\0'; j++){
				if(*(old+i+j)!=*(find+j)){
					flag=1; break;
				}
			}
			if(flag==0)return i;
		}
	}
	return NOT_FIND;
}
void main(int n, char *p[])
{	if(n!=3){
		printf("usage: find old new\n");exit(-1);
	}
	printf("origin string=%s, sub string=%s\n", p[1],p[2]);
	printf("the position = %d\n", search_string(p[1],p[2]));
}
