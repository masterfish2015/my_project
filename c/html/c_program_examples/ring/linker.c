#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linker.h"

EXIT_FLAG create_linker(Linker *linker) //��������
{
    if( linker == NULL ) //������ݵ������ǿ�ָ�룬����ִ��
        return ex_not_exist;

    //������ݽ����������ǿյģ�
    if(linker-> header != NULL)
    {
        delete_linker(linker); //������ɾ��ԭ��������
    }
    linker->header = NULL; //��ʼ����ͷָ��ָ���ָ��
    linker->count=0;
    return ex_ok;
}

EXIT_FLAG delete_linker(Linker *linker) //ɾ������
{
    if( linker == NULL ) //������ݵ������ǿ�ָ�룬����ִ��
        return ex_not_exist;
    Node *p = linker->header;
    if(p==NULL)
        return ex_ok;
    while(linker->count>0)
    {
        Node *pp = p;
        p = p->next;
        free(pp);
        linker->count--;
    }
    linker->header = NULL;
    linker->count =0;
    return ex_ok;
}

EXIT_FLAG add_head_linker(Linker *linker, const Data *d) //������ͷ��������
{
    if( linker == NULL ) //������ݵ������ǿ�ָ�룬����ִ��
        return ex_not_exist;
    Node *p = malloc(sizeof(Node)); //�����µĽڵ�
    if(p==NULL)
        return ex_not_enough_mem;
    p->data = *d; //���½ڵ���������
    if(linker->count==0) //����ǵ�һ���ڵ�
    {
        p->next = p;
        p->prev = p;
        linker->header = p;
        linker->count++;
    }
    else  //������ǵ�һ��
    {
        Node *next_node=linker->header, *prev_node=linker->header->prev;
        p->next = prev_node->next;
        prev_node->next = p;
        p->prev = next_node->prev;
        next_node->prev = p;

        linker->header = p;
        linker->count++;
    }
    return ex_ok;
}

EXIT_FLAG add_tail_linker(Linker *linker, const Data *d) //������β����������
{
    if( linker == NULL ) //������ݵ������ǿ�ָ�룬����ִ��
        return ex_not_exist;
    Node *p = malloc(sizeof(Node)); //�����µĽڵ�
    if(p==NULL)
        return ex_not_enough_mem;
    p->data = *d; //���½ڵ���������
    if(linker->count==0) //����ǵ�һ���ڵ�
    {
        p->next = p;
        p->prev = p;
        linker->header = p;
        linker->count++;
    }
    else  //������ǵ�һ��
    {
        Node *next_node=linker->header, *prev_node=linker->header->prev;
        p->next = prev_node->next;
        prev_node->next = p;
        p->prev = next_node->prev;
        next_node->prev = p;
        linker->count++;
    }
    return ex_ok;
}

EXIT_FLAG insert_linker(Linker *linker, Node *n, const Data *d); //��ָ������ڵ���������
EXIT_FLAG remove_head_linker(Linker *linker); //ɾ������ͷ
EXIT_FLAG remove_tail_linker(Linker *linker); //ɾ������β

EXIT_FLAG remove_node_linker(Linker *linker, Node *n) //ɾ��ָ������ڵ�
{
    if( linker == NULL ) //������ݵ������ǿ�ָ�룬����ִ��
        return ex_not_exist;
    if( linker->header == NULL) //���������û�нڵ�
        return ex_not_exist;
    if( linker->count == 1) //���ֻ��һ���ڵ�
    {
        free(n);
        linker->header = NULL;
        linker->count = 0;
    }
    else
    {
        Node *next_node=n->next, *prev_node=n->prev;
        prev_node->next = n->next;
        next_node->prev = n->prev;
        //���n�ڵ�һ�ڵ㣬���޸�headerָ��
        if(n==linker->header)
            linker->header=n->next;
        free(n);
        linker->count--;
    }
    return ex_ok;
}

EXIT_FLAG get_head_linker(Linker *linker, Node *n); //��ȡ����ͷ
EXIT_FLAG get_tail_linker(Linker *linker, Node *n); //��ȡ����β
EXIT_FLAG find_node_linker(Linker *linker, const Data *d, Node *n); //��ȡָ�����ݵĽڵ�

EXIT_FLAG go_linker(Linker *linker, oper_fun fun) //����������ÿ���ڵ�ִ��fun����
{
    if( linker == NULL ) //������ݵ������ǿ�ָ�룬����ִ��
        return ex_not_exist;
    Node *p = linker->header;
    int i=0;

    for(i=0; i<linker->count; i++)
    {
        fun(p);
        p=p->next;
    }

    return ex_ok;
}

void oper_print_fun(Node *n)
{
    printf("[id=%d]", n->data.id);
}

void show_all_linker(Linker *linker) //�����������
{
    go_linker(linker, oper_print_fun);
    putchar('\n');
}
