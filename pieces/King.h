#include <iostream>
using namespace std;
class King : public Piece {
    public:
        King(bool isWhite) : Piece(isWhite) {}
        string toString() {
            return "K";
        }
};