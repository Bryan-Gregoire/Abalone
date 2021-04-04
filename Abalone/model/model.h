#ifndef MODEL_H
#define MODEL_H
#include "Board.h"
#include "GameStatus.h"
#include "Player.h"
#include "utils/observable.h"
#include <vector>

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
    virtual ~Model() = default;

    /*!
     * \brief Read accessor of the game board.
     *
     * \return The game board.
     */
    virtual inline Board const& getBoard() = 0;

    /*!
     * \brief Read accessor of the state of the game.
     *
     * \return the game status.
     */
    virtual inline GameStatus const&  getGameStatus() = 0;

    /*!
     * \brief Read accessor of the current player.
     *
     * \return the current player.
     */
    virtual inline Player const& getCurrentPlayer() = 0;

    /*!
     * \brief Read accessor of the players of the game.
     *
     * \return Array of players.
     */
    virtual inline std::array<Player,2> getPlayers() = 0;

    /*!
     * \brief Write accessor of the name of the current player.
     *
     * After giving the name to the current player, we change the
     * current player to the next one.
     *
     * \param name the name to set.
     */
    virtual void setCurrentPlayerName(const std::string name) = 0;

    /*!
     * \brief Write accessor of the status of the game.
     *
     * \param gameStatus the given status to write.
     */
    virtual inline void setGameStatus(GameStatus const& gameStatus_) = 0;

    /*!
     * \brief pass the turn of the current player.
     *
     */
    virtual inline void switchCurrentPlayer() = 0;

    /*!
     * @brief get the status of the player at the given index.
     *
     * @param index of the player.
     *
     * @return the PlayerStatus of the player.
     */
    virtual inline PlayerStatus getIdxPlayerStatus(unsigned int index) const = 0;

    /*!
     * @brief get the name of the player at the given index.
     *
     * @param index of the player.
     *
     * @return the name of the player.
     */
    virtual inline std::string getIdxPlayerName(unsigned int index) const = 0;

    /*!
     * @brief Checks the content of the game board at the given position.
     *
     * Check if the selected ball(s) belong to the current player.
     *
     * If the move is in line, check that there are no opposing balls in front.
     *
     * @param pos the given positions.
     *
     * @return 'true' if the content of the game board at the given positions allows us to move otherwise 'false'.
     *
     * @throw std::invalid_argument if the number of components of the vector is not 4 or 6.
     *
     */
    virtual bool checkContentPositions(std::vector<int> const& pos) const = 0;

    /*!
     * \brief Check if the position to move is correct.
     *
     * \param position the given positions.
     * \return
     *
     * @throw std::invalid_argument if the number of components of the vector is not 4 or 6.
     */
    virtual bool checkGoodMovePos(std::vector<int> const& position) const = 0;

    /*!
     * Moves a single marble or column of marbles of the same color in a given direction.
     *
     * If the size of the vector is 4, it is a move in line.
     * If the size of the vector is 6, it is a lateral move.
     *
     * \param direction the given direction in which to move
     *
     * @throw std::invalid_argument if the number of components of the vector is not 4 or 6.
     */
    virtual void move(std::vector<int> & positions) = 0;

    /*!
     * notify the observer.
     *
     */
    virtual void notify() const = 0;

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
