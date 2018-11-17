#include"stdio.h"
int gcd(int a, int b)//求最大公约数
{	int t;
	if(a<b){
		t=a;a=b;b=t;}
	do{
		t=a%b;
		if(t==0)break;
		a=b; b=t;
	}while(1);
	return b;
}
int main()
{	int a=28, b=32;
	printf("gcd of %d,%d = %d\n", a, b, gcd(a,b));
	return 0;
}