#ifndef MODEL_H
#define MODEL_H
#include "board.h"
#include "gameStatus.h"
#include "player.h"

namespace abalone {

class Model {

public:
    virtual ~Model();

    virtual Board getBoard() const;
    virtual GameStatus getGameStatus() const;
    virtual Player getCurrentPlayer() const;
    virtual void move(Direction direction);

};

}
#endif // MODEL_H
