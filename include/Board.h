#include <string>
#include <iostream>
using namespace std;

#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED
class Square;
class Board {
    private:
        Square * board[8][8];
        enum columns { A, B, C, D, E, F, G, H };

    public:
        Board();
        void resetBoard();
        string toString();
        void printBoard();
};
#endif