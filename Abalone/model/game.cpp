#include "Game.h"

namespace abalone
{

Game::Game():
    currentPlayer_ {players_.at(0)}
{}

 Board & Game::getBoard()
{
    return board_;
}
GameStatus& Game::getGameStatus()  {
    return gameStatus_;
}

Player&  Game::getCurrentPlayer()  {
    return currentPlayer_;
}

std::array<Player,2>&  Game::getPlayers() {
    return players_;
}

} // end abalone
