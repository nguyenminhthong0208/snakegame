#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void PrintBoard(int Board[50][50]){
    printf("\n\n");
    int i,j;
    for(i=0; i<50; i++){
            printf("\t\t");
            for (j= 0; j<50; j++){
                printf("%d",Board[i][j]);
            }
            printf("\n");
    }
}

void InitBoard(int Board[50][50], int level){
    int i,j;
    if(level == 1){
            for (i=0; i<50; i++){
                for (j=0; j<50; j++){
                    if(i==0||j==0||i==49||j==49||i==1|j==1||i==48||j==48){
                        Board[i][j]=1;
                    }
                    else
                    {
                        Board[i][j]=0;
                    }

                }
            }
    }
}
void InnitSnake (int SnakeX[400], int SnakeY[400]){
    SnakeX[0]=30;
    SnakeX[1]=31;
    SnakeX[2]=32;
    //
    SnakeY[0]=30;
    SnakeY[1]=30;
    SnakeY[2]=30;
}
void NewFood(int *x, int *y, int SnakeX[400], int SnakeY[400], int SnakeLenth){

    int found =0;
    int i;
    int a=0;
    int b=0;
    while(!found)
    {
        a = (rand()%49)+1;
        b = (rand()%49)+1;
        found = 1;
        for (i=0; i< SnakeLenth; i++)
        {
            if (SnakeX[i]==a && SnakeY[i]==b)
            {
                found = 0;
            }
        }

    }
    *x= a;
    *y= b;
}

