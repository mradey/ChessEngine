#include "../include/Piece.h"
#include "../include/Board.h"

Piece::Piece(bool iw) {
    isWhite = iw;
    isOnBoard = true;
}

bool Piece::getIsWhite() { return isWhite; };

bool Piece::getIsOnBoard() { return isOnBoard; };

bitset<64> Piece::getValidMoves() { return validMoves; }

/*A1 = 0, B1 = 1, ... H1 = 7
    A2 = 8, B2 = 9, ... H2 = 15
*/
void Piece::setValidMove(int rank, int col) { 
    validMoves.set(convertChessSquareToBitSetIdx(rank, col));
}

bool Piece::isValidMove(int rank, int col) {
    return validMoves.test(convertChessSquareToBitSetIdx(rank, col));
}

void Piece::noValidMoves() { validMoves.reset(); }

string Piece::toString() { return "piece"; }

void Piece::findValidMoves(Board * board) {}