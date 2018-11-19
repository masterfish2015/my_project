//把一组字符串中的数字转换并加起来
#include "stdio.h"
#include "stdlib.h"
int  add(char **d, int n)
{
	int result=0, tmp;
	for(int i=0;i<n;i++){
		tmp=atoi(d[i]);
		printf("\"%s\" --> %d\n", d[i], tmp);
		result+=tmp;
	}
	return result;
}
int main(int n, char **argstrings)
{
	printf("result=%d\n", add(argstrings, n));
	return 0;
}