void PrintCurrentState(int Board[50][50],int SnakeX[400],int SnakeY[400],int Snakelength, int FoodX,int FoodY){
    printf("\n\n");
    char screen[50][50];
    int i,j;
    for(i=0; i<50; i++)
    {
        for (j= 0; j<50; j++)
        {
            if(Board[i][j]==0 )
            {
                screen[i][j]=' ';
            }
            else
            {
                screen[i][j]='*';
            }
        }
    }
    for (i=0; i< Snakelength;i++)
    {
        if (i!= Snakelength-1)
        {
        screen[SnakeY[i]][SnakeX[i]] = '*';
        }
        else
        {
            screen[SnakeY[i]][SnakeX[i]] = '0';
        }
    }
    screen[FoodY][FoodX]= 'F';
    for (i=0;i<50;i++)
    {
        printf("\t");
        for (j=0;j<50;j++)
        {
            printf("%c",screen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\t\t\tScore: %d", Snakelength-3);

}
void GoUp(int Board[50][50],int SnakeX[400],int SnakeY[400],int *Snakelength, int *FoodX,int *FoodY)
{
    int i,j;
    if(SnakeX[(*Snakelength)-1]==*FoodX&& (SnakeY[(*Snakelength)-1]-1+50)%50==*FoodY)
    {
        SnakeX[*Snakelength]= *FoodX;
        SnakeY[*Snakelength]= *FoodY;
        (*Snakelength)++;

        NewFood(&(*FoodX),&(*FoodY),SnakeX, SnakeY,*Snakelength);

    }
    else
    {
        for(i= 0; i<*Snakelength-1;i++)
        {
            SnakeX[i]=SnakeX[i+1];
            SnakeY[i]=SnakeY[i+1];
        }
        SnakeY[(*Snakelength)-1]= (SnakeY[(*Snakelength)-1]-1+50)%50;
    }
}
void GoDown(int Board[50][50],int SnakeX[400],int SnakeY[400],int *Snakelength, int *FoodX,int *FoodY)
{
    int i,j;
    if(SnakeX[(*Snakelength)-1]==*FoodX&& (SnakeY[(*Snakelength)-1]+1+50)%50==*FoodY)
    {
        SnakeX[*Snakelength]= *FoodX;
        SnakeY[*Snakelength]= *FoodY;
        (*Snakelength)++;
        NewFood(&(*FoodX),&(*FoodY),SnakeX, SnakeY,*Snakelength);
    }
    else
    {
        for(i= 0; i<*Snakelength-1;i++)
        {
            SnakeX[i]=SnakeX[i+1];
            SnakeY[i]=SnakeY[i+1];
        }
        SnakeY[(*Snakelength)-1]= (SnakeY[(*Snakelength)-1]+1)%50;
    }
}
void GoLeft(int Board[50][50],int SnakeX[400],int SnakeY[400],int *Snakelength, int *FoodX,int *FoodY)
{
    int i,j;
    if(SnakeY[(*Snakelength)-1]==*FoodY&& (SnakeX[(*Snakelength)-1]-1+50)%50==*FoodX)
    {
        SnakeX[*Snakelength]= *FoodX;
        SnakeY[*Snakelength]= *FoodY;
        (*Snakelength)++;
        NewFood(&(*FoodX),&(*FoodY),SnakeX, SnakeY,*Snakelength);
    }
    else
    {
        for(i= 0; i<*Snakelength-1;i++)
        {
            SnakeX[i]=SnakeX[i+1];
            SnakeY[i]=SnakeY[i+1];
        }
        SnakeX[(*Snakelength)-1]= (SnakeX[(*Snakelength)-1]-1+50)%50;
    }
}
void GoRight(int Board[50][50],int SnakeX[400],int SnakeY[400],int *Snakelength, int *FoodX,int *FoodY)
{
    int i,j;
    if(SnakeY[(*Snakelength)-1]==*FoodY&& (SnakeX[(*Snakelength)-1]+1+50)%50== *FoodX)
    {
        SnakeX[*Snakelength]= *FoodX;
        SnakeY[*Snakelength]= *FoodY;
        (*Snakelength)++;
        NewFood(&(*FoodX),&(*FoodY),SnakeX, SnakeY,*Snakelength);
    }
    else
    {
        for(i= 0; i<*Snakelength-1;i++)
        {
            SnakeX[i]=SnakeX[i+1];
            SnakeY[i]=SnakeY[i+1];
        }
        SnakeX[(*Snakelength)-1]= (SnakeX[(*Snakelength)-1]+1)%50;
    }
}
int AbleToGoup(int SnakeX[400], int SnakeY[400], int Snakelength)
{
    if(SnakeX[Snakelength-1]==SnakeX[Snakelength-2]&& (SnakeY[Snakelength-1]-1)%50==SnakeY[Snakelength-2])
    {
        return 0;
    }
    return 1;
}
int AbleToDown(int SnakeX[400], int SnakeY[400], int Snakelength)
{
    if(SnakeX[Snakelength-1]==SnakeX[Snakelength-2]&& (SnakeY[Snakelength-1]+1)%50==SnakeY[Snakelength-2])
    {
        return 0;
    }
    return 1;
}

int AbleToLeft(int SnakeX[400], int SnakeY[400], int Snakelength)
{
    if((SnakeX[Snakelength-1]-1)%50==SnakeX[Snakelength-2]&& SnakeY[Snakelength-1]==SnakeY[Snakelength-2])
    {
        return 0;
    }
    return 1;
}
int AbleToRight(int SnakeX[400], int SnakeY[400], int Snakelength)
{
    if((SnakeX[Snakelength-1]+1)%50==SnakeX[Snakelength-2]&& SnakeY[Snakelength-1]==SnakeY[Snakelength-2])
    {
        return 0;
    }
    return 1;
}

int IsOver(int Board[50][50],int SnakeX[400], int SnakeY[400], int Snakelength, int Direction)
{
    int Screen[50][50];
    int i, j;
    for (i=0; i<50;i++)
    {
        for (j=0; j<50; j++)
        {
            if (Board[i][j]==1&& i!=1&&j!=1&&i!=48&&j!=48)
            {
                Screen[i][j]= 1;
            }
            else
            {
                Screen[i][j]=0;
            }
        }
    }
    for (i=0; i<Snakelength-1; i++)
    {
        Screen[SnakeY[i]][SnakeX[i]]=1;
    }
    int over = 0;
    if (Direction==UP)
    {
        int newx = SnakeX[Snakelength-1];
        int newy = (SnakeY[Snakelength-1]+49)%50;
        if (Screen[newx][newy]== 1)
            over = 1;
    }
    if(Direction==RIGHT)
    {
        int newx = (SnakeX[Snakelength-1]+51)%50;
        int newy = SnakeY[Snakelength-1];
        if (Screen[newx][newy]== 1)
            over = 1;
    }
    if (Direction==DOWN)
    {
        int newx = SnakeX[Snakelength-1];
        int newy = (SnakeY[Snakelength-1]+51)%50;
        if (Screen[newx][newy]== 1)
            over = 1;
    }
    if (Direction==LEFT)
    {
        int newx = (SnakeX[Snakelength-1]+49)%50;
        int newy = SnakeY[Snakelength-1];
        if (Screen[newx][newy]== 1)
            over = 1;
    }
    return over;
}
int main()
{

    char key[5];
    printf("\n\n\n\t\t\t Hello!\n");
    printf("\t\t ssssssss ss ss    ss ssss    ss   \n");
    printf("\t\t ss       ss ss    ss ss ss   ss    \n");
    printf("\t\t ss   sss ss ss    ss ss  ss  ss   \n");
    printf("\t\t ss    ss ss ss    ss ss   ss ss    \n");
    printf("\t\t ssssssss ss ssssssss ss    ssss    \n");
    printf("\t\t\t Welcome to Snake Game!\n");
    printf("\t\t\t (Enter 'Yes' or 'Y' to Begin the Game )!\n");
    printf("\t\t\t ");
    scanf("%s",&key);
    printf(key);
    while (strcmp("Yes",key) != 0||strcmp("Yes",key) != 0||strcmp("Y",key) != 0||strcmp("Y",key) != 0)
    //while(key == 'yes'|| key== 'y'|| key== 'Yes'|| key == 'Y' )
    {
    int Board[50][50];
    int SnakeX[200];
    int SnakeY[200];
    int FoodX= 8, FoodY=8;
    int snakelength =3;

    InitBoard(Board, 1);
    InnitSnake(SnakeX, SnakeY);
    PrintCurrentState(Board, SnakeX,SnakeY,snakelength,32,29);
    int pre = RIGHT;
    int a = RIGHT;

    while(!IsOver(Board, SnakeX,SnakeY,snakelength,a))
    {

        do
        {
            int q;
            system("cls");

            if (a== RIGHT){
                GoRight(Board, SnakeX,SnakeY,&snakelength,&FoodX,&FoodY);
            }
            else if(a== LEFT)
            {
                GoLeft(Board, SnakeX,SnakeY,&snakelength,&FoodX,&FoodY);
            }
            else if (a== UP)
            {
                GoUp(Board, SnakeX,SnakeY,&snakelength,&FoodX,&FoodY);
            }
            else if( a== DOWN)
            {
                GoDown(Board, SnakeX,SnakeY,&snakelength,&FoodX,&FoodY);
            }
            PrintCurrentState(Board, SnakeX,SnakeY,snakelength,FoodX,FoodY);
            for(q=0;q<=10000000;q++);
            if(IsOver(Board, SnakeX,SnakeY,snakelength,a))
            {
                break;
            }
        }
        while(!kbhit());
        int q;
        for(q=0; q<=10000000;q++);
        if(IsOver(Board, SnakeX,SnakeY,snakelength,a))
        {
            break;
        }
        int prest = a;
        a= getch();
        if ((a== RIGHT&& !AbleToRight(SnakeX,SnakeY,snakelength))||(a== UP&& !AbleToGoup(SnakeX,SnakeY,snakelength))||(a== DOWN&& !AbleToDown(SnakeX,SnakeY,snakelength))||(a== LEFT&& !AbleToLeft(SnakeX,SnakeY,snakelength)))
        {
           a = prest;
        }
    }


    system("cls");
    printf("\n\n\n");
    printf("\t\t                                    \n");
    printf("\t\t $$$$$$$$ $$$$$$$$$ $$$$$$$$$$$ $$$$$\n");
    printf("\t\t $$    $$ $$     $$ $$   $   $$ $$   \n");
    printf("\t\t $$   $$$ $$$$$$$$$ $$   $   $$ $$$$$\n");
    printf("\t\t $$    $$ $$     $$ $$       $$ $$   \n");
    printf("\t\t $$$$$$$$ $$     $$ $$       $$ $$$$$\n");
    printf("\t\t                                     \n");
    printf("\t\t $$$$$$$$$ $$$$  $$$ $$$$$ $$$$$$$$$ \n");
    printf("\t\t $$     $$   $$  $$  $$    $$     $$ \n");
    printf("\t\t $$     $$   $$  $$  $$$$$ $$$$$$$$$ \n");
    printf("\t\t $$     $$   $$  $$  $$    $$     $$ \n");
    printf("\t\t $$$$$$$$$   _$$$  _ $$$$$ $$     $$$\n");
    printf("\t\t                                     \n");
    printf("\t\t         $$               $$         \n");
    printf("\t\t       $$$$$   $$$$$$$   $$$$$       \n");
    printf("\t\t          $$$$$$$$$$$$$$$$$          \n");
    printf("\t\t            $$$$$$$$$$$$$            \n");
    printf("\t\t            $$$$$$$$$$$$$            \n");
    printf("\t\t            $$   $$$   $$            \n");
    printf("\t\t            $$$$$$$$$$$$$            \n");
    printf("\t\t             $$$$$$$$$$$             \n");
    printf("\t\t         $$$$$  $$$$$  $$$$$         \n");
    printf("\t\t         $$$$           $$$$         \n");
    printf("\t\t           $$           $$           \n");
    printf("\t\t                                     \n");
    printf("\n\n\t\t\t Your Score is: %d\n\n", snakelength-3);


    printf("Enter 'Yes' or 'Y' to continue, enter 'No' or 'N' to quit: ");
    scanf("%s",&key);
    }

    return 0;
}
