#include <stdio.h>
#include <stdlib.h>
#include "linker.h"

int main()
{
	Linker linker={NULL} ;
	if (create_linker(&linker)!=ex_ok){
		printf("创建链表错误，退出。\n"); return -1;
	}
	int i; Data d;
	for(i=13; i>0; i--){ //创建链表
		d.id = i;		add_head_linker(&linker, &d);
	}
	//show_all_linker(&linker);
	//不断绕圈
	i=1; Node *p=linker.header, *old;
	while(linker.count>0){
        old=p->next;
        printf("[%d]-id=%d ", i, p->data.id);
        if(i==3){
            printf("[√]\n");
            remove_node_linker(&linker, p);
            i=1;
        }else i++;
        p=old;
	}
	delete_linker(&linker);
    return 0;
}
