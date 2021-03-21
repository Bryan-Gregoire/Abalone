#ifndef VIEW_H
#define VIEW_H

#include <windows.h>
#include <string>
#include "model/Player.h"
#include "model/Board.h"
#include "model/Position.h"


namespace abalone {

class View {

public:

    View() = default;

    void displayBoard(Board const& hexagones);

    inline void displayMessage(const std::string message) const {
        std::cout<<message<<std::endl;
    }

    void displayCurrentPlayer(Player const& player, unsigned int idxPlayer) const;

    std::pair<unsigned int,unsigned int> askPosition(std::string message);

    unsigned int getIdxRow(unsigned int first) const;

    const std::string askName();

private:
    unsigned int convertRow(char row) const;

    unsigned int convertColumn(unsigned int row, unsigned int col) const;

    bool checkGoodCol(unsigned row, unsigned int col);
};
}


#endif // VIEW_H

