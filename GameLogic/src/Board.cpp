#include "../include/Board.h"
#include "../include/Square.h"
#include "../include/Move.h"
#include "../include/allPieces.h"
#include <fstream>
#include <sstream>

Board::Board() {
    resetBoard();
}

void Board::resetBoard() {
    //white pieces
    bool isWhitePiece = true;

    board[A][1-ADJ] =  new Rook    (isWhitePiece, {A, 1-ADJ}, WHITE_A_ROOK,    ROOK);
    board[B][1-ADJ] =  new Knight  (isWhitePiece, {B, 1-ADJ}, WHITE_B_KNIGHT,  KNIGHT);
    board[C][1-ADJ] =  new Bishop  (isWhitePiece, {C, 1-ADJ}, WHITE_C_BISHOP,  BISHOP);
    board[D][1-ADJ] =  new Queen   (isWhitePiece, {D, 1-ADJ}, WHITE_QUEEN,     QUEEN);
    board[E][1-ADJ] =  new King    (isWhitePiece, {E, 1-ADJ}, WHITE_KING,      KING);
    board[F][1-ADJ] =  new Bishop  (isWhitePiece, {F, 1-ADJ}, WHITE_F_BISHOP,  BISHOP);
    board[G][1-ADJ] =  new Knight  (isWhitePiece, {G, 1-ADJ}, WHITE_G_KNIGHT,  KNIGHT);
    board[H][1-ADJ] =  new Rook    (isWhitePiece, {H, 1-ADJ}, WHITE_H_ROOK,    ROOK);

    //white pawns
    board[A][2-ADJ] =  new Pawn    (isWhitePiece, {A, 2-ADJ}, WHITE_A_PAWN,    PAWN);
    board[B][2-ADJ] =  new Pawn    (isWhitePiece, {B, 2-ADJ}, WHITE_B_PAWN,    PAWN);
    board[C][2-ADJ] =  new Pawn    (isWhitePiece, {C, 2-ADJ}, WHITE_C_PAWN,    PAWN);
    board[D][2-ADJ] =  new Pawn    (isWhitePiece, {D, 2-ADJ}, WHITE_D_PAWN,    PAWN);
    board[E][2-ADJ] =  new Pawn    (isWhitePiece, {E, 2-ADJ}, WHITE_E_PAWN,    PAWN);
    board[F][2-ADJ] =  new Pawn    (isWhitePiece, {F, 2-ADJ}, WHITE_F_PAWN,    PAWN);
    board[G][2-ADJ] =  new Pawn    (isWhitePiece, {G, 2-ADJ}, WHITE_G_PAWN,    PAWN);
    board[H][2-ADJ] =  new Pawn    (isWhitePiece, {H, 2-ADJ}, WHITE_H_PAWN,    PAWN);

    //black pieces
    isWhitePiece = false;

    board[A][8-ADJ] =  new Rook    (isWhitePiece, {A, 8-ADJ}, BLACK_A_ROOK,    ROOK);
    board[B][8-ADJ] =  new Knight  (isWhitePiece, {B, 8-ADJ}, BLACK_B_KNIGHT,  KNIGHT);
    board[C][8-ADJ] =  new Bishop  (isWhitePiece, {C, 8-ADJ}, BLACK_C_BISHOP,  BISHOP);
    board[D][8-ADJ] =  new Queen   (isWhitePiece, {D, 8-ADJ}, BLACK_QUEEN,     QUEEN);
    board[E][8-ADJ] =  new King    (isWhitePiece, {E, 8-ADJ}, BLACK_KING,      KING);
    board[F][8-ADJ] =  new Bishop  (isWhitePiece, {F, 8-ADJ}, BLACK_F_BISHOP,  BISHOP);
    board[G][8-ADJ] =  new Knight  (isWhitePiece, {G, 8-ADJ}, BLACK_G_KNIGHT,  KNIGHT);
    board[H][8-ADJ] =  new Rook    (isWhitePiece, {H, 8-ADJ}, BLACK_H_ROOK,    ROOK);

    //white pawns
    board[A][7-ADJ] =  new Pawn    (isWhitePiece, {A, 7-ADJ}, BLACK_A_PAWN,    PAWN);
    board[B][7-ADJ] =  new Pawn    (isWhitePiece, {B, 7-ADJ}, BLACK_B_PAWN,    PAWN);
    board[C][7-ADJ] =  new Pawn    (isWhitePiece, {C, 7-ADJ}, BLACK_C_PAWN,    PAWN);
    board[D][7-ADJ] =  new Pawn    (isWhitePiece, {D, 7-ADJ}, BLACK_D_PAWN,    PAWN);
    board[E][7-ADJ] =  new Pawn    (isWhitePiece, {E, 7-ADJ}, BLACK_E_PAWN,    PAWN);
    board[F][7-ADJ] =  new Pawn    (isWhitePiece, {F, 7-ADJ}, BLACK_F_PAWN,    PAWN);
    board[G][7-ADJ] =  new Pawn    (isWhitePiece, {G, 7-ADJ}, BLACK_G_PAWN,    PAWN);
    board[H][7-ADJ] =  new Pawn    (isWhitePiece, {H, 7-ADJ}, BLACK_H_PAWN,    PAWN);

    //rest of squares have no piece
    for(int i=2; i < 6; i++){
        for(int j=0; j<8; j++) {
            board[j][i] = NULL;
        }
    }

    //UPDATE ALL PIECE LOCATIONS 
        pieceLookup[WHITE_A_ROOK]       = {A, 1-ADJ};
        pieceLookup[WHITE_B_KNIGHT]     = {B, 1-ADJ};
        pieceLookup[WHITE_C_BISHOP]     = {C, 1-ADJ};
        pieceLookup[WHITE_QUEEN]        = {D, 1-ADJ};
        pieceLookup[WHITE_KING]         = {E, 1-ADJ};
        pieceLookup[WHITE_F_BISHOP]     = {F, 1-ADJ};
        pieceLookup[WHITE_G_KNIGHT]     = {G, 1-ADJ};
        pieceLookup[WHITE_H_ROOK]       = {H, 1-ADJ};
        pieceLookup[WHITE_A_PAWN]       = {A, 2-ADJ};
        pieceLookup[WHITE_B_PAWN]       = {B, 2-ADJ};
        pieceLookup[WHITE_C_PAWN]       = {C, 2-ADJ};
        pieceLookup[WHITE_D_PAWN]       = {D, 2-ADJ};
        pieceLookup[WHITE_E_PAWN]       = {E, 2-ADJ};
        pieceLookup[WHITE_F_PAWN]       = {F, 2-ADJ};
        pieceLookup[WHITE_G_PAWN]       = {G, 2-ADJ};
        pieceLookup[WHITE_H_PAWN]       = {H, 2-ADJ};
        pieceLookup[BLACK_A_ROOK]       = {A, 8-ADJ};
        pieceLookup[BLACK_B_KNIGHT]     = {B, 8-ADJ};
        pieceLookup[BLACK_C_BISHOP]     = {C, 8-ADJ};
        pieceLookup[BLACK_QUEEN]        = {D, 8-ADJ};
        pieceLookup[BLACK_KING]         = {E, 8-ADJ};
        pieceLookup[BLACK_F_BISHOP]     = {F, 8-ADJ};
        pieceLookup[BLACK_G_KNIGHT]     = {G, 8-ADJ};
        pieceLookup[BLACK_H_ROOK]       = {H, 8-ADJ};
        pieceLookup[BLACK_A_PAWN]       = {A, 7-ADJ};
        pieceLookup[BLACK_B_PAWN]       = {B, 7-ADJ};
        pieceLookup[BLACK_C_PAWN]       = {C, 7-ADJ};
        pieceLookup[BLACK_D_PAWN]       = {D, 7-ADJ};
        pieceLookup[BLACK_E_PAWN]       = {E, 7-ADJ};
        pieceLookup[BLACK_F_PAWN]       = {F, 7-ADJ};
        pieceLookup[BLACK_G_PAWN]       = {G, 7-ADJ};
        pieceLookup[BLACK_H_PAWN]       = {H, 7-ADJ};
    
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
    pieceToMove->pieceMoved(move);
    pieceToMove->setNewSquare(s2);
    board[s1.x][s1.y] = NULL;
    board[s2.x][s2.y] = pieceToMove;    
}

void Board::boardToJson(ofstream& file) {
    Piece * tmpPiece = new Piece(0, {-1,-1});
    file.open("./board.json");
    file << "{\n";
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            //file << "\t\"" << (char) ('a' + j) << i + 1<< "\":";
            Piece * p = board[j][i];
            file << "\t\"" << tmpPiece->getSquareNotation({j, i}) << "\":";
            if(p != NULL) {
                //file << "{\n\t\t\"piece\":\"" << p->toString() << "\",\n\t\t\"color\":\"" << (p->getIsWhite() ? "W" : "B") << "\"\n\t}";
                file << getPieceJSON(p);
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
 
std::string Board::getPieceJSON(Piece * piece) {
    std::ostringstream s;
    s << "{\n"  
      <<    "\t\t\"piece\":\""      << piece->toString()                 << "\",\n"
      <<    "\t\t\"color\":\""      << (piece->getIsWhite() ? "W" : "B") << "\",\n"
      <<    "\t\t\"validMoves\":"   << piece->getValidMovesAsString()    << "\n"
      << "\t}";
    return s.str();
}