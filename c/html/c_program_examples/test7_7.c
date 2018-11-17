#include"stdio.h"
#include"string.h"
#define N 5
void sort( char str[][100], int n)
{  int i,j,t;
   char tmp[100];
   for(i=n-1;i>0;i--)
   {
     t=0;
     for(j=0; j<=i; j++)
        if(strcmp(str[t], str[j])<0)
          t=j;
     if(t!=i)
     {
        strcpy(tmp,str[t]);
		strcpy(str[t], str[i]);
		strcpy(str[i],tmp);
	 }
	}
}
void main()
{
  int i;
  char words[N][100]={"orange","apple","banana","watermelon","grape"};
  printf("排序后的结果为:\n");
  sort(words, N);
  for(i=0;i<N;i++)
	printf("%s\n", words[i]);
}





