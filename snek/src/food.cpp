#include "food.h"

food::food()
{
    genfood();
}
void food::genfood()
{
    srand(time(0));
    pos.X= (rand() % (width-2))+ 1;
    pos.Y= (rand() %(height -2))+ 1;
}
COORD food::getpos()
{
    return pos;
}
