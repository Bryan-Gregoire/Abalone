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
    GameStatus gameStatus_;

    unsigned int idx_CurrentPlayer;

    /*!
     * Players who are in the game.
     *
     */
    std::array<Player,2> players_;

public :

    virtual ~Game();

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
    inline Board const& getBoard() {
        return this->board_;
    }
    /*!
     * \brief Read accessor of the state of the game.
     *
     * \return the game status.
     */
    inline GameStatus const& getGameStatus()  {
        return this->gameStatus_;
    }

    /*!
     * \brief Read accesor of the index of the current player.
     *
     * \return the index.
     */
    inline unsigned int getIndexCurrentPlayer() {
        return idx_CurrentPlayer;
    }

    /*!
     * \brief Read accessor of the current player.
     *
     * \return the current player.
     */
    inline Player & getCurrentPlayer()  {
        return this->players_[idx_CurrentPlayer];
    }

    /*!
     * \brief Read accessor of the players of the game.
     *
     * \return Array of players.
     */
    inline std::array<Player,2>  getPlayers() {
        return this->players_;
    }

    /*!
     * \brief Write accessor of the name of the current player.
     *
     * After giving the name to the current player, we change the
     * current player to the next one.
     *
     * \param name the name to set.
     */
    inline void setCurrentPlayerName(std::string name){
        players_[idx_CurrentPlayer].setName(name);
        switchCurrentPlayer();
    }

    /*!
     * \brief Write accessor of the status of the game.
     *
     * \param gameStatus the given status to write.
     */
    inline void setGameStatus(GameStatus const& gameStatus) {
        this->gameStatus_ = gameStatus;
    }

    /*!
     * \brief pass the turn of the current player.
     *
     */
    inline void switchCurrentPlayer() {
        idx_CurrentPlayer == 0 ? idx_CurrentPlayer++ : idx_CurrentPlayer--;
    }

    /*!
     * @brief get the status of the player at the given index.
     *
     * @param index of the player.
     *
     * @return the PlayerStatus of the player.
     */
    inline PlayerStatus getIdxPlayerStatus(unsigned int index) const {
        if(index >= players_.size()) {
            throw std::invalid_argument("index of this player does not exist");
        }
        return players_.at(index).getPlayerStatus();
    }

    /*!
     * @brief get the name of the player at the given index.
     *
     * @param index of the player.
     *
     * @return the name of the player.
     */
    inline std::string getIdxPlayerName(unsigned int index) const {
        if(index >= players_.size()) {
            throw std::invalid_argument("index of this player does not exist");
        }
        return players_.at(index).getName();
    }

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
    bool checkContentPositions(std::vector<int> const& pos) const;

    /*!
     * \brief Check if the position to move is correct.
     *
     * \param position the given positions.
     * \return
     *
     * @throw std::invalid_argument if the number of components of the vector is not 4 or 6.
     */
    bool checkGoodMovePos(std::vector<int> const& position) const;

    bool checkYMovePos(int row, int col, int x, int y) const;

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
     * If the size of the vector is 4, it is a move in line.
     * If the size of the vector is 6, it is a lateral move.
     *
     * \param direction the given direction in which to move
     *
     * @see board_.move(std::vector<int> positions)
     *
     * @throw std::invalid_argument if the number of components of the vector is not 4 or 6.
     */
    void move(std::vector<int> & positions) ;

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

private:
    /*!
     * \brief Check if at the given position the color of the ball is the same as the current player.
     *
     * \param row the row in the game board.
     * \param col the column in the game board.
     *
     * \return true if the color of the marble is the same as the current player otherwise false.
     */
    inline bool isColorCurrPlayer(int row, int col) const;

    /*!
     * \brief Check if one of the players has lost.
     *
     * If one of the players has lost, the player status is updated.
     *
     */
    inline void updatePlayerStatus();

};
}
#endif // GAME_H
