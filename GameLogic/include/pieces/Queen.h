#include "./Rook.h"
#include "./Bishop.h"

#ifndef QUEEN_INCLUDED
#define QUEEN_INCLUDED

class Board;
class Queen : public Rook, public Bishop {
    public:
        Queen(bbool iw, square square, pieceId pieceId, pieceType type);
        std::string toString();
        std::vector<square> findValidMoves(Board * board);
};

#endif