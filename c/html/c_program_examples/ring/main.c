#include <stdio.h>
#include <stdlib.h>
#include "linker.h"

int main()
{
	Linker linker={NULL} ;
	if (create_linker(&linker)!=ex_ok){
		printf("������������˳���\n"); return -1;
	}
	int i; Data d;
	for(i=13; i>0; i--){ //��������
		d.id = i;		add_head_linker(&linker, &d);
	}
	//show_all_linker(&linker);
	//������Ȧ
	i=1; Node *p=linker.header, *old;
	while(linker.count>0){
        old=p->next;
        printf("[%d]-id=%d ", i, p->data.id);
        if(i==3){
            printf("[��]\n");
            remove_node_linker(&linker, p);
            i=1;
        }else i++;
        p=old;
	}
	delete_linker(&linker);
    return 0;
}
