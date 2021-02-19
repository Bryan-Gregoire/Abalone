#ifndef PLAYER_H
#define PLAYER_H
#include"playerStatus.h"
#include"color.h"
namespace  abalone{

class Player {

private :
int nbMarble =14;
PlayerStatus playerStatus = IN_GAME;
Color color;

public :
    Player(Color color);
    inline bool isLost();
    inline Color getColor() const;

    Color getColor() {
        return this->color;
    }
};

}
#endif // PLAYER_H
