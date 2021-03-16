#ifndef MODEL_H
#define MODEL_H
#include "Board.h"
#include "GameStatus.h"
#include "Player.h"
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
    //~Model();

    /*!
     * \brief Read accessor of the game board.
     *
     * \return The game board.
     */
    Board & getBoard() ;

    /*!
     * \brief Read accessor of the state of the game.
     *
     * \return the game status.
     */
    GameStatus&  getGameStatus() ;

    /*!
     * \brief Read accessor of the current player.
     *
     * \return the current player.
     */
    Player const& getCurrentPlayer() ;


    void setCurrentPlayerName(std::string name);
    /*!
     * Moves a single marble or column of marbles of the same color in a given direction.
     *
     * \param direction the given direction in which to move.
     */
    void move(Direction & direction);

    /*!
     * notify the observer.
     *
     */
    void notify() const;

    /*!
     * Notify the observer of the given property.
     *
     * \param propertyName the given name of the property.
     */
    void notify(const std::string & propertyName = "No property") const;

    /*!
      * Add the given observer.
      *
      */
    inline void addObserver(utils::Observer *);

    /*!
      * Delete the given observer.
      *
      */
    inline void deleteObserver(utils::Observer *);

};

}
#endif // MODEL_H
