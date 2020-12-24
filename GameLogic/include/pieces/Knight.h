#include "../Piece.h"
#ifndef KNIGHT_INCLUDED
#define KNIGHT_INCLUDED

class Board;
class Knight : public Piece {
    public:
        Knight(bool iw, square square); 
        std::string toString();
        std::vector<square> findValidMoves(Board * board);
};

#endif