#include "../../include/pieces/Pawn.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Pawn::Pawn(bool isWhite) : Piece(isWhite) {}
string Pawn::toString() {
    return "P";
}
void Pawn::findValidMoves(Board * board) {
}