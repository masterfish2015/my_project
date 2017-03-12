#include<stdio.h>
int main(void)
{
    int i;
    int f[20]={1,1};

    for(i=2; i<20; i++)
        f[i]=f[i-2]+f[i-1];
    
    for(i=0; i<20; i++){        
        printf("%12d", f[i]);
        if((i+1)%5==0)
            putchar('\n');
    }
    
    return 0;
}
