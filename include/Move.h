#include <string>
#include <iostream>
using namespace std;

#ifndef MOVE_INCLUDED
#define MOVE_INCLUDED
struct square
{
    int x;
    int y;
};
class Move {
    private:
        square s1;
        square s2;

    public:
        Move(char * inp) {
            s1.x = inp[0] - 'a';
            s1.y = inp[1] - '1';
            s2.x = inp[3] - 'a';
            s2.y = inp[4] - '1';
        }
        square getBeginSquare(){
            return s1;
        }
        square getEndSquare(){
            return s2;
        }
};
#endif