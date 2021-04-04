#ifndef BOARD_H
#define BOARD_H
#include "Hexagone.h"
#include <array>
#include <vector>

/*!
 * Namespace of the Abalone project.
 */
namespace  abalone{

/*!
 * The game board, made of hexagons.
 */
class Board{

public:

    /*!
     * @brief SIZE size of the board.
     *
     */
    const static unsigned int SIZE = 9;

private :


    /*!
    * Two-Dimensional array made of hexagons.
    *
    */
    std::array<std::array<std::optional<Hexagone>,SIZE>,SIZE> hexagones_;
public :

    /*!
     * \brief Constructor.
     *
    */
    Board();

    /*!
     * Read accessor of the board.
     *
     * \return the board of hexagones.
     */
    inline std::array<std::array<std::optional<Hexagone>,SIZE>,SIZE>  getHexagones() const {
        return hexagones_;
    }

    /*!
     * \brief isInsideBoard Check if the given position is in the game board.
     *
     * \param i The row.
     * \param j The column.
     * \return
     */
    inline bool isInsideBoard(unsigned int i, unsigned int j) const {
        return hexagones_[i][j].has_value();
    }

    /*!
     * \brief Check if at the given position there is a marble.
     *
     * \param i the given row.
     * \param j the given column.
     *
     * \return true if there is a marble otherwise false.
     */
    inline bool containMarble(unsigned int i,unsigned int j) const {
        return hexagones_[i][j]->getMarble().has_value();
    }

    /*!
     * \brief get the color of the marble at the given position.
     *
     * \param i the row.
     * \param j the column.
     *
     *
     * \return  the color of the marble
     *
     * \throw std::invalid_argument if the given position is not inside
     *  the board or there is not a marble a the given position.
     *
     * \see abalone::isInsideBoard(unsigned int i, unsigned int j).
     * \see abalone::containMarble(unsigned int i, unsigned int j).
     */
    inline Color getColorMarble(unsigned int i, unsigned int j) const {
        if(!isInsideBoard(i,j) || !containMarble(i,j)) {
            throw std::invalid_argument("There are no marbles in this position");
        }
        return hexagones_[i][j]->getMarble()->getColor();
    }


    /*!
     * Moves a single marble or column of marbles of the same color in a given direction.
     *
     * A Column consists of two or three marbles of the same color directly
     * adjacent to one another in a straight line.
     *
     * A marble or a column can move in any direction in an in-line move or
     * side-step move.
     *
     * An “In-line” Move :
     *
     * Marbles are moved as a column into a free space.
     *
     * A ‘Side step’ move:
     *
     * Marbles are moved sideways into adjacent free spaces.
     * A ‘Side step’ move can not be used to push an opponents single
     * marble, or column.
     *
     * All marbles in a Column must move in the same direction.
     *
     * You can push the marbles of a different color when you find in a position
     * of superiority digital.
     */
    bool move(std::vector<int> & positions);

private:

    /*!
     * The marbles progress together one space at a time.
     *
     */
    bool moveLine(std::vector<int> & positions);

    /*!
     * the beads are progressing laterally, without modifying alignment.
     *
     */
    bool moveLateral(std::vector<int> & positions);

};

}
#endif // BOARD_H
