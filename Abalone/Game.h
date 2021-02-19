#ifndef GAME_H
#define GAME_H
#include"board.h"
#include"gameStatus.h"
#include "player.h"
#include "model.h"
#include "utils/observable.h"

namespace  abalone{

class Game : public Model, public utils::Observable {

private :
Board board;
GameStatus gameStatus;
Player currentPlayer;
Player players[];

public :
    Game(Board board, GameStatus gameStatus, Player players[]);
    inline Board getBoard() const override;
    inline GameStatus getGameStatus() const override;
    inline Player getCurrentPlayer() const override;
    inline Player * getPlayers() const;
    void updateLevelStatus();
    void move(Direction direction) override;
    void notify();

    Board getBoard() {
        return this->board;
    }

    GameStatus getGameStatus() {
        return this->gameStatus;
    }

    Player getCurrentPlayer() {
        return this->currentPlayer;
    }

    Player * getPlayers() {
        return this->players;
    }
};
}
#endif // GAME_H
