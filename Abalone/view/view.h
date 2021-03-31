#ifndef VIEW_H
#define VIEW_H

#include <windows.h>
#include <string>
#include "model/Player.h"
#include "model/Board.h"
#include <vector>


namespace abalone {

class View {

public:

    View() = default;

    void displayBoard(Board const& hexagones);

    inline void displayMessage(const std::string message) const {
        std::cout<<message<<std::endl;
    }

    void displayCurrentPlayer(Player const& player, unsigned int idxPlayer) const;

    std::vector<int> askPosition(std::string message);

    const std::string askName();

private:
    bool goodRow(char row) const;

    int convertRow(char row) const;

    int convertColumn(unsigned int row, unsigned int col) const;

    bool checkGoodCol(unsigned row, unsigned int col);
};
}


#endif // VIEW_H

