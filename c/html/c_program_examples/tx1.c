#include<stdio.h>
int main()
{ 
	char str1[80],str2[80];
	int i=0,j=0,a=0,b=0;
	gets(str1);
	gets(str2);
	for(i=0;str1[i]!='\0';i++)
	{
		for(j=0;str2[j]!='\0';j++);
			printf("%d",str1[i]-str2[j]);
		printf("\n");
	}
	return 0;
}