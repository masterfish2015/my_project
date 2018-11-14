#include"stdio.h"
void strcat1(char dest[], char source[])//字符串连接
{	int i=0, j=0;
	while(dest[i]!=0)
		i++;
	while(source[j]!=0)
		dest[i++]=source[j++];
}
int main()
{
	char s1[100]="hello ", s2[100]="world!";
	strcat1(s1,s2);
	printf("%s\n", s1);
	return 0;
}