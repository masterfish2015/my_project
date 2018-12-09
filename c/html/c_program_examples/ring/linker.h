#ifndef LINKER_H_INCLUDED
#define LINKER_H_INCLUDED
typedef struct _Data{ //��������
	int id;
}Data;
typedef struct _Node{ //�ڵ�����
	Data data;
	struct _Node *next, *prev; //��һ���ڵ��ǰһ���ڵ�
}Node;
typedef struct _Linker{//��������
	Node *header;
	int count ;
}Linker;

typedef enum {
	ex_ok=0, ex_not_enough_mem=-1, ex_not_exist=-2
}EXIT_FLAG;

typedef void (*oper_fun)(Node *n); //���������������ʹ�õ�ӳ�亯��ָ������

extern EXIT_FLAG create_linker(Linker *linker); //��������
extern EXIT_FLAG delete_linker(Linker *linker); //ɾ������
extern EXIT_FLAG add_head_linker(Linker *linker, const Data *d); //������ͷ��������
extern EXIT_FLAG add_tail_linker(Linker *linker, const Data *d); //������β����������
extern EXIT_FLAG insert_linker(Linker *linker, Node *n, const Data *d); //��ָ������ڵ���������
extern EXIT_FLAG remove_head_linker(Linker *linker); //ɾ������ͷ
extern EXIT_FLAG remove_tail_linker(Linker *linker); //ɾ������β
extern EXIT_FLAG remove_node_linker(Linker *linker, Node *n); //ɾ��ָ������ڵ�
extern EXIT_FLAG get_head_linker(Linker *linker, Node *n); //��ȡ����ͷ
extern EXIT_FLAG get_tail_linker(Linker *linker, Node *n); //��ȡ����β
extern EXIT_FLAG find_node_linker(Linker *linker, const Data *d, Node *n); //��ȡָ�����ݵĽڵ�
extern EXIT_FLAG go_linker(Linker *linker, oper_fun fun); //����������ÿ���ڵ�ִ��fun����
extern void show_all_linker(Linker *linker); //�����������
#endif // LINKER_H_INCLUDED
