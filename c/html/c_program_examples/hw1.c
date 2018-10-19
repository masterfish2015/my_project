#include <stdio.h>

#define PI 3.14

int main( )
{
double r,h,l,s,s1,v,v2;
scanf( "%f%f",&r,&h) ;
l=2*PI*r ;
s=r*r*PI ;
s1=4*PI*r*r;
v=PI*r*r*r*4/3;
v2=PI*r*r*h;

printf("園周長内=%.2f\n",l);
printf("園面釈内=%.2f\n",s);
printf ( "圓球面枳内=%.2f\n",s1 );
printf( "圓球体釈勺=%.2fn",v);
printf( "圓柱体枳内=%.2f\n",v2);
return 0;
}
