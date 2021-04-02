#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view/view.h"
#include "model/Game.h"

namespace abalone {

class Controller {

private:
    View view_;
    Game model_;

public:

    /**
     * @brief constructor Controller
     */
    Controller() = default;

    void start();

private :
    bool checkIfContainSamePos(std::vector<int> const& position) const;
    void printGame() ;
};

}

#endif // CONTROLLER_H

