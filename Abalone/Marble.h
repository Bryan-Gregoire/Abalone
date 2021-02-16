#ifndef MARBLE_H
#define MARBLE_H
#include "Color.h"
namespace  abalone{

class Marble{

private :
    Color color ;

public :
    Marble(Color color);
    inline Color getColor() const;
};

}


#endif // MARBLE_H
