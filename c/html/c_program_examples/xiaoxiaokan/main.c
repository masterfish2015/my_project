#include <stdio.h>
#include <stdlib.h>

//��������Ϸ���ڵ�״̬ 
#define STATE_START 0
#define STATE_RUNNING_1 1
#define STATE_RUNNING_2 2
#define STATE_WIN 3
#define STATE_LOSE 4

//������Ŀ 
#define ROW_COUNT 4
#define COL_COUNT 3

int main(int argc, char *argv[]) 
{
	int field[ROW_COUNT][COL_COUNT] = {0},  //����ÿ�����е�Ԫ����ֵ 
		mask[ROW_COUNT][COL_COUNT]={0};     //�Ƿ�򿪸��ӣ�0��û�򿪣�1���� 
	
	int state = STATE_START,  //��Ϸ״̬ 
		quit=0,  	//�˳�״̬ 
		row, col,  	//�С������� 
		value,  	//Ҫ��������ֵ�ĸ��� 
		lifes,		//�ܹ����ԵĴ��� 
		first_row=0, first_col=0, second_row=0, second_col=0  //��1��2��ѡ�е����� 
		;
	do{
		switch(state){
			case STATE_START: //��Ϸ��ʼ��
				{
					value = ROW_COUNT*COL_COUNT/2; //�ж��ٸ�Ҫ��ȥ��ֵ 
					lifes = 5; //5���� 
					
					for(int i =1; i<=value; i++){
						for(int j=0;j<2;j++)
							do{
								row=rand()%ROW_COUNT; 
								col=rand()%COL_COUNT;
								if(field[row][col]==0){
									field[row][col]=i;
									break;
								}
							}while(1);
					}
					for(row=0;row<ROW_COUNT;row++)
						for(col=0;col<COL_COUNT;col++)
							mask[row][col]=0;
				}
				first_row=0, first_col=0, second_row=0, second_col=0;
				state = STATE_RUNNING_1;
				
				break; 
			case STATE_RUNNING_1: //��Ϸ��ʼ
				//������Ϸ����
				system("cls");
				for(int i=1;i<=COL_COUNT;i++)
					printf("\t%d", i);
				printf("\n---------------------------------- lifes = %4d | left value = %4d \n", lifes, value);
				
				for(row=1;row<=ROW_COUNT;row++){
					printf("%d\t", row);
					for(col=1; col<=COL_COUNT;col++){
						if(mask[row-1][col-1]!=0)
							printf("%d\t",field[row-1][col-1]);
						else
							printf("*\t");
					}
					printf("\n");
				}
				printf("��������(q:�˳�, o:�򿪸���):");
				int sel=getchar();
				while(getchar()!='\n'); //�������뻺��
				switch(sel){
					case 'q': case 'Q': quit=1; break;
					case 'o': case 'O': //��һ������
						{
							do{
								printf("����򿪸��ӵĵ�Ԫ: row,col:"); scanf("%d,%d",&row,&col);	
								while(getchar()!='\n'); //�������뻺��
								if(row>0 && row<=ROW_COUNT && col>0 && col<=COL_COUNT){
									//�ж��Ƿ��Ѿ��򿪣������Ѿ���ȥ
									if(field[row-1][col-1]>0){
										first_row = row; 
										first_col = col;
										//������Ϸ���� 
										system("cls");
										for(int i=1;i<=COL_COUNT;i++)
											printf("\t%d", i);
										printf("\n---------------------------------- lifes = %4d | left value = %4d \n", lifes, value);
										for(row=1;row<=ROW_COUNT;row++){
											printf("%d\t", row);
											for(col=1; col<=COL_COUNT;col++){
												if(mask[row-1][col-1]!=0 || (row==first_row && col==first_col))
													printf("%d\t",field[row-1][col-1]);
												else
													printf("*\t");
											}
											printf("\n");
										}
										break;
									}
									else{
										printf("�Ѵ򿪻���������\n");	
									}					
								}else{
									printf("�С����������\n", ROW_COUNT, COL_COUNT);
								}
							}while(1);							
							state = STATE_RUNNING_2;
						} 
						break;
				}
				break; //end of case STATE_RUNNING_1
			case STATE_RUNNING_2: 
				{
					do{
						printf("������ڶ�����Ԫ���С�������: row,col:"); scanf("%d,%d",&row,&col);	
						while(getchar()!='\n'); //�������뻺��
						if(row>0 && row<=ROW_COUNT && col>0 && col<=COL_COUNT){
							//�ж��Ƿ��Ѿ��򿪣������Ѿ���ȥ
							if((field[row-1][col-1]>0) && (row!=first_row || col!=first_col)){
								second_row=row; second_col=col;
								//������Ϸ���� 
								for(int i=1;i<=COL_COUNT;i++)
									printf("\t%d", i);
								printf("\n---------------------------------- lifes = %4d | left value = %4d \n", lifes, value);
								for(row=1;row<=ROW_COUNT;row++){
									printf("%d\t", row);
									for(col=1; col<=COL_COUNT;col++){
										if(  (mask[row-1][col-1]!=0 ) || 
											(row==first_row && col==first_col) || 
											(row==second_row && col==second_col) 
										  )
											printf("%d\t",field[row-1][col-1]);
										else
											printf("*\t");
									}
									printf("\n");
								}
								if(field[first_row-1][first_col-1]==field[second_row-1][second_col-1]){
									//�ɹ���ȥһ��ֵ 
									printf("�������� �� <enter> ������ \n");
									while(getchar()!='\n');
									
									field[first_row-1][first_col-1]=0; mask[first_row-1][first_col-1]=1;
									field[second_row-1][second_col-1]=0; mask[second_row-1][second_col-1]=1;
									value --; 
									state = (value==0)?STATE_WIN:STATE_RUNNING_1;
								}
								else{
									//ʧ�� 
									printf("����ʧ�ܡ�\n");
									printf("�� <enter> ������ \n");
									while(getchar()!='\n');
									
									lifes--;
									state = (lifes==0)?STATE_LOSE:STATE_RUNNING_1;
								}
								break;
							}
							else{
								printf("�Ѵ򿪻���������\n");	
							}					
						}else{
							printf("�С��������������\n", ROW_COUNT, COL_COUNT);
						}
					}while(1);
				}
				break;
			case STATE_WIN:
				system("cls"); 
				printf("YOU WIN!!!!!\n");
				
				printf("������?(y/n)"); 
				sel = getchar();
				while(getchar()!='\n');
				
				switch(sel){
					case 'y': case 'Y': state=STATE_START; break; 
					default : quit = 1; break;							
				}
				break;
			case STATE_LOSE: 
				system("cls");
				printf("YOU LOSE!!!!!\n");
				
				printf("������?(y/n)"); 
				sel = getchar();
				while(getchar()!='\n');
				
				switch(sel){
					case 'y': case 'Y': state=STATE_START; break; 
					default : quit = 1; break;							
				}
				break;
		}
		 
	}while(quit==0);
	return 0;
}
