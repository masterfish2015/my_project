#include <stdio.h>
int main(void)
{
    int m, n;

    printf("input two positive integer number:");
    scanf("%d,%d", &m, &n);

    /*判断两个数的大小，通过交换确保 m < n */
    if(m>n){
        int t=m; m=n; n=t;
    }
    /*求最大公约数, 从比较小的数m开始往下查找, 最小是1*/
    for(int i=m; i>=1; i--){
        if( m % i ==0 && n % i == 0){
            printf("the greatest common divisor of %d and %d is %d\n", m, n, i);
            break;
        }
    }
    /*求最小公倍数，从比较大的数n开始往上查找，最大是m*n */
    for(int i=n; i<=m*n; i++){
        if( i % m ==0 && i % n == 0){
            printf("the least common multiple of %d and %d is %d\n", m, n, i);
            break;
        }
    }

    return 0;
}