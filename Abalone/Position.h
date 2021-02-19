#ifndef POSITION_H
#define POSITION_H
#include "direction.h"

/*!
 * Namespace of the Abalone project.
 */
namespace  abalone{

/*!
 * A position in the game board. Uses the x y z coordinate system.
 */
class Position{

private :

    /*!
     * The x-axis.
     *
     */
    int x ;

    /*!
     * The y-axis.
     *
     */
    int y ;

    /*!
     * The z-axis.
     *
     */
    int z ;

public :

    /*!
     * \brief Constructor
     *
     * \param x The x-axis.
     * \param y The y-axis.
     * \param z The z-axis.
     */
    Position(int x, int y, int z );

    /*!
     * \brief Read accessor of the x position.
     *
     */
    inline int getX() const;

    /*!
     * \brief Read accessor of the y position.
     *
     */
    inline int getY() const;

    /*!
     * \brief Read accessor of the z position.
     *
     */
    inline int getZ() const;

    /*!
     * Check if two position are equals.
     *
     */
    inline bool equals(Position position) const;

    /*!
     * Gives the position of a movement in a given direction.
     *
     */
    Position nextPos(Direction direction );

    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
    int getZ() {
        return this->z;
    }};

}
#endif // POSITION_H
