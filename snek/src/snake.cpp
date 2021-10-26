#include "snake.h"
#include"food.h"
snake::snake(COORD pos,int vel)
{
    this->pos=pos;
    this->vel=vel;
    len=1;
    direction='n';
}
void snake::changedir(char dir)
{
    direction=dir;
}
void snake::movesnek()
{
    switch(direction)
    {
        case 'w': pos.Y -= vel;
        break;
        case 'a': pos.X -= vel;
        break;
        case 's': pos.Y += vel;
        break;
        case 'd': pos.X += vel;
        break;
    }
}

COORD snake :: getpos()
{
    return pos;
}

bool snake::eaten(COORD foodpos)
{
    if(foodpos.X==pos.X && foodpos.Y==pos.Y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void snake::grow()
{
    len++;
}

bool snake::snakecollided()
{
    if(pos.X<1 || pos.X>=width-1|| pos.Y<1 || pos.Y>=height-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
