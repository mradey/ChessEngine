#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef PAWN_INCLUDED
#define PAWN_INCLUDED

class Board;
class Pawn : public Piece {
    public:
        Pawn(bool isWhite);
        string toString();
        void findValidMoves(Board * board);
};

#endif