#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>

class snake
{
    private:
     COORD pos;
     int len;
     int vel;
     int direction;

    public:
        snake(COORD pos,int vel);
        void changedir(char dir);
        void movesnek();
        COORD getpos();

        bool eaten(COORD foodpos);

        void grow();
        bool snakecollided();
};

#endif // SNAKE_H
