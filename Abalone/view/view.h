#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "model/Player.h"
#include "model/Board.h"
#include "model/Position.h"
namespace abalone {

class View {

public:

    View() = default;

    void displayBoard(Board& hexagones);

    inline void displayMessage(std::string message) const {
        std::cout<<message<<std::endl;
    }

    inline void displayPlayer(Player player) const;

     void askPosition()  ;

    //inline int readInteger(std::string message) ;
};
}


#endif // VIEW_H
