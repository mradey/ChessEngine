#include "../Piece.h"
#include <iostream>
using namespace std;
class Knight : public Piece {
    public:
        void toString() {
            cout << "N";
        }
};