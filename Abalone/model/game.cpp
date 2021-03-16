#include "Game.h"

namespace abalone
{

Game::~Game() {};

Game::Game():
    board_{Board()},
    gameStatus_{NOT_STARTED},
    idx_CurrentPlayer {0},
    players_{{Player(Color::BLACK), Player(Color::WHITE)}}
{}

void Game::move(Direction const& direction) {

}

void Game::notify() const {

}

} // end abalone
