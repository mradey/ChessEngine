#include <iostream>
#include "./Rook.h"
#include "./Bishop.h"

using namespace std;
#ifndef QUEEN_INCLUDED
#define QUEEN_INCLUDED

class Board;
class Queen : public Rook, public Bishop {
    public:
        Queen(bool iw, int file, int rank);
        string toString();
        int findValidMoves(Board * board);
};

#endif