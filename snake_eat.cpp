#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<synchapi.h> 

#define SNAKE_MAX_LENGTH 20//����󳤶� 
#define SNAKE_HEAD 'H'//��ͷ 
#define SNAKE_BODY 'X'//���� 
#define BLANK_CELL ' '//�հ� 
#define SNAKE_FOOD '$'//ʳ�� 
#define WALL_CELL '*'//�߽� 


void snakeMove(int,int);//'W''S''A''D'�ֱ�Ϊ�ϣ��£����� 

void put_money(void);//������ص�Ͷ��ʳ�� 

void output(void);//���ͼ�� 

void gameover(void);//�����Game Over�������� 

char map[12][13]=
	{"************",              //��ʼ״̬ 
	"*XXXXH     *",             //ֱ�Ӵ�� 
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

int snakeX[SNAKE_MAX_LENGTH]={5,4,3,2,1};         //�������ͷ������ 
int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};
int snakeLength=5;                  //�����ʼ���� 
int gamefail=0;//�ж���Ϸ�Ƿ����

int main(){
	int direction='d';//��ʼ���� 
	int predirection='d';//�ж��Ƿ�ת�� 
	int food_eaten=0; 
	put_money();
	output();//��Ϸ��ʼ�� 
	while(!gamefail){
		Sleep(500); 
		system("cls");
		if(kbhit()){ //�м���ʱ�ı䷽�� 
			predirection=getch();
			switch(direction){//�ж��Ƿ�ת�� 
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
	int is_eat = 0;//�ж��Ƿ�Ե�ʳ��
	if(map[snakeY[0]+dy][snakeX[0]+dx] == SNAKE_FOOD){ //�ж�ͷ������moveʱ�Ƿ��Ե�ʳ�� 
		is_eat = 1;//����Ե�ʳ�������
		snakeLength++;//�Ժ��߳���+1 
		put_money(); 
	}
	if(map[snakeY[0]+dy][snakeX[0]+dx] == SNAKE_BODY){//�ж�ͷ���Ƿ��������� 
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
void put_money(void){//  ���Ͷ��ʳ��
	     

    srand(time(0)); //  ��ʼ��ʳ�����
    int x,y;
    while (1) { //  һֱѭ�����ֱ�����ֿ������� 
        x=(rand() % 11)+1; y=(rand() % 11)+1;    //  ���һ������ 
        if (map[x][y]==BLANK_CELL) {    //  ��������Ϊ�հ׸� 
            map[x][y] = SNAKE_FOOD ;   //  ��Ϊʳ�� 
            return;     //  ���� 
        }  
    }
    
}
void output(void){//���ͼ�� 
	int i;
	for(i=0;i<12;i++){
		printf("%s\n",map[i]);
	}
}
void gameover(void){//�����Game Over��������
	printf("Game Over!!!");
}

