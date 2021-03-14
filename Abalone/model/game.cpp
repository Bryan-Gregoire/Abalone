#include "Game.h"

namespace abalone
{

Game::Game() {
    Board board_;

    Color black = Color::BLACK;
    Player blackPlayer = Player(black);

    Color white = Color::WHITE;
    Player whitePlayer = Player(white);

    std::array<Player,2> players_ = {blackPlayer,whitePlayer};
    Player currentPlayer_ = players_.at(0);

}

} // end abalone
