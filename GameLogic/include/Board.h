#include <string>
#include <iostream>
#include "SquareStruct.h"
using namespace std;

#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED
class Square;
class Piece;
class Move;
class Board {
    private:
        int ADJ = 1;
        Piece * board[8][8];
        enum columns { A, B, C, D, E, F, G, H };
        bool whiteMove = true;
        const char * jsonTemplate = 
                "{\n"  
                    "\t\t\"piece\":\"%s\",\n"
                    "\t\t\"color\":\"%s\",\n"
                    "\t\t\"validMoves\":\"%s\"\n"
                "\t}\n";
    public:
        Board();
        void resetBoard();
        void resetBoard1();
        string toString();
        void printBoardWhiteTurn();
        void printBoardBlackTurn();
        void movePiece(Move * move);
        void boardToJson(ofstream& file);
        Piece * getPiece(square square);
        bool isOnBoard(square square);
        std::string getPieceJSON(Piece * piece);

};
#endif