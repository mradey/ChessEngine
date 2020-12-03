#include <iostream>
using namespace std;
class Rook : public Piece {
    public:
        Rook(bool isWhite) : Piece(isWhite) {}
        string toString() {
            return "Rook";
        }
};