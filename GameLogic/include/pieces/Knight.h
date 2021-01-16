#include "../Piece.h"
#ifndef KNIGHT_INCLUDED
#define KNIGHT_INCLUDED

class Board;
class Knight : public Piece {
    public:
        Knight(bool iw, square square, pieceId pieceId, pieceType type); 
        char toChar();
        std::vector<square> findValidMoves(Board * board);
};

#endif