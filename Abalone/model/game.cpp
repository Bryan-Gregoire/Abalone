#include "Game.h"

namespace abalone
{

Game::Game():
    board_{Board()},
    gameStatus_{NOT_STARTED},
    currentPlayer_ {Player(Color::BLACK)},
    players_{{currentPlayer_,Player(Color::WHITE)}}

{}


} // end abalone
