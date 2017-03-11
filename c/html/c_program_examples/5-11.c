#include<stdio.h>
int main(void)
{
    double s=100, r=50 ;
    printf("[%2d]s=%10g, r=%10g\n",1,s,r);
    for(int i=2; i<=10; i++){
        s=s+r*2; r=r/2;
        printf("[%2d]s=%10g, r=%10g\n",i,s,r);
    }
    return 0;
}