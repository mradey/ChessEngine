#include <iostream>
using namespace std;
class Bishop : public Piece {
    public:
        Bishop(bool isWhite) : Piece(isWhite) {}
        string toString() {
            return "B";
        }
};