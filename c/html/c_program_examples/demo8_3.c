//把一组字符串中的数字转换并加起来
#include "stdio.h"
#include "stdlib.h"
int  add(char **d, int n)
{
	int result=0, tmp;
	for(int i=0;i<n;i++){
		tmp=atoi(d[i]);
		result+=tmp;
	}
	return result;
}
int main()
{
	char *values[]={"15","27","38"};
	int n=sizeof(values)/sizeof(char *);
	printf("result=%d\n", add(values, n));
	return 0;
}





