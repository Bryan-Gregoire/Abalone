#ifndef BOARD_H
#define BOARD_H
#include "Hexagone.h"
#include "Position.h"
namespace  abalone{

class Board{

private :
Hexagone hexagones[9][9];

public :
    Board(Hexagone hexagones);
    inline Board getInititalBoard();
    inline int getNbX() const;
    inline int getNbY() const;
    inline int getNbZ() const;
    bool isInside(Position position) const;
    Position move(Direction direction,Position position);
};

}
#endif // BOARD_H
