#ifndef PLAYER_H
#define PLAYER_H
#include"PlayerStatus.h"
#include"Color.h"
namespace  abalone{

class Player{

private :
int nbMarble =14;
PlayerStatus playerStatus = IN_GAME;
Color color;

public :
    Player(Color color);
    inline bool isLost();
    inline Color getColor() const;
};

}
#endif // PLAYER_H
