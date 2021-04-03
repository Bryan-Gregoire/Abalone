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
        return  isColorCurrPlayer(pos.at(0), pos.at(1))
                && (board_.containMarble(pos.at(2), pos.at(3)
                                         ? board_.getColorMarble(pos.at(2),pos.at(3))
                                           == players_[idx_CurrentPlayer].getColor() : true));
    }
    return isColorCurrPlayer(pos.at(0),pos.at(1))
            && isColorCurrPlayer(pos.at(2),pos.at(3) && !board_.containMarble(pos.at(4), pos.at(5)));
}

inline bool Game::isColorCurrPlayer(int row, int col) const {
    if(board_.containMarble(row, col)) {
        return board_.getHexagones()[row][col]->getMarble()->getColor() == players_[idx_CurrentPlayer].getColor();
    }
    return false;
}

inline bool Game::checkGoodMovePos(std::vector<int> const& position) const { // A FINIR
    if(position.size() == 4) {
        int x = position.at(0) - position.at(2);
        int y = position.at(1) - position.at(3);
        if(x == 0) {
            return y == 1 || y == -1;
        }
        if(x == 1 || x == -1) {
            return y == 1 || y == -1;
        }
    } else {
        int x = position.at(0) - position.at(2);
        int y = position.at(1) - position.at(3);
        if(x == 0) {
            if(y == 1 || y == -1) {
                return true;
            } else if(y == 2) {
                return isColorCurrPlayer(position.at(0), position.at(1) -1);
            } else if(y == -2) {
                return isColorCurrPlayer(position.at(0), position.at(1) + 1);
            }
        } else if(x == 1 || x == -1) {

            return y == 1 || y == -1 ? true : false;
        } else if(x == 2 || x - 2) {

        }
    }

    //REVERIFIER TOUT
    return false;
}

void Game::move(std::vector<int> & positions) { //REVERIFIER methode
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
