#include <windows.h>
#ifndef SNAKE_H
#define SNAKE_H

#define WIDTH 50
#define HEIGHT 25

class snake
{
    private:
        int len;
        int vel;
        COORD pos;
        char direction;

    public:
        snake(COORD pos, int vel);
        void change_dir(char dir);
        void move_snake();
        COORD get_pos();
        bool eaten(COORD food_pos);
        void grow();

        bool collided();



};

#endif // SNAKE_H
