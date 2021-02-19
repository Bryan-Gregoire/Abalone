#ifndef POSITION_H
#define POSITION_H
#include "direction.h"

namespace  abalone{

class Position{

private :
    int x ;
    int y ;
    int z ;

public :
    Position(int x, int y, int z );
    inline int getX() const;
    inline int getY() const;
    inline int getZ() const;
    inline bool equals(Position position) const;
    Position nextPos(Direction direction );

    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
    int getZ() {
        return this->z;
    }};

}
#endif // POSITION_H
