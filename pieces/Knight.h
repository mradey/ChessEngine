#include <iostream>
#include "../Board.h"
using namespace std;
#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED
class Knight : public Piece {
    public:
        Knight(bool isWhite) : Piece(isWhite) {}
        string toString() {
            return "N";
        }

        void findValidMoves(Board board) {

        }
};
#endif