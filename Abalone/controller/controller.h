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
    void printGame();
    bool checkIfIsSamePos(std::vector<int> const& position) const;
    void printWinnerLoser();
};

}

#endif // CONTROLLER_H

