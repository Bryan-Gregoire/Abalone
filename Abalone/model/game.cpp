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
    return isColorCurrPlayer(pos.at(0),pos.at(1)) && isColorCurrPlayer(pos.at(2),pos.at(3));

}

inline bool Game::isColorCurrPlayer(int row, int col) const {
    return board_.getHexagones().at(row).at(col)->getMarble()->getColor()
            == players_.at(idx_CurrentPlayer).getColor();
}

//inline bool Game::checkGoodMovePos(std::vector<int> const& position) const {
//    if(position.size() != 4 || position.size() != 6 ) {
//        std::invalid_argument("Number of components of the vector are not correct.");
//    }

//    if(position.size() == 4) {
//        int x = position.at(0) - position.at(2);
//        int y = position.at(1) - position.at(3);
//        if(x == 0) {
//            return y == 1 || y == -1;
//        }
//        if(x == 1 || x == -1) {
//            return y == 1 || y == -1;
//        }
//    } else {
//        int marbleX = position.at(0) - position.at(2);
//        int marbleY = position.at(1) - position.at(3);

//        int moveX =  position.at(4) - position.at(0);
//        int moveY = position.at(5) - position.at(1);

//        if(marbleX == 0) {
//            if(std::abs(marbleY) == 1 && moveX == 1 && moveY == 0) {
//                return !board_.containMarble(position.at(0) + moveX, position.at(1))
//                        && !board_.containMarble(position.at(2) + moveX, position.at(3));
//            } else if(std::abs(marbleY) == 2) {
//                int midY = marbleY == 2 ? -1 : 1;
//                return isColorCurrPlayer(position.at(0), position.at(1) + midY)
//                        && !board_.containMarble(position.at(0) + moveX, position.at(1))
//                        && !board_.containMarble(position.at(2) + moveX, position.at(3))
//                        && !board_.containMarble(position.at(0) + moveX, position.at(1) + midY);
//            }
//        } else if(marbleX == 1 || marbleX == -1) {

//            return marbleY == 1 || marbleY == -1 ? true : false;

//        } else if(marbleX == 2 || marbleX - 2) {

//        }
//    }
//    return false;
//}


inline bool Game::checkGoodMovePos(std::vector<int> const& pos) const {
    if(pos.size() != 4 || pos.size() != 6 ) {
        std::invalid_argument("Number of components of the vector are not correct.");
    }

    if(pos.size() == 4) {
        int x = pos.at(0) - pos.at(2);
        int y = pos.at(1) - pos.at(3);
        if(x == 0) {
            return y == 1 || y == -1;
        }
        if(x == 1 || x == -1) {
            return y == 1 || y == -1;
        }
    } else {
        int marbleX = pos.at(0) - pos.at(2);
        int marbleY = pos.at(1) - pos.at(3);

        int moveX =  pos.at(4) - pos.at(0);
        int moveY = pos.at(5) - pos.at(1);
        int addX = board_.convertPositionBound(moveX);
        int addY = board_.convertPositionBound(moveY);
        return std::abs(moveX) < 2 && std::abs(moveY) < 2
                && std::abs(marbleX) < 3 && std::abs(marbleY) < 3
                && !board_.containMarble(pos.at(0) + addX,pos.at(1) + addY)
                && !board_.containMarble(pos.at(2) + addX,pos.at(3) + addY);
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
