#include <iostream>
#include "../Piece.h"
using namespace std;
#ifndef KNIGHT_INCLUDED
#define KNIGHT_INCLUDED

class Board;
class Knight : public Piece {
    private:
        bool white;
    public:
        Knight(bool iw, int file, int rank); 
        string toString();
        int findValidMoves(Board * board);
        bool whiteBool();
};

#endif