#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linker.h"

EXIT_FLAG create_linker(Linker *linker) //创建链表
{
    if( linker == NULL ) //如果传递的链表是空指针，则不能执行
        return ex_not_exist;

    //如果传递进来的链表不是空的，
    if(linker-> header != NULL)
    {
        delete_linker(linker); //必须先删除原来的链表
    }
    linker->header = NULL; //初始化是头指针指向空指针
    linker->count=0;
    return ex_ok;
}

EXIT_FLAG delete_linker(Linker *linker) //删除链表
{
    if( linker == NULL ) //如果传递的链表是空指针，则不能执行
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

EXIT_FLAG add_head_linker(Linker *linker, const Data *d) //在链表头插入数据
{
    if( linker == NULL ) //如果传递的链表是空指针，则不能执行
        return ex_not_exist;
    Node *p = malloc(sizeof(Node)); //创建新的节点
    if(p==NULL)
        return ex_not_enough_mem;
    p->data = *d; //对新节点设置数据
    if(linker->count==0) //如果是第一个节点
    {
        p->next = p;
        p->prev = p;
        linker->header = p;
        linker->count++;
    }
    else  //如果不是第一个
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

EXIT_FLAG add_tail_linker(Linker *linker, const Data *d) //在链表尾部插入数据
{
    if( linker == NULL ) //如果传递的链表是空指针，则不能执行
        return ex_not_exist;
    Node *p = malloc(sizeof(Node)); //创建新的节点
    if(p==NULL)
        return ex_not_enough_mem;
    p->data = *d; //对新节点设置数据
    if(linker->count==0) //如果是第一个节点
    {
        p->next = p;
        p->prev = p;
        linker->header = p;
        linker->count++;
    }
    else  //如果不是第一个
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

EXIT_FLAG insert_linker(Linker *linker, Node *n, const Data *d); //在指定链表节点后插入数据
EXIT_FLAG remove_head_linker(Linker *linker); //删除链表头
EXIT_FLAG remove_tail_linker(Linker *linker); //删除链表尾

EXIT_FLAG remove_node_linker(Linker *linker, Node *n) //删除指定链表节点
{
    if( linker == NULL ) //如果传递的链表是空指针，则不能执行
        return ex_not_exist;
    if( linker->header == NULL) //如果链表中没有节点
        return ex_not_exist;
    if( linker->count == 1) //如果只有一个节点
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
        //如果n在第一节点，则修改header指向
        if(n==linker->header)
            linker->header=n->next;
        free(n);
        linker->count--;
    }
    return ex_ok;
}

EXIT_FLAG get_head_linker(Linker *linker, Node *n); //获取链表头
EXIT_FLAG get_tail_linker(Linker *linker, Node *n); //获取链表尾
EXIT_FLAG find_node_linker(Linker *linker, const Data *d, Node *n); //获取指定数据的节点

EXIT_FLAG go_linker(Linker *linker, oper_fun fun) //遍历链表，对每个节点执行fun函数
{
    if( linker == NULL ) //如果传递的链表是空指针，则不能执行
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

void show_all_linker(Linker *linker) //输出整个链表
{
    go_linker(linker, oper_print_fun);
    putchar('\n');
}
