#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef QUEEN_INCLUDED
#define QUEEN_INCLUDED

class Board;
class Queen : public Piece {
    public:
        Queen(bool isWhite);
        string toString();
        void findValidMoves(Board * board);
};

#endif