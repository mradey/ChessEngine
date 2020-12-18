#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef ROOK_INCLUDED
#define ROOK_INCLUDED

class Board;
class Rook : virtual public Piece {
    public:
        Rook(bool iw, int file, int rank);
        string toString();
        int findValidMoves(Board * board);
        int movesOnLine(int xDir, int yDir, square square, Board * board);
};

#endif