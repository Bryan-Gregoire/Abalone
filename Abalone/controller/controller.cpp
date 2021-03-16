#include "controller/controller.h"

namespace abalone {

void Controller::start() {
   view_.displayMessage("Player 1");
   model_.setCurrentPlayerName(view_.askName());
   view_.displayMessage("Player 2");
   model_.setCurrentPlayerName(view_.askName());
   view_.displayCurrentPlayer(model_.getCurrentPlayer());
   view_.askPosition();
   view_.displayBoard(model_.getBoard());
}
}
