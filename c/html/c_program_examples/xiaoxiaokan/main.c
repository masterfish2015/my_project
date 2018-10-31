#include <stdio.h>
#include <stdlib.h>

//下面是游戏所在的状态 
#define STATE_START 0
#define STATE_RUNNING_1 1
#define STATE_RUNNING_2 2
#define STATE_WIN 3
#define STATE_LOSE 4

//行列数目 
#define ROW_COUNT 4
#define COL_COUNT 3

int main(int argc, char *argv[]) 
{
	int field[ROW_COUNT][COL_COUNT] = {0},  //保存每个行列单元的数值 
		mask[ROW_COUNT][COL_COUNT]={0};     //是否打开盖子，0：没打开，1：打开 
	
	int state = STATE_START,  //游戏状态 
		quit=0,  	//退出状态 
		row, col,  	//行、列坐标 
		value,  	//要消除的数值的个数 
		lifes,		//能够尝试的次数 
		first_row=0, first_col=0, second_row=0, second_col=0  //第1、2次选中的坐标 
		;
	do{
		switch(state){
			case STATE_START: //游戏初始化
				{
					value = ROW_COUNT*COL_COUNT/2; //有多少个要消去的值 
					lifes = 5; //5条命 
					
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
			case STATE_RUNNING_1: //游戏开始
				//绘制游戏区域
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
				printf("输入命令(q:退出, o:打开盖子):");
				int sel=getchar();
				while(getchar()!='\n'); //消除输入缓冲
				switch(sel){
					case 'q': case 'Q': quit=1; break;
					case 'o': case 'O': //打开一个盖子
						{
							do{
								printf("输入打开盖子的单元: row,col:"); scanf("%d,%d",&row,&col);	
								while(getchar()!='\n'); //消除输入缓冲
								if(row>0 && row<=ROW_COUNT && col>0 && col<=COL_COUNT){
									//判断是否已经打开，或者已经消去
									if(field[row-1][col-1]>0){
										first_row = row; 
										first_col = col;
										//绘制游戏区域 
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
										printf("已打开或已消除。\n");	
									}					
								}else{
									printf("行、列坐标错误。\n", ROW_COUNT, COL_COUNT);
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
						printf("请输入第二个单元的行、列坐标: row,col:"); scanf("%d,%d",&row,&col);	
						while(getchar()!='\n'); //消除输入缓冲
						if(row>0 && row<=ROW_COUNT && col>0 && col<=COL_COUNT){
							//判断是否已经打开，或者已经消去
							if((field[row-1][col-1]>0) && (row!=first_row || col!=first_col)){
								second_row=row; second_col=col;
								//绘制游戏区域 
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
									//成功消去一个值 
									printf("已消除。 按 <enter> 继续。 \n");
									while(getchar()!='\n');
									
									field[first_row-1][first_col-1]=0; mask[first_row-1][first_col-1]=1;
									field[second_row-1][second_col-1]=0; mask[second_row-1][second_col-1]=1;
									value --; 
									state = (value==0)?STATE_WIN:STATE_RUNNING_1;
								}
								else{
									//失败 
									printf("消除失败。\n");
									printf("按 <enter> 继续。 \n");
									while(getchar()!='\n');
									
									lifes--;
									state = (lifes==0)?STATE_LOSE:STATE_RUNNING_1;
								}
								break;
							}
							else{
								printf("已打开或已消除。\n");	
							}					
						}else{
							printf("行、列坐标输入错误。\n", ROW_COUNT, COL_COUNT);
						}
					}while(1);
				}
				break;
			case STATE_WIN:
				system("cls"); 
				printf("YOU WIN!!!!!\n");
				
				printf("重玩吗?(y/n)"); 
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
				
				printf("重玩吗?(y/n)"); 
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
