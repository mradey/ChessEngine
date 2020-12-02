#include <iostream>
using namespace std;
class Pawn : public Piece {
    public:
        Pawn(bool isWhite) : Piece(isWhite) {}
        string toString() {
            return "P";
        }
};