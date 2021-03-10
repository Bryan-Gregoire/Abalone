#ifndef GAME_H
#define GAME_H
#include"Board.h"
#include"GameStatus.h"
#include "Player.h"
#include "model.h"
#include <array>

/*!
 * Namespace of the Abalone project.
 */
namespace  abalone{

/*!
 * Bring together the elements necessary for the game to present a facade to the
 * view.
 *
 */
class Game : public Model {

private :

    /*!
     * The game board.
     *
     */
    Board board_;

    /*!
     * The state of the game.
     *
     */
    GameStatus gameStatus_ = NOT_STARTED;

    /*!
     * The player whose turn it is to play.
     *
     */
    Player currentPlayer_;

    /*!
     * Players who are in the game.
     *
     */
    std::array<Player,2> players_;

public :

    /*!
     * \brief Constructor.
     *
     * \param gameStatus the state of the game.
     * \param Players who are in the game.
     */
    Game();

    /*!
     * \brief Read accessor of the game board.
     *
     * \return The game board.
     */
    inline Board & getBoard() const override;

    /*!
     * \brief Read accessor of the state of the game.
     *
     * \return the game status.
     */
    inline GameStatus & getGameStatus() const override;

    /*!
     * \brief Read accessor of the current player.
     *
     * \return the current player.
     */
    inline Player & getCurrentPlayer() const override;

    /*!
     * \brief Read accessor of the players of the game.
     *
     * \return Array of players.
     */
    inline std::array<Player,2> & getPlayers() const;

    /*!
     * Updates the status of the game.
     *
     * As long as one of the players has not won, the game continues.
     * if one of the players wins, the game is over.
     *
     */
    void updateLevelStatus();

    /*!
     * Moves a single marble or column of marbles of the same color in a given direction.
     *
     * \param direction the given direction in which to move
     */
    void move(Direction & direction) override;

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

    Board & getBoard() {
        return this->board_;
    }

    GameStatus & getGameStatus() {
        return this->gameStatus_;
    }

    Player & getCurrentPlayer() {
        return this->currentPlayer_;
    }

    std::array<Player,2> & getPlayers() {
        return this->players_;
    }
};
}
#endif // GAME_H
