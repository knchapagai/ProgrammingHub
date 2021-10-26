#ifndef FOOD_H
#define FOOD_H
#include<windows.h>
#include<time.h>
#include<stdlib.h>
const int height=30,width=60;
class food
{

    private:
        COORD pos;
    public:
        food();
        void genfood();
        COORD getpos();
};

#endif // FOOD_H
