#include "../Piece.h"
#ifndef BISHOP_INCLUDED
#define BISHOP_INCLUDED

class Board;
class Bishop : virtual public Piece {
    public:
        Bishop(bool iw, square square, pieceId pieceId, pieceType type);
        char toChar();
        std::vector<square> findValidMoves(Board * board);
        std::vector<square> movesOnDiag(int xDir, int yDir, square square, Board * board);
};

#endif