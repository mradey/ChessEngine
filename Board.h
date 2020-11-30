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
        void resetBoard() {
            //white pieces
            board[7][0] = new Square(7,0,new Rook(true));
            board[7][1] = new Square(7,1,new Knight(true));
            board[7][2] = new Square(7,2,new Bishop(true));
            board[7][3] = new Square(7,3,new Queen(true));
            board[7][4] = new Square(7,4,new King(true));
            board[7][5] = new Square(7,5,new Bishop(true));
            board[7][6] = new Square(7,6,new Knight(true));
            board[7][7] = new Square(7,7,new Rook(true));

            //white pawns
            board[6][0] = new Square(6,0,new Pawn(true));
            board[6][1] = new Square(6,1,new Pawn(true));
            board[6][2] = new Square(6,2,new Pawn(true));
            board[6][3] = new Square(6,3,new Pawn(true));
            board[6][4] = new Square(6,4,new Pawn(true));
            board[6][5] = new Square(6,5,new Pawn(true));
            board[6][6] = new Square(6,6,new Pawn(true));
            board[6][7] = new Square(6,7,new Pawn(true));

            //black pieces
            board[0][0] = new Square(0,0,new Rook(false));
            board[0][1] = new Square(0,1,new Knight(false));
            board[0][2] = new Square(0,2,new Bishop(false));
            board[0][3] = new Square(0,3,new Queen(false));
            board[0][4] = new Square(0,4,new King(false));
            board[0][5] = new Square(0,5,new Bishop(false));
            board[0][6] = new Square(0,6,new Knight(false));
            board[0][7] = new Square(0,7,new Rook(false));

            //black pawns
            board[1][0] = new Square(1,0,new Pawn(false));
            board[1][1] = new Square(1,1,new Pawn(false));
            board[1][2] = new Square(1,2,new Pawn(false));
            board[1][3] = new Square(1,3,new Pawn(false));
            board[1][4] = new Square(1,4,new Pawn(false));
            board[1][5] = new Square(1,5,new Pawn(false));
            board[1][6] = new Square(1,6,new Pawn(false));
            board[1][7] = new Square(1,7,new Pawn(false));

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