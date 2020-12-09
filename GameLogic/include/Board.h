#include <string>
#include <iostream>
using namespace std;

#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED
class Square;
class Piece;
class Move;
class Board {
    private:
        int ADJ = 1;
        Square * board[8][8];
        enum columns { A, B, C, D, E, F, G, H };
        bool whiteMove = true;

    public:
        Board();
        void resetBoard();
        string toString();
        void printBoardWhiteTurn();
        void printBoardBlackTurn();
        void movePiece(Move * move);
        void boardToJson(ofstream& file);
};
#endif