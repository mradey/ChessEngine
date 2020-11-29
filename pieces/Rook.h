#include "../Piece.h"
#include <iostream>
using namespace std;
class Rook : public Piece {
    public:
        void toString() {
            cout << "R";
        }
};