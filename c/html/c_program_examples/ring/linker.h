#ifndef LINKER_H_INCLUDED
#define LINKER_H_INCLUDED
typedef struct _Data{ //数据类型
	int id;
}Data;
typedef struct _Node{ //节点类型
	Data data;
	struct _Node *next, *prev; //下一个节点和前一个节点
}Node;
typedef struct _Linker{//链表类型
	Node *header;
	int count ;
}Linker;

typedef enum {
	ex_ok=0, ex_not_enough_mem=-1, ex_not_exist=-2
}EXIT_FLAG;

typedef void (*oper_fun)(Node *n); //在链表遍历函数中使用的映射函数指针类型

extern EXIT_FLAG create_linker(Linker *linker); //创建链表
extern EXIT_FLAG delete_linker(Linker *linker); //删除链表
extern EXIT_FLAG add_head_linker(Linker *linker, const Data *d); //在链表头插入数据
extern EXIT_FLAG add_tail_linker(Linker *linker, const Data *d); //在链表尾部插入数据
extern EXIT_FLAG insert_linker(Linker *linker, Node *n, const Data *d); //在指定链表节点后插入数据
extern EXIT_FLAG remove_head_linker(Linker *linker); //删除链表头
extern EXIT_FLAG remove_tail_linker(Linker *linker); //删除链表尾
extern EXIT_FLAG remove_node_linker(Linker *linker, Node *n); //删除指定链表节点
extern EXIT_FLAG get_head_linker(Linker *linker, Node *n); //获取链表头
extern EXIT_FLAG get_tail_linker(Linker *linker, Node *n); //获取链表尾
extern EXIT_FLAG find_node_linker(Linker *linker, const Data *d, Node *n); //获取指定数据的节点
extern EXIT_FLAG go_linker(Linker *linker, oper_fun fun); //遍历链表，对每个节点执行fun函数
extern void show_all_linker(Linker *linker); //输出整个链表
#endif // LINKER_H_INCLUDED
