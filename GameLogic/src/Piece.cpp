#include "../include/Board.h"
#include "../include/Piece.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

Piece::Piece(bool iw, square square) {
    isWhite = iw;
    isOnBoard = true;
    currentSquare = square;
}

bool Piece::getIsWhite() { return isWhite; };

bool Piece::getIsOnBoard() { return isOnBoard; };

bitset<64> Piece::getValidMoves() { return validMoves; }

/*A1 = 0, B1 = 1, ... H1 = 7
    A2 = 8, B2 = 9, ... H2 = 15
*/
void Piece::setValidMove(square square) {
    int idx = convertChessSquareToBitSetIdx(square); 
    validMoves.set(idx);
    validMovesList.push_back(arr.at(idx));
}
void Piece::setValidMoves(std::vector<square> validMoves) {
    for(square sq : validMoves) {
        setValidMove(sq);
    }
}

bool Piece::isValidMove(square square) {
    return validMoves.test(convertChessSquareToBitSetIdx(square));
}

void Piece::noValidMoves() { validMoves.reset(); }

string Piece::toString() { return "piece"; }

std::vector<square> Piece::findValidMoves(Board * board) {return std::vector<square>();}

square Piece::getSquare() {
    return currentSquare;
}

bool Piece::isSameColor(Piece * piece) {
    return piece->getIsWhite() == isWhite;
}


std::string Piece::getValidMovesAsString(){
    std::ostringstream oss;
    oss << "[";
    if (!validMovesList.empty())
    {
    oss << "\"";
    // Convert all but the last element to avoid a trailing ","
    std::copy(validMovesList.begin(), validMovesList.end()-1,
        std::ostream_iterator<std::string>(oss, "\",\""));

    // Now add the last element with no delimiter
    oss << validMovesList.back();
    oss << "\"";
    }
    oss << "]";
    return oss.str();

}

void Piece::setNewSquare(square square) {
    currentSquare = square;
}

occupation Piece::squareIsAttackable(Board * board, square square) {
    Piece * piece = board->getPiece(square);
    board->isOnBoard(square);

    if(board->isOnBoard(square) && (piece == NULL || !isSameColor(piece))){
        return piece == NULL ? EMPTY_SQUARE : OCCUPIED_DIFFERENT_COLOR;
    } 
    return OCCUPIED_SAME_COLOR;
}

void Piece::pieceMoved() {
    hasMoved = true;
}

std::string Piece::getSquareNotation(square square) {
    return arr.at(convertChessSquareToBitSetIdx(square));
}


