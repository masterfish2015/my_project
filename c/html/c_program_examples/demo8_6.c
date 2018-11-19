#include"stdio.h"
#include"stdlib.h"
#include"string.h"

void *darray; 		//动态数组的开始地址
int darray_count; 	//动态数组的最大长度
int darray_size;  	//动态数组每个元素的字节数
int darray_last;  	//动态数组的最后加入的元素的序号

/*创建动态数组
参数：
	n	:动态数组的初始长度
	size:每个元素的字节数

返回值：
	若成功则返回开始地址
	若失败则返回NULL
*/
void *da_create(int n, int size)
{
	void *p=malloc(n*size);
	if(p!=NULL){
		darray_count = n; 
		darray_size = size;
		darray_last = -1; //-1 表示没有加入元素
		darray = p; 
	}
	return p;
}

/*增加元素到最后
参数：
	p:要加入的数据的地址
      注意数据的长度由darray_size定义

返回值：
	当加入值后序号超过原来的最大长度，
	则重新申请内存并复制到新内存；
	若成功则返回0
	若失败则返回-1
*/
int da_add_tail(void *p)
{
	if(darray_last+1 >= darray_count){
		//超出原来的长度
		//将动态数组的长度增加1倍
		int count = darray_count*2;
		void *p = malloc(count*darray_size);
		if(p==NULL)
			return -1; //内存不够
		//把原来数组内的内容复制到新数组中
		memcpy(p, darray, darray_count*darray_size);
		//释放原来的数组内存
		free(darray);
		//把darray重定向到新的内存地址三
		darray=p;
	}
	//下面空间足够，开始增加新的元素
	darray_last++; //下标+1
	//复制输入的元素内容到数组最后位置
	memcpy(darray+darray_last, p, darray_size);
}
/*打印数组中每一个元素
参数：
	fun: 函数指针，用于生成每个元素的字符串

返回值：
	无
*/
void da_print_all(char* (*fun)(char *str, void *p))
{
	char str[100];
	if(darray_last<0){
		puts("No element in array.\n");
		return; //若没有添加元素
	}
	for(int i=0;i<=darray_last;i++){
		printf("%s\n", fun(str, darray+i));
	}
}

char *convert_int(char *str, int *p)
{
	sprintf(str, "%d", *p);
	return str;
}

int main()
{	int a;
	da_create(2, sizeof(int));
	a=30;  da_add_tail(&a); 
	a=50;  da_add_tail(&a); 
	a=22;  da_add_tail(&a); 
	da_print_all(convert_int);
	
}





