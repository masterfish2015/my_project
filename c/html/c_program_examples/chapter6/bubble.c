#include<stdio.h>
#define PRINT_INT_ARRAY(array, n, p1, p2) \
      for(int i=0;i<n;i++)\
         if(i==p1 || i==p2)\
             printf("[%4d]",array[i]); \
         else\
             printf("%6d",array[i]); \
      putchar('\n');

int main(void)
{
    int data[]={7,12,89,5,33,67,21,46,58}, i;
    int count = sizeof(data)/sizeof(int);

    //显示原来顺序的数组
    printf("[0]\n");
    PRINT_INT_ARRAY(data,count,-1,-1);

    //开始冒泡排序
    for(int i=count; i>1; i--){
        int is_switch=0; //是否进行交换，0为未交换
        printf("[%d]\n", count-i+1);
        for(int j=0; j<i-1; j++){
            if(data[j]>data[j+1]){
                int t = data[j];
                data[j]=data[j+1];
                data[j+1]=t;
                is_switch=1; //进行了交换
                PRINT_INT_ARRAY(data,count,j,j+1);
            }            
        }
        //如果未进行交换，则已经排好序，结束排序
        if( 0==is_switch) 
            break;
    }

    //显示排好序的数组
    PRINT_INT_ARRAY(data,count,-1,-1);

    return 0;
}
