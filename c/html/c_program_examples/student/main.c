#include <stdio.h>
#include <string.h>
typedef struct{	char *name;	float score;}Course; //ÿ�ſε�����
typedef struct{
	char id[13]; //ѧ�ţ�4λѧ��+2λѧԺ��+2λרҵ��+2λ���+2λ�������=12λ+1λ��β��=13λ
	char name[31]; //����
	Course course[3]; //�γ�
}Student; //ÿ��ѧ��������

void init_data(FILE *fin, Student *stu, int n);
void show_data(Student *stu, int n);
void average_course(Student *stu, int n);
void find_highest(Student *stu, int n, char *course);

int main()
{	int n=10;
	Student stu[n];
	FILE *fin ;
	if((fin=fopen("1.dat", "r"))==NULL){
		printf("�ļ��򿪴���\n"); return -1;
	}
	init_data(fin, stu, n);
	fclose(fin);
    show_data(stu, n);
    average_course(stu, n);
    find_highest(stu, n, "c");
    find_highest(stu, n, "math");
    find_highest(stu, n, "english");
    return 0;
}
void init_data(FILE *fin, Student *stu, int n)
{
	static char *course_name[]={"c","math","english"};
	int i;
	for(i=0;i<n;i++){
		printf("\n�����%d��ѧ����ѧ�ţ�", i+1);
		fscanf(fin, "%s", (stu+i)->id);

		printf("\n�����%d��ѧ����������", i+1);
		fscanf(fin, "%s", (stu+i)->name);

		printf("\n�����%d��ѧ����C���Գɼ���", i+1);
		(stu+i)->course[0].name=course_name[0];
		fscanf(fin, "%f", &((stu+i)->course[0].score));
		printf("\n�����%d��ѧ������ѧ�ɼ���", i+1);
		(stu+i)->course[1].name=course_name[1];
		fscanf(fin, "%f", &((stu+i)->course[1].score));
		printf("\n�����%d��ѧ����Ӣ��ɼ���", i+1);
		(stu+i)->course[2].name=course_name[2];
		fscanf(fin, "%f", &((stu+i)->course[2].score));
	}
}

void show_data(Student *stu, int n)
{	puts("\n\n-------���ѧ����Ϣ-------");
	printf("No.\t[%12s][%8s]%10s%10s%10s\n", "ѧ��", "����",
			stu->course[0].name, stu->course[1].name, stu->course[2].name);
	for(int i=0; i<n; i++){
		printf("%d\t[%12s][%8s]%10.1f%10.1f%10.1f\n",i+1,(stu+i)->id, (stu+i)->name,
				(stu+i)->course[0].score,
				(stu+i)->course[1].score,
				(stu+i)->course[2].score);
	}
}

void average_course(Student *stu, int n)
{
	float sum;
	for(int i=0; i<3; i++){
		sum=0;
		for(int j=0; j<n; j++){
			sum += stu[j].course[i].score;
		}
		printf("\n %10s ��ƽ����=%.2f\n", stu[0].course[i].name, sum/n);
	}
}

void find_highest(Student *stu, int n, char *course)
{
	int i, j, course_id, max_pos;
	for(i=0;i<3;i++)
		if(strcmp(stu[0].course[i].name, course)==0)
			break;
	if(i>=3){ //û�ҵ��γ�
		printf("\n%s �γ̲������ݿ���\n", course);
		return;
	}
	course_id = i;
	max_pos=0;
	for(j=0;j<n;j++){
		if( stu[j].course[course_id].score > stu[max_pos].course[course_id].score )
			max_pos=j;
	}

	printf("\n %8s �γ̵���߷��� [%12s] [%5s]:\n" \
		   "��3�ſηֱ�Ϊ��[%3s]: %6.1f [%5s]: %6.1f [%8s]: %6.1f ƽ����=%6.1f\n",
			stu[0].course[course_id].name, stu[max_pos].id, stu[max_pos].name,
			stu[max_pos].course[0].name, stu[max_pos].course[0].score,
			stu[max_pos].course[1].name, stu[max_pos].course[1].score,
			stu[max_pos].course[2].name, stu[max_pos].course[2].score,
			(stu[max_pos].course[0].score+stu[max_pos].course[1].score+stu[max_pos].course[2].score)/3.0 );
}