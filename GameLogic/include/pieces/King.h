#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef KING_INCLUDED
#define KING_INCLUDED

class Board;
class King : public Piece {
    private:
        bool hasMoved = false;
    public:
        King(bool iw, int file, int rank);
        string toString();
        int findValidMoves(Board * board);
};

#endif