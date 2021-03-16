#include "Game.h"

namespace abalone
{

Game::Game():
    board_{Board()},
    gameStatus_{NOT_STARTED},
    players_{{Player(Color::BLACK)}}
    //currentPlayer_ {players_.at(0)}


{}


} // end abalone
