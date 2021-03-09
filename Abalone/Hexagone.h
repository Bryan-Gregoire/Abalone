#ifndef HEXAGONE_H
#define HEXAGONE_H
#include <optional>
#include "marble.h"

/*!
 * Namespace of the Abalone project.
 */
namespace  abalone{

/*!
 * Hexagone on the board.
 *
 */
class Hexagone{

private :

    /*!
     * One marble of one color.
     *
     */
    std::optional<Marble> marble_;

public :

    /*!
     * \brief Constructor.
     *
     * Does not contain a marble.
     *
     */
     inline Hexagone();

    /*!
     * \brief Constructor.
     *
     * Contains a marble.
     *
     * \param marble cannot be null and represents only one marble.
     */
    inline Hexagone(Marble marble);

    /*!
     * \brief Read accessor of the marble.
     *
     */
    inline Marble getMarble() const;


    /*!
     * \brief Write accessor of the marble.
     *
     */
    void setMarble(Marble & marble);


    Marble getMarble() {
        return this->marble_.value();
    }
};

}
#endif // HEXAGONE_H
