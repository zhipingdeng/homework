---
layout: default
title: lab13
---

# 智能蛇实验报告
## 目录
1.sin函数实验

2.kbhit()的实现

3.智能蛇的实现

    3.1智能蛇moveTO函数
    3.2能蛇代码及效果图
    3.3长度为5的障碍物困死蛇
4.总结
## sin函数实验
在ubuntu创建文件并复制函数（去除注释）后，效果图如下：

![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/OZv7PxIDa0RM5Z9fp1p1f25hE*nEOQr8oDd0Id2j3jQ!/b/dFIBAAAAAAAA&bo=agNTAgAAAAACFws!&rf=viewer_4)

## kbhit()实验
在ubuntu创建文件并复制函数（去除注释）后，效果图如下：

![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/SsncRg2GdWNaatJqobfhqhxyV6A1RjTGOK6j.qBvPJA!/b/dLYAAAAAAAAA&bo=lQHOAQAAAAADF2k!&rf=viewer_4)

## 智能蛇的实现
### 智能蛇的moveTO函数
```c
int moveTO(void){
	char movable[5]="wasd";
	int distance[4]={0,0,0,0};
	int i,min=0;
	if(map[snakeY[0]-1][snakeX[0]]==BLANK_CELL||map[snakeY[0]-1][snakeX[0]]==SNAKE_FOOD){
		distance[0]=fabs(snakeY[0]-1-foodY)+fabs(snakeX[0]-foodX);
	}
	else{
		distance[0]=9999;
	}
	
	if(map[snakeY[0]][snakeX[0]-1]==BLANK_CELL||map[snakeY[0]][snakeX[0]-1]==SNAKE_FOOD){
		distance[1]=fabs(snakeY[0]-foodY)+fabs(snakeX[0]-1-foodX);
	}
	else{
		distance[1]=9999;
	}
	
	if(map[snakeY[0]+1][snakeX[0]]==BLANK_CELL||map[snakeY[0]+1][snakeX[0]]==SNAKE_FOOD){
		distance[2]=fabs(snakeY[0]+1-foodY)+fabs(snakeX[0]-foodX);
	}
	else{
		distance[2]=9999;
	}

	if(map[snakeY[0]][snakeX[0]+1]==BLANK_CELL||map[snakeY[0]][snakeX[0]+1]==SNAKE_FOOD){
		distance[3]=fabs(snakeY[0]-foodY)+fabs(snakeX[0]+1-foodX);
	}
	else{
		distance[3]=9999;
	}
	for(i=1;i<4;i++){
		if(distance[i]<distance[min]){
			min=i;
		}
	}
	return movable[min];
}
```
### 智能蛇代码及其效果图

```c
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>

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

int moveTO(void);//智能转向 

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
int gamefail=0;//判断游戏是否结束
int foodX=1;//初始化食物坐标 
int foodY=1;
int main(){
	int direction='d';//初始方向 
	int predirection='d';//判断是否转向 
	int food_eaten=0; 
	put_money();
	output();//游戏初始化 
	while(!gamefail){
		usleep(500000); 
		system("cls");
		predirection=moveTO();//自动改变方向
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
	int is_eat = 0;//判断是否吃到食物
	if(map[snakeY[0]+dy][snakeX[0]+dx] == SNAKE_FOOD){ //判断头部进行move时是否会吃到食物 
		is_eat = 1;//如果吃到食物则更新
		snakeLength++;//吃后蛇长度+1 
		put_money(); 
	}
	if(map[snakeY[0]+dy][snakeX[0]+dx] == SNAKE_BODY){//判断头部是否碰到身体 
		gamefail=1;
	}
	if(!is_eat){
		map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]=' ';
	}
	for(i=snakeLength-1;i>=1;i--){
		snakeX[i]=snakeX[i-1];
		snakeY[i]=snakeY[i-1];
		map[snakeY[i]][snakeX[i]]=SNAKE_BODY;
	}
	snakeX[0]+=dx;
	snakeY[0]+=dy;
	
	map[snakeY[0]][snakeX[0]]=SNAKE_HEAD;	
} 
void put_money(void){//  随机投放食物
    srand(time(0)); //  初始化食物随机
    while (1) { //  一直循环随机直到出现可行坐标 
        foodX=(rand() % 11)+1; foodY=(rand() % 11)+1;    //  随机一个坐标 
        if (map[foodY][foodX]==BLANK_CELL) {    //  若此坐标为空白格 
            map[foodY][foodX] = SNAKE_FOOD ;   //  改为食物 
            return;     //  跳出 
        }  
    }
}
void output(void){//输出图表 
	int i;
	for(i=0;i<12;i++){
		printf("%s\n",map[i]);
	}
}
void gameover(void){//输出“Game Over！！！”
	printf("Game Over!!!\n");
}
int moveTO(void){
	char movable[5]="wasd";
	int distance[4]={0,0,0,0};
	int i,min=0;
	if(map[snakeY[0]-1][snakeX[0]]==BLANK_CELL||map[snakeY[0]-1][snakeX[0]]==SNAKE_FOOD){
		distance[0]=fabs(snakeY[0]-1-foodY)+fabs(snakeX[0]-foodX);
	}
	else{
		distance[0]=9999;
	}
	if(map[snakeY[0]][snakeX[0]-1]==BLANK_CELL||map[snakeY[0]][snakeX[0]-1]==SNAKE_FOOD){
		distance[1]=fabs(snakeY[0]-foodY)+fabs(snakeX[0]-1-foodX);
	}
	else{
		distance[1]=9999;
	}
	
	if(map[snakeY[0]+1][snakeX[0]]==BLANK_CELL||map[snakeY[0]+1][snakeX[0]]==SNAKE_FOOD){
		distance[2]=fabs(snakeY[0]+1-foodY)+fabs(snakeX[0]-foodX);
	}
	else{
		distance[2]=9999;
	}

	if(map[snakeY[0]][snakeX[0]+1]==BLANK_CELL||map[snakeY[0]][snakeX[0]+1]==SNAKE_FOOD){
		distance[3]=fabs(snakeY[0]-foodY)+fabs(snakeX[0]+1-foodX);
	}
	else{
		distance[3]=9999;
	}
	for(i=1;i<4;i++){
		if(distance[i]<distance[min]){
			min=i;
		}
	}
	return movable[min];
}
```
效果图：

![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/yxZLTuEJu9FcdNXXzSdW.C8jh36KBVybGl1voufkw1w!/b/dL4AAAAAAAAA&bo=agNTAgAAAAACFws!&rf=viewer_4)

### 长度为5的障碍物困死蛇

![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/y4qhxW*kdywwDQytRaFt4mYea0T*6cvCUW84CUKaAzE!/b/dL0AAAAAAAAA&bo=ngJTAgAAAAACF*4!&rf=viewer_4)

## 总结
智能蛇是字符蛇的进阶，增加一个函数就能使蛇变得智能，我认为者很有趣。

同时sin函数以及kbhit函数的实现也十分有趣。在Linux环境进行程序编译和执行也很有趣。