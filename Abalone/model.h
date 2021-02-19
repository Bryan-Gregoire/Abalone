#ifndef MODEL_H
#define MODEL_H
#include "board.h"
#include "gameStatus.h"
#include "player.h"
#include "utils/observable.h"

/*!
 * Namespace of the Abalone project.
 */
namespace abalone {

/*!
 * Define methods that the game should implements.
 *
 */
class Model : public utils::Observable {

public:
    virtual ~Model();

    /*!
     * \brief Read accessor of the game board.
     *
     * \return The game board.
     */
    virtual Board getBoard() const;

    /*!
     * \brief Read accessor of the state of the game.
     *
     * \return the game status.
     */
    virtual GameStatus getGameStatus() const;

    /*!
     * \brief Read accessor of the current player.
     *
     * \return the current player.
     */
    virtual Player getCurrentPlayer() const;

    /*!
     * Moves a single marble or column of marbles of the same color in a given direction.
     *
     * \param direction the given direction in which to move.
     */
    virtual void move(Direction direction);

    /*!
     * notify the observer.
     *
     */
    virtual void notify() const;

    /*!
     * Notify the observer of the given property.
     *
     * \param propertyName the given name of the property.
     */
    virtual void notify(const std::string & propertyName = "No property") const;

};

}
#endif // MODEL_H