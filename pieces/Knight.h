#include <iostream>
using namespace std;
class Knight : public Piece {
    public:
        Knight(bool isWhite) : Piece(isWhite) {}
        string toString() {
            return "N";
        }
};