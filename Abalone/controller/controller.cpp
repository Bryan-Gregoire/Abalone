#include "controller/controller.h"

namespace abalone {

void Controller::start() {
    printGame();
    while(model_.getGameStatus() == IN_PROGRESS) {
        view_.displayCurrentPlayer(model_.getCurrentPlayer(), model_.getIndexCurrentPlayer());
        view_.displayBoard(model_.getBoard());
        std::vector posMove =  view_.askPosition("Enter the Position of your(s) marble(s) and where you want to move it : ");
        while(!model_.checkContentPositions(posMove) || checkIfIsSamePos(posMove)) {
            view_.displayMessage("Wrong Position(s), try again : ");
            posMove = view_.askPosition("Enter the Position of your(s) marble(s) and where you want to move it : ");
        }
        model_.move(posMove);
        model_.switchCurrentPlayer();
        model_.updateLevelStatus();
    }
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

bool Controller::checkIfIsSamePos(std::vector<int> const& position) const {
    if(position.size() == 4) {
        return position.at(0) == position.at(2) && position.at(1) == position.at(3);
    }
    return (position.at(0) == position.at(2) && position.at(1) == position.at(3))
            || (position.at(0) == position.at(4) && position.at(1) == position.at(5))
             || (position.at(2) == position.at(4) && position.at(3) == position.at(5));
}


}
