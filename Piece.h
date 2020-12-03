#include <string>
#include <bitset>
#include "./Board.h"
using namespace std;

#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED
class Piece {
    private: 
        bool isWhite;
        bool isOnBoard;
        bitset<64> validMoves;
        int convertChessSquareToBitSetIdx(int rank, int col) {
            return 8 * (rank - 1) + (col - 1);
        }
    public:
        Piece(bool iw) {
            isWhite = iw;
            isOnBoard = true;
        }

        bool getIsWhite() {
            return isWhite;
        };
        
        bool getIsOnBoard() {
            return isOnBoard;
        };

        bitset<64> getValidMoves() {
            return validMoves;
        }

        /*A1 = 0, B1 = 1, ... H1 = 7
          A2 = 8, B2 = 9, ... H2 = 15
        */
        void setValidMove(int rank, int col) { 
            validMoves.set(convertChessSquareToBitSetIdx(rank, col));
        }

        bool isValidMove(int rank, int col) {
            return validMoves.test(convertChessSquareToBitSetIdx(rank, col));
        }
        
        void noValidMoves() {
            validMoves.reset();
        }
        virtual string toString() {
            return "piece";
        }
        
        virtual void findValidMoves(Board board) {}


};

#endif