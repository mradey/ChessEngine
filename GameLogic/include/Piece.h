#include <string>
#include <bitset>
using namespace std;

#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED
class Board;
class Piece {
    private: 
        bool isWhite;
        bool isOnBoard;
        bitset<64> validMoves;
        int convertChessSquareToBitSetIdx(int rank, int col) {
            return 8 * (rank - 1) + (col - 1);
        }
    public:
        Piece(bool iw);
        bool getIsWhite();
        bool getIsOnBoard();
        bitset<64> getValidMoves();
        void setValidMove(int rank, int col);
        bool isValidMove(int rank, int col);
        void noValidMoves();
        virtual string toString();
        virtual void findValidMoves(Board * board);


};

#endif