#include <string.h>
using namespace std;
class Queen : public Piece {
    public:
        using Piece::Piece;
        string toString() {
            return "Q";
        }
};