#include<stdio.h>
int main(void)
{
    int daffodil;
    for(daffodil=100; daffodil<1000; daffodil++){
        int d1, d2, d3;
        d1 = daffodil / 100; 
        d2 = daffodil % 100 / 10;
        d3 = daffodil % 10;
        if( d1*d1*d1 + d2*d2*d2 + d3*d3*d3 == daffodil){
            printf("%d\n", daffodil);
        }
    }
    return 0;
}