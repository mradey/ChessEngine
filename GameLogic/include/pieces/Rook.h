#include "../Piece.h"
#ifndef ROOK_INCLUDED
#define ROOK_INCLUDED

class Board;
class Rook : virtual public Piece {
    public:
        Rook(bool iw, square square, pieceId pieceId, pieceType type);
        std::string toString();
        std::vector<square> findValidMoves(Board * board);
        std::vector<square> movesOnLine(int xDir, int yDir, square currentSquare, Board * board);
};

#endif