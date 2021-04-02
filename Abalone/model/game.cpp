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

inline bool Game::checkContentPositions(std::vector<int> const& pos) const  {
    if(pos.size() == 4) {
        return  sameColorCurrPlayer(pos.at(0), pos.at(1));
    }
    return sameColorCurrPlayer(pos.at(0),pos.at(1)) && sameColorCurrPlayer(pos.at(2),pos.at(3)
                                                                           && !board_.containMarble(pos.at(4), pos.at(5)));
}

inline bool Game::sameColorCurrPlayer(int row, int col) const {
    if(board_.containMarble(row, col)) {
        return board_.getHexagones()[row][col]->getMarble()->getColor() == players_[idx_CurrentPlayer].getColor();
    }
    return false;
}

void Game::move(std::vector<int> & positions) {
    bool move = board_.move(positions);
    if(move){
        switchCurrentPlayer();
        players_[idx_CurrentPlayer].fallMarble();
        switchCurrentPlayer();
    }

}

void Game::updateLevelStatus(){
    for (unsigned int i = 0; i < players_.size();i++) {
        if(players_.at(i).isLost()){
            players_.at(i).setPlayerStatus(FAIL);
            setGameStatus(END);
            break;
        }
    }
}


void Game::notify() const {

}

} // end abalone
