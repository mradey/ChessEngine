#include "../../include/pieces/Rook.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Rook::Rook(bool isWhite) : Piece(isWhite) {}
string Rook::toString() {
    return "R";
}
void Rook::findValidMoves(Board * board) {
    board->printBoard();
}