#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "model/Player.h"
#include "model/Board.h"
#include <vector>

/*!
 * Namespace of the Abalone project.
 *
 */
namespace abalone {

/*!
 * \brief represents the view of the game.
 */
class View {

public:

    /*!
     * \brief Constructor.
     *
    */
    View() = default;

    /*!
     * \brief Display the game board.
     *
     * \param hexagones the board of the game.
     */
    void displayBoard(Board const& hexagones);

    /*!
     * @brief Display the given message.
     *
     * @param message the given message to display.
     */
    inline void displayMessage(const std::string message) const {
        std::cout<<message<<std::endl;
    }

    /**
     * @brief Display the name and the number of the given player.
     *
     * @param player the given player.
     * @param idxPlayer the number of the player.
     */
    void displayCurrentPlayer(Player const& player, unsigned int idxPlayer) const;

    /**
     * @brief Ask for positions.
     *
     * Ask for the position of the balls that the player wants to move and
     * the position where he wants to move them.
     *
     * @param message the given message to display.
     * @return the given positions.
     */
    std::vector<int> askPosition(std::string message);

    /**
     * @brief Ask for the name of a player.
     *
     * @return the given name of the player.
     */
    const std::string askName();

private:
    /*!
     * \brief Check if the row is in the game board.
     *
     * \param row the given row.
     *
     * \return 'true' if the row is in the game board otherwise 'false'.
     */
    bool goodRow(char row) const;

    /*!
     * \brief Convert the given letter into a row of the game board.
     *
     * \param row the given row.
     *
     * \return the converted row.
     */
    int convertRow(char row) const;

    /*!
     * \brief Convert the column.
     *
     * \param row the given row.
     * \param col the given column.
     *
     * \return The converted column.
     */
    int convertColumn(unsigned int col) const;

    /*!
     * \brief Check if the given column is inside the game board.
     *
     * \param row the given row.
     * \param col the given column.
     * \return 'true' if the column is inside otherwise 'false'.
     */
    bool checkGoodCol(unsigned int row, unsigned int col);
};
}


#endif // VIEW_H
