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
            bool isWhitePiece = true;
            board[7][A] = new Square(7,A,new Rook(isWhitePiece));
            board[7][B] = new Square(7,B,new Knight(isWhitePiece));
            board[7][C] = new Square(7,C,new Bishop(isWhitePiece));
            board[7][D] = new Square(7,D,new Queen(isWhitePiece));
            board[7][E] = new Square(7,E,new King(isWhitePiece));
            board[7][F] = new Square(7,F,new Bishop(isWhitePiece));
            board[7][G] = new Square(7,G,new Knight(isWhitePiece));
            board[7][H] = new Square(7,H,new Rook(isWhitePiece));

            //white pawns
            board[6][A] = new Square(6,A,new Pawn(isWhitePiece));
            board[6][B] = new Square(6,B,new Pawn(isWhitePiece));
            board[6][C] = new Square(6,C,new Pawn(isWhitePiece));
            board[6][D] = new Square(6,D,new Pawn(isWhitePiece));
            board[6][E] = new Square(6,E,new Pawn(isWhitePiece));
            board[6][F] = new Square(6,F,new Pawn(isWhitePiece));
            board[6][G] = new Square(6,G,new Pawn(isWhitePiece));
            board[6][H] = new Square(6,H,new Pawn(isWhitePiece));

            //black pieces
            isWhitePiece = false;
            board[0][A] = new Square(0,A,new Rook(isWhitePiece));
            board[0][B] = new Square(0,B,new Knight(isWhitePiece));
            board[0][C] = new Square(0,C,new Bishop(isWhitePiece));
            board[0][D] = new Square(0,D,new Queen(isWhitePiece));
            board[0][E] = new Square(0,E,new King(isWhitePiece));
            board[0][F] = new Square(0,F,new Bishop(isWhitePiece));
            board[0][G] = new Square(0,G,new Knight(isWhitePiece));
            board[0][H] = new Square(0,H,new Rook(isWhitePiece));

            //black pawns
            board[1][A] = new Square(1,A,new Pawn(isWhitePiece));
            board[1][B] = new Square(1,B,new Pawn(isWhitePiece));
            board[1][C] = new Square(1,C,new Pawn(isWhitePiece));
            board[1][D] = new Square(1,D,new Pawn(isWhitePiece));
            board[1][E] = new Square(1,E,new Pawn(isWhitePiece));
            board[1][F] = new Square(1,F,new Pawn(isWhitePiece));
            board[1][G] = new Square(1,G,new Pawn(isWhitePiece));
            board[1][H] = new Square(1,H,new Pawn(isWhitePiece));

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