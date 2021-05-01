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
    if(pos.size() != 4 || pos.size() != 6 ) {
        std::invalid_argument("Number of components of the vector are not correct.");
    }

    if(pos.size() == 4) {
        return  isColorCurrPlayer(pos.at(0), pos.at(1))
                && (!board_.containMarble(pos.at(2), pos.at(3))
                    || isColorCurrPlayer(pos.at(2), pos.at(3)));

    }
    return isColorCurrPlayer(pos.at(0),pos.at(1))
            && isColorCurrPlayer(pos.at(2),pos.at(3));

}

inline bool Game::isColorCurrPlayer(int row, int col) const {
    return board_.getHexagones().at(row).at(col)->getMarble()->getColor()
            == players_.at(idx_CurrentPlayer).getColor();
}

inline bool Game::checkGoodMovePos(std::vector<int> const& pos) const {
    if(pos.size() != 4 || pos.size() != 6 ) {
        std::invalid_argument("Number of components of the vector are not correct.");
    }

    int x = 0;
    int y = 0;

    if(pos.size() == 4) {
        x = pos.at(2) - pos.at(0);
        y = pos.at(3) - pos.at(1);
    } else {
        x = pos.at(4) - pos.at(0);
        y = pos.at(5)- pos.at(1);
    }

    if(x ==0) {
        return y == 1 || y == -1;
    }

    if(x == 1 || x == -1) {
        return x == -y || y == 0;
    }
    return false;
}

void Game::move(std::vector<int> & positions) {
    if(positions.size() != 4 || positions.size() != 6 ) {
        std::invalid_argument("Number of components of the vector are not correct.");
    }

    bool move = board_.move(positions);
    if(move){
        switchCurrentPlayer();
        players_[idx_CurrentPlayer].fallMarble();
        switchCurrentPlayer();
    }
    updatePlayerStatus();
}

void Game::updateLevelStatus(){
    for (unsigned int i = 0; i < players_.size();i++) {
        if(players_.at(i).getPlayerStatus() == FAIL || players_.at(i).getPlayerStatus() == WIN){
            setGameStatus(END);
            break;
        }
    }
}

inline void Game::updatePlayerStatus() {
    if(players_.at(0).isLost()) {
        players_.at(0).setPlayerStatus(FAIL);
        players_.at(1).setPlayerStatus(WIN);
    } else if(players_.at(1).isLost()) {
        players_.at(1).setPlayerStatus(FAIL);
        players_.at(0).setPlayerStatus(WIN);
    }

}


void Game::notify() const {

}

} // end abalone
