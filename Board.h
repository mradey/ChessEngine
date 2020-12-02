#include "./Square.h"
#include "./pieces/King.h"
#include "./pieces/Queen.h"
#include "./pieces/Bishop.h"
#include "./pieces/Knight.h"
#include "./pieces/Rook.h"
#include "./pieces/Pawn.h"
#include <string>
#include <iostream>
using namespace std;
class Board {
    private:
        Square * board[8][8];
    public:
        Board() {
            resetBoard();
        }

        enum columns { A, B, C, D, E, F, G, H };

        void resetBoard() {
            //white pieces
            bool isWhite = true;
            board[7][A] = new Square(7,A,new Rook(isWhite));
            board[7][B] = new Square(7,B,new Knight(isWhite));
            board[7][C] = new Square(7,C,new Bishop(isWhite));
            board[7][D] = new Square(7,D,new Queen(isWhite));
            board[7][E] = new Square(7,E,new King(isWhite));
            board[7][F] = new Square(7,F,new Bishop(isWhite));
            board[7][G] = new Square(7,G,new Knight(isWhite));
            board[7][H] = new Square(7,H,new Rook(isWhite));

            //white pawns
            board[6][A] = new Square(6,A,new Pawn(isWhite));
            board[6][B] = new Square(6,B,new Pawn(isWhite));
            board[6][C] = new Square(6,C,new Pawn(isWhite));
            board[6][D] = new Square(6,D,new Pawn(isWhite));
            board[6][E] = new Square(6,E,new Pawn(isWhite));
            board[6][F] = new Square(6,F,new Pawn(isWhite));
            board[6][G] = new Square(6,G,new Pawn(isWhite));
            board[6][H] = new Square(6,H,new Pawn(isWhite));

            //black pieces
            bool isWhite = false;
            board[0][A] = new Square(0,A,new Rook(isWhite));
            board[0][B] = new Square(0,B,new Knight(isWhite));
            board[0][C] = new Square(0,C,new Bishop(isWhite));
            board[0][D] = new Square(0,D,new Queen(isWhite));
            board[0][E] = new Square(0,E,new King(isWhite));
            board[0][F] = new Square(0,F,new Bishop(isWhite));
            board[0][G] = new Square(0,G,new Knight(isWhite));
            board[0][H] = new Square(0,H,new Rook(isWhite));

            //black pawns
            board[1][A] = new Square(1,A,new Pawn(isWhite));
            board[1][B] = new Square(1,B,new Pawn(isWhite));
            board[1][C] = new Square(1,C,new Pawn(isWhite));
            board[1][D] = new Square(1,D,new Pawn(isWhite));
            board[1][E] = new Square(1,E,new Pawn(isWhite));
            board[1][F] = new Square(1,F,new Pawn(isWhite));
            board[1][G] = new Square(1,G,new Pawn(isWhite));
            board[1][H] = new Square(1,H,new Pawn(isWhite));

            //rest of squares have no piece
            for(int i=2; i < 6; i++){
                for(int j=0; j<8; j++) {
                    board[i][j] = new Square(i, j, NULL);
                }
            }
            
        }

        string toString() {
            for(int i = 0; i < 8; i++) {
                cout << "\n---------------\n";
                for(int j = 0; j < 8; j++) {
                    Square square = * board[i][j];
                    Piece * p = square.getPiece();
                    if(p != NULL) cout << "|" << p->toString();
                    else cout << "| ";
                }
            }
            return "";
        }
};