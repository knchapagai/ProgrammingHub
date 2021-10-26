#include <iostream>
#include "snake.h"
#include "food.h"
#include<conio.h>
using namespace std;
snake snake({width/2,height/2},1);
food food;
int x=10,y=10;
void board()
{
    COORD snakepos=snake.getpos();
    COORD foodpos=food.getpos();
    cout<<"\n\n\n\n\n\n";
    for (int i=0;i<height;i++)
    {
        cout<<"\t\t\t#";
        for(int j=0;j<width-1;j++)
        {
            if(i==0||i==height-1)
            {
                cout<<"#";
            }
            else if(i==snakepos.Y && j+1==snakepos.X)
            {
                cout<<"D";
            }
            else if(i==foodpos.Y && j+1==foodpos.X)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"#\n";
    }
};
int main()
{
    bool gameover = false;

    while(!gameover)
   {
       board();
       if(GetAsyncKeyState('W'))
       {
            snake.changedir('w');
        }
      else  if(GetAsyncKeyState('A'))
       {
            snake.changedir('a');
        }
        else if(GetAsyncKeyState('S'))
       {
            snake.changedir('s');
        }
        else if(GetAsyncKeyState('D'))
       {
            snake.changedir('d');
        }
           snake.movesnek();

         if(snake.eaten(food.getpos()))
         {
             food.genfood();
             snake.grow();
         }
         if(snake.snakecollided())
         {
             cout<<"GAME OVER";
             gameover = true;

         }
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
   }
   return 0;
}
