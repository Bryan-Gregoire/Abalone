#include "controller/controller.h"

namespace abalone {

void Controller::start() {
    //view_.displayMessage("Bienvenue dans Abalone, voici le plateau de jeu : ");
   view_.displayBoard(model_.getBoard());
}
}
