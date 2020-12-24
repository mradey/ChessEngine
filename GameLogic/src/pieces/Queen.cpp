#include "../../include/pieces/Queen.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Queen::Queen(bool iw, square square) : Piece(iw, square), Rook(iw, square), Bishop(iw, square) {}
std::string Queen::toString() {
    return "Q";
}
std::vector<square> Queen::findValidMoves(Board * board) {
    std::vector<square> queenMoves = Bishop::findValidMoves(board); 
    std::vector<square> rookMoves   = Rook::findValidMoves(board);
    queenMoves.insert(queenMoves.end(), rookMoves.begin(), rookMoves.end());
    return queenMoves;

}