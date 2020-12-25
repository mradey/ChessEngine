#include "../../include/pieces/King.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

King::King(bool iw, square square, pieceId pieceId, pieceType type) : Piece(iw, square, pieceId, type) {}
std::string King::toString() {
    return "K";
}
std::vector<square> King::findValidMoves(Board * board) {
    square currentSquare = getSquare();
    std::vector<square> availableSquares = checkSurrondingSqures(board, currentSquare);
    std::vector<square> castlingSquares = castlingEligible(board);
    availableSquares.insert(availableSquares.end(), castlingSquares.begin(), castlingSquares.end());

    return availableSquares;
}
std::vector<square> King::checkSurrondingSqures(Board * board, square currentSquare) {
    std::vector<square> availableSquares;
    std::vector<square> rankSquares;
    
    rankSquares = checkRank(board, currentSquare);
    availableSquares.insert(availableSquares.end(), rankSquares.begin(), rankSquares.end());

    currentSquare.y += 1;
    rankSquares = checkRank(board, currentSquare);
    availableSquares.insert(availableSquares.end(), rankSquares.begin(), rankSquares.end());
    
    currentSquare.y -= 2;
    rankSquares = checkRank(board, currentSquare);
    availableSquares.insert(availableSquares.end(), rankSquares.begin(), rankSquares.end());
    
    return availableSquares;
}

std::vector<square> King::checkRank(Board * board, square currentSquare) {
    std::vector<square> availableSquares;
    if(squareIsAttackable(board, currentSquare)) availableSquares.push_back(currentSquare);
    currentSquare.x -= 1;
    if(squareIsAttackable(board, currentSquare)) availableSquares.push_back(currentSquare);
    currentSquare.x += 2;
    if(squareIsAttackable(board, currentSquare)) availableSquares.push_back(currentSquare);
    return availableSquares;
}

std::vector<square> King::castlingEligible(Board * board) {
    std::vector<square> castlingSquares;
    if(!getHasMoved()) {
        int rank = getIsWhite() ? 0 : 7;
        Piece * aRook = board->getPiece({0, rank});
        Piece * hRook = board->getPiece({7, rank});
        square castlingSquare;
        castlingSquare = checkSquaresBetweenKingAndRook(board, aRook, RIGHT);
        if(castlingSquare.x != -1) castlingSquares.push_back(castlingSquare);
        castlingSquare = checkSquaresBetweenKingAndRook(board, hRook, LEFT);
        if(castlingSquare.x != -1) castlingSquares.push_back(castlingSquare);
    }
   return castlingSquares;
}

square King::checkSquaresBetweenKingAndRook(Board * board, Piece * rook, int direction) {
    if(rook != NULL && rook->getPieceType() == ROOK && rook->getHasMoved()) {
        square castlingSquare = {rook->getSquare().x + direction, rook->getSquare().y}; 
        if(board->getPiece(castlingSquare) == NULL) {
            return castlingSquare;
        }
    }
    return {-1,-1};
}
