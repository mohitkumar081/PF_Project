#include<stdio.h>
#include<string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
void instructions()
{
	printf("\t\t\t\t\t\t\tInstructions");
	printf("\n\t\t\t\t\t\t\t______________");
	printf("\n\n\n\n");
	printf("\n\t1. Avoid hurdles by Pressing 'S'");
	printf("\n\t2. Press S to Jump ");
	printf("\npress any key to start the game");
	getch();
}
struct Player
{
	char Playername[100];
	int Playerscore;
};
struct Player score[5];
//Global variable use throughtout program

int time_ = 0, i, a=1, speed = 0;

   /*int i,j;
   int x;  //for positions
   int time=0;//control time;
   int speed=0;//speed of dinosaur and 
   int a;// for animation of game*/


void gotoxy(int a,int b)
{
	HANDLE Cons_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = a;
    pos.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void clrscreen(){ 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD written;
    FillConsoleOutputCharacter(hConsole, ' ', 100*100, coord, &written);
    SetConsoleCursorPosition(hConsole, coord);
}
void pause_ms(unsigned int mSec)
{
    clock_t goal = mSec + clock();
    while (goal > clock());
}
void initialGameScore() 
{
    gotoxy(42,6);
    printf("S to JUMP");
    gotoxy(1,5);
    for(i=0;i<115;i++)
    {
    printf(">");  
    }
    gotoxy(80,1);
    printf("SCORE : 0");
}
void printDino()  
{
	
    gotoxy(2,15-time_);
    printf("                 ");
    gotoxy(2,16-time_);
    printf("         млпллллм");
    gotoxy(2,17-time_);
    printf("         лллллллл");
    gotoxy(2,18-time_);
    printf("         лллллппп");
    gotoxy(2,19-time_);
    printf(" л      мллллппп ");
    gotoxy(2,20-time_);
    printf(" ллм  мллллллммм ");
    gotoxy(2,21-time_);
    printf(" пллллллллллл  п ");
    gotoxy(2,22-time_);
    printf("   плллллллп     ");
    gotoxy(2,23-time_);

    if(a==1)
    {
    printf("    пллп  ппп");
    gotoxy(2,24-time_);
    printf("      лм");
    a=2;
    }
    else if(a==2)
    {
    printf("     плм пл");
    gotoxy(2,24-time_);
        printf("          лм");
    a=1;
    }

    gotoxy(2,25-time_);
    printf("                ");

    gotoxy(0,26);
    for(i=0;i<115;i++)
    {
    printf("п");
    }
}

	
void moveDino(int *jump, int jumpLvl)	
{
	if((*jump)<jumpLvl)//ascending
		time_++;
	else
		time_--;
	(*jump)++;
//	printf("%d %d", *jump, time_);

//    if (*jump == 0)
//    time_ = 0;
//    else if (*jump == 2)
//    time_--;
//    else
//    time_++;
//    printDino();
//    jump_();
//    if (*jump > 0)
//    (*jump)++;
//
//    if (*jump == 21)
//    *jump = 0;
}
void drawObs(int time)
{
	int i;
	for(i=0;i<2;i++)
	{
		gotoxy(80-time,24-i);//80 screen width for display output
		
		printf(" лммм ");		
	}	
}

void chooseMode(int* mode)
{
	printf("Choose Mode:\n 1. Easy\n2. Hard\nEnter Choice: ");
	scanf("%d", mode);
}
int main()

{
	int jump=0, click=0,spClick=0, FPS=30, jumpLevel=12, obsT=0,score=0, time2=0, time3=0,time4=0;
	int obs1Reach=0,obs2Reach=0, Lifes=3, lifeDeduct = 0, mode = 1;
	
	instructions();
	
	//initialGameScore();
	chooseMode(&mode);
	
	while(1){
		if(Lifes>0)
		{
			score++;
			gotoxy(101,1);
			printf("SCORE: %d", score);
			gotoxy(71,1);
			printf("Life: %d", Lifes);
			time2%=80;//set value of time 
			time3%=80;
			time4%=80;
			time2++;
			
		if(mode==1)
		{
			if(time2>40)
				obs1Reach = 1;
			if(obs1Reach)
				time3++;
			if(time2==79 || time3==79)
				lifeDeduct = 0;
			if(((time2>65 && time2<79) || (time3>65 && time3<79)) && jump<4)
			
			{
				if(!lifeDeduct)
					Lifes--;
				lifeDeduct = 1;
			}
			
			drawObs(time2);
			if(obs1Reach)
				drawObs(time3);
	}
	
	else if(mode==2)
	{
		FPS = 45;
		if(time2>26)
			obs1Reach = 1;
		if(obs1Reach)
			time3++;
		if(time3>26)
			obs2Reach = 1;
		if(obs2Reach)
			time4++;
		if(time2==79 || time3==79 || time4==79)
			lifeDeduct = 0;
		if(((time2>68 && time2<79) || (time3>68 && time3<79)  || (time4>68 && time4<79)) && jump<4){
			if(!lifeDeduct)
				Lifes--;
			lifeDeduct = 1;
		}
		drawObs(time2);
		if(obs1Reach)
			drawObs(time3);
		if(obs2Reach)
			drawObs(time4);
	}
		printDino();
		if(kbhit()){
	        char c = getch();
	        if(c=='s' || c=='S')
	        	click=1;
	    }
	    if(click){
	        moveDino(&jump, jumpLevel);
	    }
	
		//obsT%=55;
		//obsT++;
	    if(jump==jumpLevel*2){
	    	click=0;
	    	jump=0;
		}
	    clrscreen();
	    pause_ms(1000/FPS);
	}
	else{
		gotoxy(57,20);
		printf("Game Over!\n");
		gotoxy(54,21);
		printf("Your Score is %d\n", score);
		gotoxy(52,22);
		printf("Press Space To Restart");
		if(kbhit()){
	        char c = getch();
	        if(c==32)
	        	spClick=1;
	    }
		if(spClick){
			chooseMode(&mode);
			printf("%d: \n",mode);
			if(mode==1)
				FPS = 30;
			else
				FPS = 45;
			Lifes = 3;
			score = 0;
			time2 = 0;
			time3 = 0;
			time4 = 0;
			spClick=0;
			obs1Reach = 0;
			obs2Reach = 0;
		}

	}
	 
}
	
}

