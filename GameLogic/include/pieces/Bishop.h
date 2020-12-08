#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef BISHOP_INCLUDED
#define BISHOP_INCLUDED

class Board;
class Bishop : public Piece {
    public:
        Bishop(bool isWhite);
        string toString();
        void findValidMoves(Board * board);
};

#endif