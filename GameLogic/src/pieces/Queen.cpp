#include "../../include/pieces/Queen.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Queen::Queen(bool iw, int file, int rank) : Piece(iw, file, rank), Rook(iw, file, rank), Bishop(iw, file, rank) {}
string Queen::toString() {
    return "Q";
}
int Queen::findValidMoves(Board * board) {
    return Bishop::findValidMoves(board) + Rook::findValidMoves(board);
}