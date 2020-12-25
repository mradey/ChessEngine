#include "../../include/pieces/Pawn.h"
#include "../../include/Piece.h"
#include "../../include/Board.h"

Pawn::Pawn(bool iw, square square, pieceId pieceId, pieceType type) : Piece(iw, square, pieceId, type), direction(iw ? UP : DOWN) {}
std::string Pawn::toString() {
    return "P";
}

std::vector<square> Pawn::findValidMoves(Board * board) {
    std::vector<square> validMoves;
    square currentSquare = getSquare();
    
    //get vectors of available squares
    validMoves = getAdvanceableSquares(board, currentSquare);
    std::vector<square> attackingSquares   = getAttackingSquares(board, currentSquare);
    validMoves.insert(validMoves.end(), attackingSquares.begin(), attackingSquares.end());
    return validMoves;
}
std::vector<square> Pawn::getAdvanceableSquares(Board * board, square currentSquare) {
    //Get pawn direction and if has moved
    std::vector<square> advanceableSquares;

    //Check 1 square ahead
    currentSquare.y += direction;    
    Piece * piece = board->getPiece(currentSquare);
    if(piece == NULL) {
        advanceableSquares.push_back(currentSquare);

        //check 2 squares ahead if is on starting square 
        piece = board->getPiece(currentSquare);
        currentSquare.y += direction;
        if(!getHasMoved() && piece == NULL) advanceableSquares.push_back(currentSquare);
    }
    return advanceableSquares;
}

std::vector<square> Pawn::getAttackingSquares(Board * board, square currentSquare) {
    //get pawn direction
    std::vector<square> attackingSquares;
    currentSquare.y += direction;

    //check if can attack towards a file
    currentSquare.x += LEFT;
    if(squareIsAttackable(board, currentSquare) == OCCUPIED_DIFFERENT_COLOR) 
        attackingSquares.push_back(currentSquare);

    //check if can attack towards h file
    currentSquare.x += 2 * RIGHT;
    if(squareIsAttackable(board, currentSquare) == OCCUPIED_DIFFERENT_COLOR) 
        attackingSquares.push_back(currentSquare);

    //check if can en passant
    if(isOnEnPassantSquare()) {
        currentSquare.y -= direction;
        if(canEnPassant(board, currentSquare)) attackingSquares.push_back(currentSquare);
        currentSquare.x += 2 * LEFT;
        if(canEnPassant(board, currentSquare)) attackingSquares.push_back(currentSquare);
    }
    return attackingSquares;
}

bool Pawn::canEnPassant(Board * board, square currentSquare) {
    Piece * piece = board->getPiece(currentSquare);
    return piece->getPieceType() == PAWN && piece->getNumMovesMade() == 1;
}

