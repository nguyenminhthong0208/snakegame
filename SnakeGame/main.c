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
