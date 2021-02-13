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
    bool isInside(Position position);
    inline Board getInititalBoard();
    inline int getNbX();
    inline int getNbY();
    inline int getNbZ();
    Position move(Direction direction,Position position);
};
}
#endif // BOARD_H
