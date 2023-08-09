#include "snake.h"

snake::snake(COORD pos, int vel)
{
    //ctor
    this->pos = pos;
    this->vel = vel;
    len = 4;
    direction ='n';
}

void snake::change_dir(char dir){
    direction = dir;
}

void snake::move_snake(){
    switch(direction){
        case 'u': pos.Y -=vel; break;

        case 'd': pos.Y +=vel; break;

        case 'r': pos.X +=vel; break;

        case 'l': pos.X -=vel; break;


    }
}

COORD snake::get_pos(){
    return pos;
    }

bool snake::eaten(COORD food_pos){
    if(food_pos.X == pos.X && food_pos.Y== pos.Y){return true;}
    else return false;
}

void snake::grow(){len++;}

bool snake::collided(){
    if(pos.X<1 || pos.X > WIDTH || pos.Y <1 || pos.Y > HEIGHT) return true;
    else return false;
}
