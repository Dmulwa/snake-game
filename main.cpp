#include <iostream>

#include <conio.h>
#include <ctime>

#include "food.h"
#include "snake.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;
snake s({WIDTH/2, HEIGHT/2}, 1);
food Food;

void board(){
    COORD snake_pos = s.get_pos();
    COORD food_pos = Food.get_pos();

    for(int i =0;i<HEIGHT; i++){
            cout<<"\t\t\t#";

            for(int j=0;j<WIDTH;j++){
                    if(i==0 || i == HEIGHT-1)cout<<"#";
                    else if(i== snake_pos.Y && j==snake_pos.X) cout<<'0';
                    else if(i==food_pos.Y && j== food_pos.X) cout<<'*';
                    else cout<<" ";
            }
            cout<<"#\n";
}


}
int main()
{
    srand(time(NULL));
    bool gameover = false;
    while(!gameover){
        board();
        //capture key strokes
        if(kbhit){
            switch(getch()){

                case 'w': s.change_dir('u'); break;

                case 's': s.change_dir('d'); break;

                case 'a': s.change_dir('l'); break;

                case 'd': s.change_dir('r'); break;


            }

        }
        s.move_snake();
        if(s.eaten(Food.get_pos())){
            Food.gen_food();
            s.grow();
        }
        if(s.collided()){
            gameover =true;}

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0, 0});
    }

    return 0;
}
