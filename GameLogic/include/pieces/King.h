#include "../Piece.h"
#ifndef KING_INCLUDED
#define KING_INCLUDED

class Board;
class King : public Piece {
    private:
        const short queenside = 2;
        const short kingside = 6;
    public:
        King(bool iw, square square);
        std::string toString();
        std::vector<square> findValidMoves(Board * board);
        std::vector<square> checkRank(Board * board, square square);
        std::vector<square> checkSurrondingSqures(Board * board, square square);
        std::vector<square> castlingEligible(Board * board);
        square checkSquaresBetweenKingAndRook(Board * board, Piece * rook, int direction);
        
};

#endif