#include "../../include/pieces/Queen.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Queen::Queen(bool iw, square square, pieceId pieceId, pieceType type) : Piece(iw, square, pieceId, type), Rook(iw, square, pieceId, type), Bishop(iw, square, pieceId, type) {}
char Queen::toChar() {
    return getIsWhite() ? 'Q' : 'q';
}
std::vector<square> Queen::findValidMoves(Board * board) {
    std::vector<square> queenMoves = Bishop::findValidMoves(board); 
    std::vector<square> rookMoves   = Rook::findValidMoves(board);
    queenMoves.insert(queenMoves.end(), rookMoves.begin(), rookMoves.end());
    return queenMoves;

}