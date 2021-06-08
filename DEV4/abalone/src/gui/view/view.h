#ifndef VIEW_H
#define VIEW_H

#include "libs/ghexacell.h"
#include "utils/observer.h"
#include <cmath>
#include <QMainWindow>
#include <QGraphicsView>

namespace abalone
{
class Controller;
}

namespace Ui
{
class View;
}

class View : public QMainWindow, public pbt::utils::Observer
{
    Q_OBJECT

  public:
    QGraphicsScene * scene_;
    explicit View(QWidget * parent = nullptr);
    std::vector<std::string> givenInfo;
    QGraphicsView * view_;
    ~View();
    abalone::Controller * controller_ = nullptr;
    /**
     * @brief Setter of controller.
     * @param ctrl controller.
     */
    inline void controller(abalone::Controller * ctrl)
    {
        controller_ = ctrl;
        modelObs().addObserver(this);
    }

    /**
     * @brief Board of game.
     * @return the board of game.
     */
    std::array<std::array<std::optional<abalone::Hexagon>, 9>, 9> & board()
    const;

    /**
     * @brief Getter of model.
     * @return model
     */
    abalone::Model & modelObs() const;

    /**
     * @brief Sets the label with a message.
     */
    void defineLabel(std::string);

    /**
     * @brief updates player information.
     */
    void updateInfoPlayer(abalone::Player &, int);

    /**
     * @brief Adapts the label according to the current player.
     */
    void selectCurrentPlayer(int);

    /**
    * @brief Shows the game board.
    */
    void showBoard();

    /**
     * @brief updates the board when the games is finished.
     */
    void updateEnd(bool);

    /**
     * @brief updates the board.
     */
    inline void updateBoard()
    {
        scene_->clear();
        _gHexaCells.clear();
        showBoard();
        view_->update();
    }

    /**
     * @brief update
     */
    void update(const std::string &) override;

    /**
     * @brief Manages the inscription of players.
     */
    void inscription();

    /**
     * @brief Manages the start of the game after registration.
     */
    void names(std::vector<std::string> &);

    private slots:
    /**
     * @brief Manages the ghexacell when its clicked.
     */
    void my_on_ghexacell_clicked(std::string);

    /**
     * @brief See if the registration went well when its clicked.
     */
    void on_pushButton_clicked();

    private:
    Ui::View * ui;
    std::vector<GHexaCell *> _gHexaCells;
};

#endif // VIEW_H
