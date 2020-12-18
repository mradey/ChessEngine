#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef PAWN_INCLUDED
#define PAWN_INCLUDED

class Board;
class Pawn : public Piece {
    private:
        bool canEnPassant;
    public:
        Pawn(bool iw, int file, int rank);
        string toString();
        int findValidMoves(Board * board);
        bool hasNotMoved();
        int getAdvanceableSquares(Board * board, square square);
        int getAttackingSquares(Board * board, square square);
};

#endif