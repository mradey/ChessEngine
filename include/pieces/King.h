#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef KING_INCLUDED
#define KING_INCLUDED

class Board;
class King : public Piece {
    public:
        King(bool isWhite);
        string toString();
        void findValidMoves(Board * board);
};

#endif