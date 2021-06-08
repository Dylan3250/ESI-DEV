#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"
#include "view/view.h"
#include <regex>

namespace abalone {
/**
 * @brief The Controller class allows to link the model and the view.
 * It manages the game mechanism for the graphic version .
 */
class Controller {
    Model &game_;
    View &view_;

public:
    inline static const std::string NOT_POSSIBLE_DISPLACMENT{"Displacement"};
    inline static const std::string BLOCKED{"Blocked"};
    inline static const std::string NOT_DISPLACEMENT_CHECK_COORD{"CheckCoord"};
    inline static const std::string NOT_VALID_NAME{"NameNotValid"};

    /**
     * @brief Constructor of Controller.
     * @param game game
     * @param view view of the game
     */
    Controller(Model &game, View &view) :
        game_{game}, view_{view} {
    }

    /**
     * @brief Setter of game.
     * @param game game
     */
    void game(Game &game) {
        game_ = game;
    }

    /**
     * @brief Getter of game.
     * @return the game
     */
    Model &game() const {
        return game_;
    }

    /**
     * @brief Starts the game.
     */
    void start();

    /**
     * @brief Allows to execute an action when the button is pressed.
     * If the players have filled in their names correctly, they can start playing.
     * @param informations collected representing the names of the players
     */
    inline void buttonHandler(std::vector<std::string> & informations) {
        game_.players().at(0).name().empty()
                ? inscription(informations)
                : makeAction(informations);
    }

    /**
     * @brief Allows you to check if the players' names are valid.
     * @param names collected representing the names of the players
     */
    inline void inscription(std::vector<std::string> & names) {
        std::regex regNumber(".*[0-9]+.*");
        for (const auto & name : names) {
            if (name.empty() || std::regex_match(name, regNumber)) {
                view_.defineLabel(NOT_VALID_NAME);
                return;
            }
        }
        game_.players().at(0).name(names.at(0));
        game_.players().at(1).name(names.at(1));
        view_.names(names);
    }

    /**
     * @brief Manages the game mechanism.
     */
    void makeAction(std::vector<std::string> &);
};

}

#endif //CONTROLLER_H
