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
List<Player> players;
public :
    Game(Board board, GameStatus gameStatus, List<Player> players);
    inline Baord getBoard();
    inline GameStatus getGameStatus();
    inline <Player> getPlayers();
    void updateLevelStatus();
    void startGame();
};
}
#endif // GAME_H
