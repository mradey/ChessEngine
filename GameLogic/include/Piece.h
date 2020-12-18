#include <string>
#include <bitset>
#include "SquareStruct.h"
#include <vector> 
#include <array>
#include <string>

#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED
class Board;
class Piece {
    private: 
        bool isWhite;
        bool isOnBoard;
        int file;
        int rank;
        bool hasMoved = false;
        std::vector<std::string> validMovesList;
        std::array<std::string, 64> arr = {
            "H1", "G1", "F1", "E1", "D1", "C1", "B1", "A1",
            "H2", "G2", "F2", "E2", "D2", "C2", "B2", "A2",
            "H3", "G3", "F3", "E3", "D3", "C3", "B3", "A3",
            "H4", "G4", "F4", "E4", "D4", "C4", "B4", "A4",
            "H5", "G5", "F5", "E5", "D5", "C5", "B5", "A5",
            "H6", "G6", "F6", "E6", "D6", "C6", "B6", "A6",
            "H7", "G7", "F7", "E7", "D7", "C7", "B7", "A7",
            "H8", "G8", "F8", "E8", "D8", "C8", "B8", "A8"
        };
        //bitset index = A1 = 7 E5=35
        /*
        8 0 0000 000
        7 0 0000 000
        6 0 0000 000
        5 0 000E5000
        4 0 0000 000
        3 0 0000 000
        2 0 0000 00
        1 A10000 000
        */
        std::bitset<64> validMoves;
        int convertChessSquareToBitSetIdx(int rank, int col) {
            return 8 * (rank) + (7-col);
        }
    public:
        Piece(bool iw, int file, int rank);
        const int RIGHT =  1;
        const int UP    =  1;
        const int LEFT  = -1;
        const int DOWN  = -1;
        bool getIsWhite();
        bool getIsOnBoard();
        bool isValidMove(square square);
        bool isSameColor(Piece * piece);
        occupation squareIsAttackable(Board * board, square square);
        void setValidMove(square square);
        void noValidMoves();
        void setNewSquare(square square);
        void pieceMoved();
        square getSquare();
        std::bitset<64> getValidMoves();
        std::string getValidMovesAsString();
        virtual std::string toString();
        virtual int findValidMoves(Board * board);

};

#endif