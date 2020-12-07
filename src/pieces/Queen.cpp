#include "../../include/pieces/Queen.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Queen::Queen(bool isWhite) : Piece(isWhite) {}
string Queen::toString() {
    return "Q";
}
void Queen::findValidMoves(Board * board) {
    board->printBoard();
}