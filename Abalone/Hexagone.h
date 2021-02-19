#ifndef HEXAGONE_H
#define HEXAGONE_H
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
     * If it contains a marble.
     *
     */
    bool isFree ;

    /*!
     * One marble of one color.
     *
     */
    Marble * marble;

public :

    /*!
     * \brief Constructor.
     *
     * Does not contain a marble.
     *
     */
    Hexagone() = default;

    /*!
     * \brief Constructor.
     *
     * Contains a marble.
     *
     * \param marble cannot be null and represents only one marble.
     */
    Hexagone(Marble * marble);

    /*!
     * \brief Read accessor of isFree.
     *
     */
    inline bool getIsFree() const;

    /*!
     * \brief Read accessor of the marble.
     *
     */
    inline Marble * getMarble() const;

    /*!
     * \brief Write accessor of isFree.
     *
     */
    void setIsFree(bool isFree);

    /*!
     * \brief Write accessor of the marble.
     *
     */
    void setMarble(Marble * marble);

    /*!
     * Delete the marble.
     *
     */
    void deleteMarble();

public:
    bool getIsFree() {
        return this->isFree;
    }

    Marble * getMarble() {
        return this->marble;
    }
};

}
#endif // HEXAGONE_H
