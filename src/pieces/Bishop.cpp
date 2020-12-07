#include "../../include/pieces/Bishop.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite) {}
string Bishop::toString() {
    return "B";
}
void Bishop::findValidMoves(Board * board) {
    board->printBoard();
}