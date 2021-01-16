#include "./Rook.h"
#include "./Bishop.h"

#ifndef QUEEN_INCLUDED
#define QUEEN_INCLUDED

class Board;
class Queen : public Rook, public Bishop {
    public:
        Queen(bool iw, square square, pieceId pieceId, pieceType type);
        char toChar();
        std::vector<square> findValidMoves(Board * board);
};

#endif