#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

int main()
{
    printf("Hello world!\n");
    return 0;
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
