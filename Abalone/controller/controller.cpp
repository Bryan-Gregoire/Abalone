#include "controller/controller.h"

namespace abalone {

void Controller::start() {
    model_.setGameStatus(IN_PROGRESS);
    view_.displayMessage("                      Abalone");
    view_.displayMessage("===================================================");
    view_.displayMessage("Player 1");
    model_.setCurrentPlayerName(view_.askName());
    std::cout<<std::endl;
    view_.displayMessage("Player 2");
    model_.setCurrentPlayerName(view_.askName());
    std::cout<<std::endl;
    while(model_.getGameStatus() == IN_PROGRESS) {
        view_.displayCurrentPlayer(model_.getCurrentPlayer(), model_.getIndexCurrentPlayer());
        view_.displayBoard(model_.getBoard());
        std::pair pos =  view_.askPosition("Enter the Position of one of your marble you want to move : ");
        while(!model_.checkCurrentPlayerColor(pos)) {
            view_.displayMessage("The position does not match with your marble ");
            pos = view_.askPosition("Enter the position of one of your marble : ");
        }
        std::pair nextPos = view_.askPosition("Enter the position where you want to move it : ");
        model_.switchCurrentPlayer();
        std::cout<<std::endl;
    }
}

}
