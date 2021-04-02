#include "controller/controller.h"

namespace abalone {

void Controller::start() {
    printGame();
    while(model_.getGameStatus() == IN_PROGRESS) {
        view_.displayCurrentPlayer(model_.getCurrentPlayer(), model_.getIndexCurrentPlayer());
        view_.displayBoard(model_.getBoard());
        std::vector posMove =  view_.askPosition("Enter the Position of one of your marble you want to move : ");
        while(!model_.checkContentPositions(posMove) || checkIfContainSamePos(posMove)) {
            view_.displayMessage("The selected marble(s) does not match with your color ");
            posMove = view_.askPosition("Enter the position of your marble(s) : ");
        }
        model_.move(posMove);
        model_.switchCurrentPlayer();
        std::cout<<std::endl;
    }
}

bool Controller::checkIfContainSamePos(std::vector<int> const& position) const {
    if(position.size() == 4) {
        return position.at(0) == position.at(2) && position.at(1) == position.at(3);
    }
    return (position.at(0) == position.at(2) && position.at(1) == position.at(3))
            || (position.at(0) == position.at(4) && position.at(1) == position.at(5))
             || (position.at(2) == position.at(4) && position.at(3) == position.at(5));
}

void Controller::printGame(){
    model_.setGameStatus(IN_PROGRESS);
    view_.displayMessage("                      Abalone");
    view_.displayMessage("===================================================");
    view_.displayMessage("Player 1");
    model_.setCurrentPlayerName(view_.askName());
    std::cout<<std::endl;
    view_.displayMessage("Player 2");
    model_.setCurrentPlayerName(view_.askName());
    std::cout<<std::endl;
}

}
