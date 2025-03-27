#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define D 20
typedef struct player
{
        int x;
        int y;
        struct player *next;
}player;
typedef struct bullet
{
        int x;
        int y;
        int sta;
}bullet;
player *p,*head;
int i,s,key,score=0;
bullet bul;
void pos(int x,int y)
{
	COORD coord; 
	coord.X=x;
	coord.Y=y;
	HANDLE hOutPut;
    hOutPut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutPut,coord);
}
void createmap()
{
	for(i=15;i<=85;i=i+2){
		pos(i,3);
		printf("¡ö");
		pos(i,37);
		printf("¡ö");
	}
	for(i=4;i<37;i++){
		pos(15,i);
		printf("¡ö");
		pos(85,i);
		printf("¡ö");
	}
	pos(93,5);
	printf("Your score:%d",score);
}
void createtank()
{
	player *q;
    head=(player*)malloc(sizeof(player));
    head->x=50;
    head->y=21;
    q=head;
    for(i=0;i<2;i++)
    {
        p=(player*)malloc(sizeof(player));
        head->next=p;
        p->x=50+i;
    	p->y=20;
    	head=p;
    }
    for(i=0;i<2;i++)
    {
        p=(player*)malloc(sizeof(player));
        head->next=p;
        p->x=50+i;
        p->y=21;
        head=p;
    }
    p->next=NULL;
    head=q;
    p=head;
}
void printtank()
{
    while(p!=NULL)
    {
        pos(p->x,p->y);
        printf("¡ö");
        p=p->next;
    }
    p=head;
}
void tankmove()
{
    if(s==1)
    {
    	Sleep(D);
		system("cls");
		createmap();
		while (p!=NULL)
        {
            p->y=p->y-1;
            pos(p->x,p->y);
            printf("¡ö");
            p=p->next;
        }
		printtank();
    }
    if(s==2)
    {
        Sleep(D);
		system("cls");
		createmap();
		while (p!=NULL)
        {
            p->y=p->y+1;
            pos(p->x,p->y);
            printf("¡ö");
            p=p->next;
        }
		printtank();
    }
    if(s==3)
    {
        Sleep(D);
		system("cls");
		createmap();
		while (p!=NULL)
        {
            p->x=p->x-2;
            pos(p->x,p->y);
            printf("¡ö");
            p=p->next;
        }
		printtank();
	}
    if(s==4)
    {
    	Sleep(D);
		system("cls");
		createmap();
		while (p!=NULL)
        {
            p->x=p->x+2;
            pos(p->x,p->y);
            printf("¡ö");
            p=p->next;
        }
		printtank();
    }
}
void endgame()
{
	system("cls");
	createmap();
	pos(50,20);
	printf("Game Over");
	Sleep(1000);
	exit(0);
}
void judgegameover()
{
	int j;
	while(p!=NULL)
	{
		if(p->x==bul.x&&p->y==bul.y)
			endgame();
		p=p->next;
	}
	p=head;
}
void createbullet()
{
	int j;
	srand(time(0));
	for(j=0;j<10;j++)
	{
    	bul.x=rand()%61+16;
		bul.y=4;
		bul.sta=0;
		pos(bul.x,bul.y);
    	printf("¡ö");
	}
}
void control()
{
		if(GetAsyncKeyState(VK_UP)&&head->y!=5)
		{
			s=1;
			tankmove();
		}
		else if(GetAsyncKeyState(VK_DOWN)&&head->y+2!=38)
		{
			s=2;
			tankmove();
		}
		else if(GetAsyncKeyState(VK_LEFT)&&head->x-2!=16)
		{
			s=3;
			tankmove();
		}
		else if(GetAsyncKeyState(VK_RIGHT)&&head->x+2!=84)
		{
			s=4;
			tankmove();
		}
}
void bulletmoveandsoonlive()
{
	int j;
	while(1)
	{
		key=kbhit();
		if(key==1)
		control();
		createbullet();
		for(j=5;j<=37;j++)
		{
			Sleep(50);
			bul.y++;
			system("cls");
			createmap();
			printtank();
			pos(bul.x,bul.y);
			printf("¡ö");
			control();
			judgegameover();
		}
	}
}
int judgescore()
{
	int j=0;
	for(p=head;j<2;j++,p=p->next)
	{
		if(p->x==bul.x&&p->y==bul.y){
			score++;
			p=head;
			return 1;}
		p=p->next;
	}
	p=head;
}
void bulletmoveandsoonscore()
{
	int j,js=0;
	while(1)
	{
		key=kbhit();
		if(key=1)
		control();
		createbullet();
		for(j=5;j<=37;j++)
		{
			Sleep(50);
			bul.y++;
			system("cls");
			createmap();
			printtank();
			pos(bul.x,bul.y);
			printf("¡ö");
			control();
			js=judgescore();
			if(js==1)
				break;
		}
	}
}
void hidecursor()
{
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void start()
{
	pos(20,20);
	printf("Zhaoye's game!");
	Sleep(100);
	pos(20,25);
	printf("Press any key to enter the game...");
	system("pause");
}
void gamelive()
{
	hidecursor();
	createmap();
	createtank();
	printtank();
	bulletmoveandsoonlive();
}
void gamescore()
{
	hidecursor();
	createmap();
	createtank();
	printtank();
	bulletmoveandsoonscore();
}
void gamedescription()
{
	system("cls");
	pos(20,20);
	printf("You have two choices:\n1.Live mood:Don't be hit by the bullet and try your best to live!\n2.Score mood:Try to get the gold and you will gain score!");
	pos(20,26);
	printf("Press any key to back to the main menu...");
	system("pause");
}
void enterandplay()
{
	int c;
	here:
	system("cls");
	pos(20,20);
	printf("Zhaoye's game!");
	pos(15,30);
	printf("Choose the mood you want!");
	pos(15,33);
	printf("1-Live mood 2-Score mood 3- Game description\n");
	pos(15,34);
	printf("Your choice:");
	pos(15,35);
	scanf("%d",&c);
	switch(c)
	{
		case 1:gamelive();break;
		case 2:gamescore();break;
		case 3:gamedescription();goto here;break;
		defluat:printf("So what do you want to do?");
	}
}
int main()
{
	system("mode con cols=130 lines=50");
	system("color F3");
	start();
	enterandplay();
}
