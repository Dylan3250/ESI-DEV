#include "controller.h"
#include "consoleColor.h"

namespace abalone {

void Controller::start() {
    game_.players().at(0).name(view_.askName(0));
    game_.players().at(1).name(view_.askName(1));
    view_.showBoard(game_.board());
    while (!game_.isEnd()) {
        ActionStatus resultMove;
        std::string movement;
        std::vector <Position> ABACoords;
        while (true) {
            try {
                ABACoords.clear();
                movement = view_.askMovement(game_.currentPlayer());
                for (size_t i = 0; i < movement.size(); i += 2) {
                    std::string currentMove = movement.substr(i, 2);
                    ABACoords.push_back(game_.convertABAToCoord(currentMove));
                }

                if (ABACoords.size() == 2 || ABACoords.size() == 3) {
                    resultMove = game_.move(ABACoords);
                    if (resultMove == ActionStatus::BLOCKED) {
                        continue;
                    }
                    break;
                }
            } catch (const std::exception &e) {
                std::cerr << red << "Erreur de mouvement, veuillez réessayer."
                          << reset << std::endl;
            }
        }

        if (resultMove == ActionStatus::SELF_FALLEN) {
            game_.currentPlayer().decreaseNbBall();
        }
        game_.togglePlayer();
        if (resultMove == ActionStatus::FALLEN) {
            game_.currentPlayer().decreaseNbBall();
        }
        game_.addMoves();
    }
}

}

