#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef BISHOP_INCLUDED
#define BISHOP_INCLUDED

class Board;
class Bishop : virtual public Piece {
    public:
        Bishop(bool iw, int file, int rank);
        string toString();
        int findValidMoves(Board * board);
        int movesOnDiag(int xDir, int yDir, square square, Board * board);
};

#endif