#ifndef GAME_H
#define GAME_H
#include"Board.h"
#include"GameStatus.h"
#include "Player.h"
#include <list>

namespace  abalone{

class Game{

private :
Board board;
GameStatus gameStatus;
std::list<Player> players;

public :
    Game(Board board, GameStatus gameStatus, std::list<Player> players);
    inline Board getBoard() const;
    inline GameStatus getGameStatus() const;
    inline std::list<Player> getPlayers() const;
    void updateLevelStatus();
    void startGame();
    void move(Direction direction);
};
}
#endif // GAME_H
