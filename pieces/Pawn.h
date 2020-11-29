#include "../Piece.h"
#include <iostream>
using namespace std;
class Pawn : public Piece {
    public:
        void toString() {
            cout << "P";
        }
};