#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef ROOK_INCLUDED
#define ROOK_INCLUDED

class Board;
class Rook : public Piece {
    public:
        Rook(bool isWhite);
        string toString();
        void findValidMoves(Board * board);
};

#endif