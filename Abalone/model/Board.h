#ifndef BOARD_H
#define BOARD_H
#include "Hexagone.h"
#include "Direction.h"
#include <array>

/*!
 * Namespace of the Abalone project.
 */
namespace  abalone{

/*!
 * The game board, made of hexagons.
 */
class Board{

public:

    static const unsigned int SIZE = 9;

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
     * \brief Constructor.
     *
     * \param hexagons the given array made of hexagons.
     *
     * \throw std::invalid_argument if hexagons is null.
     */
    //Board(Hexagone std::array<std::array<std::optional<Hexagone>,9>,9>  hexagons);

    /*!
     * Read accessor of the board.
     *
     * \return the board of hexagones.
     */
    inline std::array<std::array<std::optional<Hexagone>,SIZE>,SIZE>  getHexagones() {
        return hexagones_;
    }

    inline bool isInsideBoard(unsigned int i, unsigned int j) const {
        return hexagones_[i][j].has_value();
    }

    inline bool containMarble(unsigned int i,unsigned int j) {
        return hexagones_[i][j]->getMarble().has_value();
    }

    inline Color getColorMarble(unsigned int i, unsigned int j) {
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
    void move(Direction & direction);

private:

    /*!
     * The marbles progress together one space at a time.
     *
     */
    void moveHorizontally(Direction & direction);

    /*!
     * the beads are progressing laterally, without modifying alignment.
     *
     */
    void moveOblique(Direction & direction);

};

}
#endif // BOARD_H
