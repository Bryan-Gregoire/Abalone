#include "controller/controller.h"

namespace abalone {

void Controller::start() {
    model_.setGameStatus(IN_PROGRESS);
    view_.displayMessage("Player 1");
    model_.setCurrentPlayerName(view_.askName());
    view_.displayMessage("Player 2");
    model_.setCurrentPlayerName(view_.askName());
    view_.displayCurrentPlayer(model_.getCurrentPlayer(), model_.getIndexCurrentPlayer());
    view_.displayBoard(model_.getBoard());
    std::pair p =  view_.askPosition();
    std::cout<<"Ligne : "<<p.first<< " Colonne : "<<p.second<<std::endl;
}

}
