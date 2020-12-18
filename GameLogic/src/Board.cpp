#include "../include/Board.h"
#include "../include/Square.h"
#include "../include/Move.h"
#include "../include/allPieces.h"
#include <fstream>


Board::Board() {
    resetBoard();
}

void Board::resetBoard() {
    //white pieces
    bool isWhitePiece = true;

    board[A][1-ADJ] =  new Rook    (isWhitePiece,A, 1-ADJ);
    board[B][1-ADJ] =  new Knight  (isWhitePiece,B, 1-ADJ);
    board[C][1-ADJ] =  new Bishop  (isWhitePiece,C, 1-ADJ);
    board[D][1-ADJ] =  new Queen   (isWhitePiece,D, 1-ADJ);
    board[E][1-ADJ] =  new King    (isWhitePiece,E, 1-ADJ);
    board[F][1-ADJ] =  new Bishop  (isWhitePiece,F, 1-ADJ);
    board[G][1-ADJ] =  new Knight  (isWhitePiece,G, 1-ADJ);
    board[H][1-ADJ] =  new Rook    (isWhitePiece,H, 1-ADJ);

    //white pawns
    board[A][2-ADJ] =  new Pawn    (isWhitePiece,A, 2-ADJ);
    board[B][2-ADJ] =  new Pawn    (isWhitePiece,B, 2-ADJ);
    board[C][2-ADJ] =  new Pawn    (isWhitePiece,C, 2-ADJ);
    board[D][2-ADJ] =  new Pawn    (isWhitePiece,D, 2-ADJ);
    board[E][2-ADJ] =  new Pawn    (isWhitePiece,E, 2-ADJ);
    board[F][2-ADJ] =  new Pawn    (isWhitePiece,F, 2-ADJ);
    board[G][2-ADJ] =  new Pawn    (isWhitePiece,G, 2-ADJ);
    board[H][2-ADJ] =  new Pawn    (isWhitePiece,H, 2-ADJ);

    //black pieces
    isWhitePiece = false;

    board[A][8-ADJ] =  new Rook    (isWhitePiece,A, 8-ADJ);
    board[B][8-ADJ] =  new Knight  (isWhitePiece,B, 8-ADJ);
    board[C][8-ADJ] =  new Bishop  (isWhitePiece,C, 8-ADJ);
    board[D][8-ADJ] =  new Queen   (isWhitePiece,D, 8-ADJ);
    board[E][8-ADJ] =  new King    (isWhitePiece,E, 8-ADJ);
    board[F][8-ADJ] =  new Bishop  (isWhitePiece,F, 8-ADJ);
    board[G][8-ADJ] =  new Knight  (isWhitePiece,G, 8-ADJ);
    board[H][8-ADJ] =  new Rook    (isWhitePiece,H, 8-ADJ);

    //white pawns
    board[A][7-ADJ] =  new Pawn    (isWhitePiece,A, 7-ADJ);
    board[B][7-ADJ] =  new Pawn    (isWhitePiece,B, 7-ADJ);
    board[C][7-ADJ] =  new Pawn    (isWhitePiece,C, 7-ADJ);
    board[D][7-ADJ] =  new Pawn    (isWhitePiece,D, 7-ADJ);
    board[E][7-ADJ] =  new Pawn    (isWhitePiece,E, 7-ADJ);
    board[F][7-ADJ] =  new Pawn    (isWhitePiece,F, 7-ADJ);
    board[G][7-ADJ] =  new Pawn    (isWhitePiece,G, 7-ADJ);
    board[H][7-ADJ] =  new Pawn    (isWhitePiece,H, 7-ADJ);

    //rest of squares have no piece
    for(int i=2; i < 6; i++){
        for(int j=0; j<8; j++) {
            board[j][i] = NULL;
        }
    }
    
}
Piece * Board::getPiece(square square) {
    return board[square.x][square.y];
}

bool Board::isOnBoard(square square) {
    return square.x < 8 && square.x >= 0 &&
           square.y < 8 && square.y >= 0;
}

string Board::toString() {
    string boardString;
    for(int i = 0; i < 8; i++) {
        string row;
        for(int j = 0; j < 8; j++) {
            Piece * p = board[i][j];
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
            Piece * p = board[i][j];
            if(p != NULL) cout << p->toString() << (p->getIsWhite() ? "W" : "B") << "|";
            else cout << "  |";
        }    
    }
}

void Board::printBoardWhiteTurn() {
    for(int i = 7; i >= 0; i--) {
        cout << "\n" << string(8 * 3, '-') << "\n";
        for(int j = 0; j < 8; j++) {
            Piece * p = board[j][i];
            if(p != NULL) cout << p->toString() << (p->getIsWhite() ? "W" : "B") << "|";
            else cout << "  |";
        }
    }
}


void Board::movePiece(Move * move) {
    whiteMove = !whiteMove;
    square s1 = move->getBeginSquare();
    square s2 = move->getEndSquare();
    Piece * pieceToMove = board[s1.x][s1.y];
    pieceToMove->pieceMoved();
    pieceToMove->setNewSquare(s2);
    board[s1.x][s1.y] = NULL;
    board[s2.x][s2.y] = pieceToMove;    
}

void Board::boardToJson(ofstream& file) {
    file.open("./board.json");
    file << "{\n";
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            file << "\t\"" << (char) ('a' + j) << i + 1<< "\":";
            string newSquare = (char) ('a' + j) + to_string(i + 1);
            Piece * p = board[j][i];
            if(p != NULL) {
                file << "{\n\t\t\"piece\":\"" << p->toString() << "\",\n\t\t\"color\":\"" << (p->getIsWhite() ? "W" : "B") << "\"\n\t}";
            }
            else {
                file << "null";
            }
            if(i!=7 || j!=7) file << ",\n";
        }    
    }
    file << "\n}";
    file.close();
    cout << "wrote to json";
}
 