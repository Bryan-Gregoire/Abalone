#ifndef BOARD_H
#define BOARD_H
#include "hexagone.h"
#include "direction.h"

namespace  abalone{

class Board{

private :
Hexagone hexagones[9][9];

public :
    Board();
    //Board(Hexagone** hexagones); // Pour les tests.
    inline Hexagone** getHexagones();
    inline int getNbRow() const;
    inline int getNbCol() const;
    void move(Direction direction);
private:
    void moveHorizontally(Direction direction);
    void moveOblique(Direction direction);

};

}
#endif // BOARD_H
