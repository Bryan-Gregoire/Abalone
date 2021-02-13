#ifndef POSITION_H
#define POSITION_H
#include "Direction.h"

namespace  abalone{
class Position{
private :
    int x ;
    int y ;
    int z ;

public :
    Position(int x, int y, int z );
    inline int getX();
    inline int getY();
    inline int getZ();
    inline bool equals();
    inline Position(Direction direction );

};
}
#endif // POSITION_H
