#include "view.h"
#include <array>
#include "consoleColor.h"
#include <regex>

namespace abalone {

void View::showBoard(Board &board) {
    std::array<std::string, 9> abaProLetters{"I", "H", "G", "F", "E", "D", "C", "B", "A"};
    std::array<int, 9> abaProNumbers{1, 2, 3, 4, 5, 9, 8, 7, 6};

    for (size_t line = 0; line < board.board().size(); line++) {
        for (size_t col = 0; col < board.board().size(); col++) {
            if (board.at(line, col)) {
                if (col != 0 && !board.at(line, col - 1)) {
                    std::cout << blue << abaProLetters[line] << reset << "  ";
                } else if (col == 0) {
                    if (line == 4) {
                        std::cout << blue << abaProLetters[line] << reset << "  ";
                    } else {
                        for (unsigned long long i = 0; i < (line % 9) - 4; i++) {
                            std::cout << " ";
                        }
                        std::cout << blue << abaProLetters[line] << reset << "  ";
                    }
                }
                if (board.at(line, col)->ball()) {
                    if (board.at(line, col)->ball()->color() == Color::BLACK) {
                        std::cout << gray << "N " << reset;
                    } else {
                        std::cout << white << "B " << reset;
                    }
                } else {
                    std::cout << "* ";
                }
            } else if (board.at(line, col)) {
                std::cout << " " << blue << abaProLetters[line] << reset << "  ";
            } else if (col < 5) {
                std::cout << " ";
            }
        }
        if (line > 4) {
            std::cout << " " << blue << abaProNumbers[line] << reset;
        }
        std::cout << " " << std::endl;
    }
    std::cout << "       ";
    for (size_t nb = 0; nb < 5; nb++) {
        std::cout << " " << blue << abaProNumbers[nb] << reset;
    }
    std::cout << std::endl;
}

std::string View::askName(unsigned idPlayer) {
    std::string name;
    // Checks if the name contains number,
    // see all before and after characters that contain numbers
    std::regex regNumber(".*[0-9]+.*");
    do {
        std::cout << "Veuillez indiquer le nom pour le joueur "
                  << idPlayer + 1 << " : " << std::endl;
        std::cin >> name;
    } while (std::regex_match(name, regNumber));
    return name;
}

std::string View::askMovement(Player &player) {
    std::string movement;
    std::cout << "Veuillez choisir un mouvement " << player.name()
              << " (" << (player.id() == 1 ? "noir" : "blanc") << ")"
              << " : " << std::endl;
    std::cin >> movement;
    transform(movement.begin(), movement.end(), movement.begin(), ::toupper);
    return movement;
}

void View::showEnd(std::array<Player, 2> &players, unsigned moves) {
    Player winner{ players.at(0).nbBall() == 8
                    ? players.at(1)
                    : players.at(0)};
        std::cout << green << "Félicitations à "
                  << winner.name() << " qui a gagné avec "
                  << winner.nbBall() << " balles et "
                  << moves << " mouvements !" << white << std::endl;
}

void View::update(const std::string &propertyName) {
    if (propertyName == modelObservable_.PROPERTY_BOARD) {
        showBoard(modelObservable_.board());
    }

    if (propertyName == modelObservable_.PROPERTY_ACTIONSTATUS) {
        if (modelObservable_.lastActionStatus() == ActionStatus::FALLEN) {
            std::cout << green << "Vous avez fait tombé une bille adverse !" << reset << std::endl;
        } else if (modelObservable_.lastActionStatus() == ActionStatus::MOVED) {
            std::cout << green << "Vous vous êtes correctement déplacé !" << reset << std::endl;
        } else if (modelObservable_.lastActionStatus() == ActionStatus::PUSHED) {
            std::cout << green << "Vous avez poussé une bille ennemie !" << reset << std::endl;
        } else if (modelObservable_.lastActionStatus() == ActionStatus::SELF_FALLEN) {
            std::cout << red << "Vous avez fait tombé votre propre bille !" << reset << std::endl;
        } else {
            std::cerr << red << "Erreur de mouvement, veuillez réessayer." << reset << std::endl;
        }
    }

    if (propertyName == modelObservable_.PROPERTY_ENDGAME) {
        showEnd(modelObservable_.players(), modelObservable_.totalMoves());
    }
}
}
