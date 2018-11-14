#include"stdio.h"

void perm(int list[], int min_index, int count)
{
	if(min_index==count-1){
		putchar('{'); 
        for(int i=0; i<count;i++)
            printf("%d ", list[i]);
        putchar('}');
    }else{
       for(int i=min_index; i<count; i++){
          int t;
		  if(i!=min_index){
			t=list[min_index];
			list[min_index]=list[i];
			list[i]=t;
		  }
          perm(list, min_index+1, count);
          if(i!=min_index){
			t=list[min_index];
			list[min_index]=list[i];
			list[i]=t;
		  }
       }
    }
}
void main()
{   int list[]={3,4,5,6,7};
    perm(list, 0, 5);
}




