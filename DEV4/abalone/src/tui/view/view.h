#ifndef VIEW_H
#define VIEW_H

#include "board.h"
#include "player.h"
#include "utils/observer.h"
#include "game.h"
#include "utils/observable.h"

namespace abalone {

class View : public pbt::utils::Observer {

public:
    Model &modelObservable_;
    /**
     * @brief Constructor of view.
     * @param model of the game
     */
    inline View(Model &source) : modelObservable_{source} {
        source.addObserver(this);
    }

    /**
     * @brief Shows the game board.
     */
    void showBoard(Board &);

    /**
     * @brief Asks the name of the player id.
     * @return the name of player id
     */
    std::string askName(unsigned);

    /**
     * @brief Asks the movement to the player.
     * @return the movement's player
     */
    std::string askMovement(Player &);

    /**
     * @brief shows the end of the game.
     */
    void showEnd(std::array<Player, 2> &, unsigned);

    /**
     * @brief update
     * @param propertyName
     */
    void update(const std::string &propertyName) override;
};

}

#endif //VIEW_H
