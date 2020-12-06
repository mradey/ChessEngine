#include <string.h>
using namespace std;
class Queen : public Piece {
    public:
        Queen(bool isWhite) : Piece(isWhite) {}
        string toString() {
            return "Q";
        }
};