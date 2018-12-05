#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<synchapi.h> 

#define SNAKE_MAX_LENGTH 20//蛇最大长度 
#define SNAKE_HEAD 'H'//蛇头 
#define SNAKE_BODY 'X'//蛇身 
#define BLANK_CELL ' '//空白 
#define SNAKE_FOOD '$'//食物 
#define WALL_CELL '*'//边界 


void snakeMove(int,int);//'W''S''A''D'分别为上，下，左，右 

void put_money(void);//在任意地点投放食物 

void output(void);//输出图表 

void gameover(void);//输出“Game Over！！！” 

char map[12][13]=
	{"************",              //初始状态 
	"*XXXXH     *",             //直接打表 
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************"};

int snakeX[SNAKE_MAX_LENGTH]={5,4,3,2,1};         //蛇身和蛇头的坐标 
int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};
int snakeLength=5;                  //蛇身初始长度 

int main(){
	int direction='d';//初始方向 
	int predirection='d';//判断是否转向 
	int gamefail=0;//判断游戏是否结束 
	output();//游戏初始化 
	while(!gamefail){
		Sleep(1000); 
		system("cls");
		if(kbhit()){ //有键入时改变方向 
			predirection=getch();
			switch(direction){//判断是否转向 
				case 'w': 
					if(predirection=='a'||predirection=='d')
					direction=predirection;
					break;
				case 'a': 
					if(predirection=='w'||predirection=='s')
					direction=predirection;
					break;
				case 's': 
					if(predirection=='a'||predirection=='d')
					direction=predirection;
					break;
				case 'd': 
					if(predirection=='w'||predirection=='s')
					direction=predirection;
					break;
			}
		}
		switch(direction) {
			case 'w': snakeMove(0,-1);break;
			case 'a': snakeMove(-1,0);break;
			case 's': snakeMove(0,1);break;
			case 'd': snakeMove(1,0);break;
		}
		if(!(snakeX[0]>=1&&snakeX[0]<=10&&snakeY[0]>=1&&snakeY[0]<=10))
		gamefail=1;
		output();
	}
	gameover(); 
	
} 
void snakeMove(int dx,int dy){
	int i;
	map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]=' ';
	
	for(i=snakeLength-1;i>=1;i--){
		snakeX[i]=snakeX[i-1];
		snakeY[i]=snakeY[i-1];
		map[snakeY[i]][snakeX[i]]=SNAKE_BODY;
	}
	snakeX[0]+=dx;
	snakeY[0]+=dy;
	map[snakeY[0]][snakeX[0]]=SNAKE_HEAD;
			
} 
void put_money(void){
}
void output(void){//输出图表 
	int i;
	for(i=0;i<12;i++){
		printf("%s\n",map[i]);
	}
}
void gameover(void){//输出“Game Over！！！”
	printf("Game Over!!!");
}
