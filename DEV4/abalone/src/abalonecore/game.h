#ifndef GAME_H
#define GAME_H

#include "model.h"
#include "player.h"

namespace abalone {
/**
* @brief assembles all the elements of the abalone game already codded and defines players,
* the mechanism of the game... This class is used with the Model interface.
*/
class Game : public Model {
    size_t currentPlayer_;
    Board board_;
    std::array<Player, 2> players_;
    GameStatus status_;
    ActionStatus lastActionStatus_;
    unsigned totalMoves_;
    int nbMaxBall_;

public:
    /**
    * @brief constructor of game.
    */
    Game() :
        currentPlayer_{1},
        board_{Board{}},
        players_{std::array < Player, 2 > {Player{1}, Player{2}}},
        status_{GameStatus::NOT_STARTED},
        lastActionStatus_{ActionStatus::NOT_STARTED},
        totalMoves_{0},
        nbMaxBall_{14}
    {}

    /**
    * @brief Getter of current player.
    * @return the current player
    */
    inline Player &currentPlayer() override {
        return players_[currentPlayer_ - 1];
    }

    /**
     * @brief Getter of nbMaxBall.
     * @return max ball in the game
     */
    inline int nbMaxBall() const override {
        return nbMaxBall_;
    }

    /**
    * @brief Switches the Player to play.
    */
    inline void togglePlayer() override {
        currentPlayer_ = currentPlayer_ == 1 ? 2 : 1;
    }

    /**
    * @brief Switches the Player to play.
    */
    inline std::array<Player, 2> &players() override {
        return players_;
    }

    /**
    * @brief Getter of board.
    * @return the board of the game
    */
    inline Board &board() override {
        return board_;
    }

    /**
    * @brief Getter of GameStatus.
    * @return GameStatus of the game
    */
    inline GameStatus gameStatus() const override {
        return status_;
    }

    /**
     * @brief Getter of lastActionStatus.
     * @return lastActionStatus of the game
     */
    inline ActionStatus lastActionStatus() const override {
        return lastActionStatus_;
    }

    /**
    * @brief Setter of GameStatus.
    * @param gameStatus the given GameStatus
    */
    inline void gameStatus(GameStatus gameStatus) override {
        status_ = gameStatus;
    }

    /**
    * @brief Getter the total number of movements.
    * @return the total number of movements
    */
    inline unsigned totalMoves() const override {
        return totalMoves_;
    }

    /**
    * @brief Adds a movement.
    */
    inline void addMoves() override {
        totalMoves_++;
    }

    /**
    * @brief Checks if the game is over. The game is over when a player
    * has successfully pushed 6 balls
    * from the opposing player and if the GameStatus is finish.
    */
    inline bool isEnd() override {
        bool isEnd = players_[0].nbBall() == 8
                || players_[1].nbBall() == 8;
        if (isEnd) {
            notify(PROPERTY_ENDGAME);
        }
        return isEnd;
    }

    /**
    * @brief Moves the ball according to the starting position of the given ball
    * and the destination position of the given ball.
    * @param Positions list of position, if 3 it will be lateral movement,
    * 2 line movement and throws exception otherwise
    * @return the actionStatus of the movement
    */
    inline ActionStatus move(std::vector <Position> positions) override {
        if (positions.size() == 2 || positions.size() == 3) {
            // Checks that in the starting position there is a ball and that it is
            // to the current player. Then check if there is a ball at the destination
            // position, if so we check that it is in the current player otherwise
            // it is that the position is free. If these cases are not respected,
            // we cannot make the move.
            if (!((board_.at(positions.at(0))->ball()
                   && board_.at(positions.at(0))->ball()->playerId() == currentPlayer().id())
                  && (!board_.at(positions.at(1))->ball()
                      || (board_.at(positions.at(1))->ball()
                          && board_.at(positions.at(1))->ball()->playerId()
                          == currentPlayer().id())))) {
                throw std::invalid_argument("Selected balls are not at current player.");
            }

            lastActionStatus_ = positions.size() == 2
                    ? board_.moveLine(positions.at(0), positions.at(1))
                    : board_.moveLateral(positions.at(0), positions.at(1), positions.at(2));
            notify(PROPERTY_ACTIONSTATUS);
            notify(PROPERTY_BOARD);
            return lastActionStatus();
        }
        throw std::invalid_argument("Number of position must be 2 or 3.");
    }

    /**
    * @brief Converts ABA-PRO notation to array position (x,y).
    * @param ABACoord ABA-PRO notation
    * @return the array position converted
    */
    inline Position convertABAToCoord(std::string ABACoord) override {
        return board_.convertABAToCoord(ABACoord);
    }
};
}

#endif // GAME_H
