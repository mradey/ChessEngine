#include <vector>
#include "../Piece.h"
#ifndef PAWN_INCLUDED
#define PAWN_INCLUDED

class Board;
class Pawn : public Piece {
    private:
        const int direction;
    public:
        Pawn(bool iw, square square, pieceId pieceId, pieceType type);
        bool isOnEnPassantSquare() {
            return getIsWhite() ? getSquare().y == 5 : getSquare().y == 4;
        }
        bool canEnPassant(Board * board, square currentSquare);
        std::string toString();
        std::vector<square> findValidMoves(Board * board);
        std::vector<square> getAdvanceableSquares(Board * board, square currentSquare);
        std::vector<square> getAttackingSquares(Board * board, square currentSquare);
};

#endif