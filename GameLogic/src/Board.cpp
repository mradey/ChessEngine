#include "../include/Board.h"
#include "../include/Square.h"
#include "../include/Move.h"
#include "../include/allPieces.h"

Board::Board() {
    resetBoard();
}

void Board::resetBoard() {
    //white pieces
    bool isWhitePiece = true;

    board[A][1 - ADJ] =  new Square(A,1 - ADJ,new Rook(isWhitePiece));
    board[B][1 - ADJ] =  new Square(B,1 - ADJ,new Knight(isWhitePiece));
    board[C][1 - ADJ] =  new Square(C,1 - ADJ,new Bishop(isWhitePiece));
    board[D][1 - ADJ] =  new Square(D,1 - ADJ,new Queen(isWhitePiece));
    board[E][1 - ADJ] =  new Square(E,1 - ADJ,new King(isWhitePiece));
    board[F][1 - ADJ] =  new Square(F,1 - ADJ,new Bishop(isWhitePiece));
    board[G][1 - ADJ] =  new Square(G,1 - ADJ,new Knight(isWhitePiece));
    board[H][1 - ADJ] =  new Square(H,1 - ADJ,new Rook(isWhitePiece));

    //white pawns
    board[A][2 - ADJ] =  new Square(A,2 - ADJ,new Pawn(isWhitePiece));
    board[B][2 - ADJ] =  new Square(B,2 - ADJ,new Pawn(isWhitePiece));
    board[C][2 - ADJ] =  new Square(C,2 - ADJ,new Pawn(isWhitePiece));
    board[D][2 - ADJ] =  new Square(D,2 - ADJ,new Pawn(isWhitePiece));
    board[E][2 - ADJ] =  new Square(E,2 - ADJ,new Pawn(isWhitePiece));
    board[F][2 - ADJ] =  new Square(F,2 - ADJ,new Pawn(isWhitePiece));
    board[G][2 - ADJ] =  new Square(G,2 - ADJ,new Pawn(isWhitePiece));
    board[H][2 - ADJ] =  new Square(H,2 - ADJ,new Pawn(isWhitePiece));

    //black pieces
    isWhitePiece = false;

    board[A][8 - ADJ] =  new Square(A,8 - ADJ,new Rook(isWhitePiece));
    board[B][8 - ADJ] =  new Square(B,8 - ADJ,new Knight(isWhitePiece));
    board[C][8 - ADJ] =  new Square(C,8 - ADJ,new Bishop(isWhitePiece));
    board[D][8 - ADJ] =  new Square(D,8 - ADJ,new Queen(isWhitePiece));
    board[E][8 - ADJ] =  new Square(E,8 - ADJ,new King(isWhitePiece));
    board[F][8 - ADJ] =  new Square(F,8 - ADJ,new Bishop(isWhitePiece));
    board[G][8 - ADJ] =  new Square(G,8 - ADJ,new Knight(isWhitePiece));
    board[H][8 - ADJ] =  new Square(H,8 - ADJ,new Rook(isWhitePiece));

    //white pawns
    board[A][7 - ADJ] =  new Square(A,7 - ADJ,new Pawn(isWhitePiece));
    board[B][7 - ADJ] =  new Square(B,7 - ADJ,new Pawn(isWhitePiece));
    board[C][7 - ADJ] =  new Square(C,7 - ADJ,new Pawn(isWhitePiece));
    board[D][7 - ADJ] =  new Square(D,7 - ADJ,new Pawn(isWhitePiece));
    board[E][7 - ADJ] =  new Square(E,7 - ADJ,new Pawn(isWhitePiece));
    board[F][7 - ADJ] =  new Square(F,7 - ADJ,new Pawn(isWhitePiece));
    board[G][7 - ADJ] =  new Square(G,7 - ADJ,new Pawn(isWhitePiece));
    board[H][7 - ADJ] =  new Square(H,7 - ADJ,new Pawn(isWhitePiece));

    //rest of squares have no piece
    for(int i=2; i < 6; i++){
        for(int j=0; j<8; j++) {
            board[j][i] = new Square(j, i, NULL);
        }
    }
    
}

string Board::toString() {
    string boardString;
    for(int i = 0; i < 8; i++) {
        string row;
        for(int j = 0; j < 8; j++) {
            Square square = * board[i][j];
            Piece * p = square.getPiece();
            row.append(p != NULL ? p->toString() + "|" : "|");
        }
        row.append("\n");
        boardString.append(row);
    }
    return boardString;
}

void Board::printBoardBlackTurn() {
    for(int i = 0; i < 8; i++) {
        cout << "\n" << string(8 * 3, '-') << "\n";
        for(int j = 7; j >= 0; j--) {
            Square square = * board[j][i];
            Piece * p = square.getPiece();
            if(p != NULL) cout << p->toString() << (p->getIsWhite() ? "W" : "B") << "|";
            else cout << "  |";
        }    
    }
}

void Board::printBoardWhiteTurn() {
    for(int i = 7; i >= 0; i--) {
        cout << "\n" << string(8 * 3, '-') << "\n";
        for(int j = 0; j < 8; j++) {
            Square square = * board[j][i];
            Piece * p = square.getPiece();
            if(p != NULL) cout << p->toString() << (p->getIsWhite() ? "W" : "B") << "|";
            else cout << "  |";
        }
    }
}


void Board::movePiece(Move * move) {
    whiteMove = !whiteMove;
    square s1 = move->getBeginSquare();
    square s2 = move->getEndSquare();
    Piece * pieceToMove = board[s1.x][s1.y]->getPiece();
    board[s1.x][s1.y]->setPiece(NULL);
    board[s2.x][s2.y]->setPiece(pieceToMove);
    whiteMove ? printBoardWhiteTurn() : printBoardBlackTurn();
    
}