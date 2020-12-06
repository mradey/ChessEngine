#include "../../include/pieces/Knight.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Knight::Knight(bool isWhite) : Piece(isWhite) {}
string Knight::toString() {
    return "N";
}
void Knight::findValidMoves(Board * board) {
    board->printBoard();
}