#include"stdio.h"
int func(int n)
{   if(n<1)
		return 1;
    else
		return n+=func(n-2);
}
int main()
{   int x=5;
    printf("%d",func(x));
	return 0;
}




