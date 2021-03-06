#include <stdio.h>
#include <string.h>
typedef struct{	char *name;	float score;}Course; //每门课的类型
typedef struct{
	char id[13]; //学号：4位学级+2位学院号+2位专业号+2位班号+2位班内序号=12位+1位结尾符=13位
	char name[31]; //姓名
	Course course[3]; //课程
}Student; //每个学生的类型

void init_data(FILE *fin, Student *stu, int n);
void show_data(Student *stu, int n);
void average_course(Student *stu, int n);
void find_highest(Student *stu, int n, char *course);

int main()
{	int n=10;
	Student stu[n];
	FILE *fin ;
	if((fin=fopen("1.dat", "r"))==NULL){
		printf("文件打开错误。\n"); return -1;
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
		printf("\n输入第%d个学生的学号：", i+1);
		fscanf(fin, "%s", (stu+i)->id);

		printf("\n输入第%d个学生的姓名：", i+1);
		fscanf(fin, "%s", (stu+i)->name);

		printf("\n输入第%d个学生的C语言成绩：", i+1);
		(stu+i)->course[0].name=course_name[0];
		fscanf(fin, "%f", &((stu+i)->course[0].score));
		printf("\n输入第%d个学生的数学成绩：", i+1);
		(stu+i)->course[1].name=course_name[1];
		fscanf(fin, "%f", &((stu+i)->course[1].score));
		printf("\n输入第%d个学生的英语成绩：", i+1);
		(stu+i)->course[2].name=course_name[2];
		fscanf(fin, "%f", &((stu+i)->course[2].score));
	}
}

void show_data(Student *stu, int n)
{	puts("\n\n-------输出学生信息-------");
	printf("No.\t[%12s][%8s]%10s%10s%10s\n", "学号", "姓名",
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
		printf("\n %10s 的平均分=%.2f\n", stu[0].course[i].name, sum/n);
	}
}

void find_highest(Student *stu, int n, char *course)
{
	int i, j, course_id, max_pos;
	for(i=0;i<3;i++)
		if(strcmp(stu[0].course[i].name, course)==0)
			break;
	if(i>=3){ //没找到课程
		printf("\n%s 课程不在数据库中\n", course);
		return;
	}
	course_id = i;
	max_pos=0;
	for(j=0;j<n;j++){
		if( stu[j].course[course_id].score > stu[max_pos].course[course_id].score )
			max_pos=j;
	}

	printf("\n %8s 课程的最高分是 [%12s] [%5s]:\n" \
		   "其3门课分别为：[%3s]: %6.1f [%5s]: %6.1f [%8s]: %6.1f 平均分=%6.1f\n",
			stu[0].course[course_id].name, stu[max_pos].id, stu[max_pos].name,
			stu[max_pos].course[0].name, stu[max_pos].course[0].score,
			stu[max_pos].course[1].name, stu[max_pos].course[1].score,
			stu[max_pos].course[2].name, stu[max_pos].course[2].score,
			(stu[max_pos].course[0].score+stu[max_pos].course[1].score+stu[max_pos].course[2].score)/3.0 );
}
