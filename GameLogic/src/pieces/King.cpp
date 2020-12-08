#include "../../include/pieces/King.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

King::King(bool isWhite) : Piece(isWhite) {}
string King::toString() {
    return "K";
}
void King::findValidMoves(Board * board) {
}