#include "view.h"
#include "ui_view.h"

#include <cmath>
#include <QDebug>
#include <QGraphicsScene>
#include "controller/controller.h"

View::View(QWidget * parent) :
    QMainWindow(parent),
    scene_{new QGraphicsScene()},
    view_{new QGraphicsView(scene_)},
    ui(new Ui::View),
    _gHexaCells{}
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(view_);
    this->setWindowTitle("Abalone - Chahed & Dylan");
    this->setWindowIcon(QIcon(":/resources/favicon.png"));
    this->setFixedSize(this->width(), this->height());
}

View::~View()
{
   delete ui;
}

void View::showBoard()
{
    std::array<std::string, 9>
    abaProLetters{"I", "H", "G", "F", "E", "D", "C", "B", "A"};
    std::array<int, 9> abaProNumbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
    double radius{50};
    double lHex{sqrt(3) * radius};
    int countCol{};
    int countLine{};
    std::string s;

    for (int line = board().size() / 2; line >= 0; line--) {
        for (size_t col = 0; col < board().size(); col++) {
            if (!modelObs().board().at(line, col)) {
                continue;
            }
            double y{lHex * (col - countCol)};
            size_t x{board().size() - 1 - line};

            if (line % 2 == 0) {
                s = abaProLetters.at(line)
                        + std::to_string(abaProNumbers.at(col));
                _gHexaCells.push_back(new GHexaCell(line * (radius * 1.5),
                                                    y, radius, s,
                                                    modelObs().board().at(line, col)->ball()));
                if (line != 4) {
                    s = abaProLetters.at(x)
                            + std::to_string(abaProNumbers.at(col - countLine));
                    _gHexaCells.push_back(new GHexaCell(x * (radius * 1.5),
                                                        y - countLine, radius, s,
                                                        modelObs().board().at(x, col - countLine)->ball()));
                }
            } else {
                s = abaProLetters.at(line) + std::to_string(
                            abaProNumbers.at(col));
                _gHexaCells.push_back(new GHexaCell(line * (radius * 1.5),
                                                    y + lHex / 2, radius, s,
                                                    modelObs().board().at(line, col)->ball()));
                s = abaProLetters.at(x) + std::to_string(
                            abaProNumbers.at(col - countLine));
                _gHexaCells.push_back(new GHexaCell(x * (radius * 1.5),
                                                    y - countLine + lHex / 2, radius, s,
                                                    modelObs().board().at(x, col - countLine)->ball()));
            }
        }

        if (line % 2 == 0) {
            countCol++;
        }
        countLine++;
    }

    std::for_each(begin(_gHexaCells),
                  end(_gHexaCells), [this](GHexaCell * e) {
        e->setPos(e->y(), e->x());
        scene_->addItem(e);
        QObject::connect(e, SIGNAL(sendValue(std::string)), this,
                         SLOT(my_on_ghexacell_clicked(std::string)));
    });
}

void View::updateEnd(bool isEnd)
{
    if (isEnd) {
        scene_->clear();
        _gHexaCells.clear();
        layout()->removeWidget(ui->pushButton);
        delete ui->pushButton;
    } else {
        givenInfo.clear();
        updateBoard();
    }
}

void View::my_on_ghexacell_clicked(std::string value)
{
    auto it = std::find(givenInfo.begin(), givenInfo.end(), value);
    if (it != givenInfo.end()) {
        givenInfo.erase(it);
    } else {
        givenInfo.push_back(value);
    }
}

void View::inscription()
{
    QString lineEditBlack = ui->lineEditBlack->text();
    std::string playerBlackName = lineEditBlack.toLocal8Bit().constData();
    givenInfo.push_back(playerBlackName);

    QString textEditWhite = ui->lineEditWhite->text();
    std::string playerWhiteName = textEditWhite.toLocal8Bit().constData();
    givenInfo.push_back(playerWhiteName);
}

void View::on_pushButton_clicked()
{
    // Checks if the name of black player is empty
    if (ui->playerBlack->text().size() == 0) {
        inscription();
    }

    controller_->buttonHandler(givenInfo);

    if (ui->playerBlack->text().size() == 0) {
        givenInfo.clear();
    }
}

std::array<std::array<std::optional<abalone::Hexagon>, 9>, 9> &
View::board() const
{
    return controller_->game().board().board();
}

abalone::Model & View::modelObs() const
{
    return controller_->game();
}

void View::defineLabel(std::string str)
{
    ui->label->setStyleSheet("color: red");
    if (str == controller_->NOT_POSSIBLE_DISPLACMENT) {
        ui->label->setText("Ce déplacement n'est pas possible"
                           ", merci de réessayer.");
    } else if (str == controller_->BLOCKED) {
        ui->label->setText("Vous êtes bloqués !");
    } else if (str == controller_->NOT_DISPLACEMENT_CHECK_COORD) {
        ui->label->setText("Ce déplacement n'est pas possible, "
                           "merci de vérifier vos coordonnées !");
    } else if (str == controller_->NOT_VALID_NAME) {
        ui->label->setText("Un des noms renseigné n'est pas valide, "
                           "merci de vérifier.");
    }
}

void View::updateInfoPlayer(abalone::Player & player, int nbBalls)
{
    std::string takes{"Prise : "};
    takes.append(std::to_string(nbBalls));

    if (player.id() == 1) {
        ui->playerBlack->setText(player.name().c_str());
        ui->playerBlackTake->setText(takes.c_str());
    } else {
        ui->playerWhite->setText(player.name().c_str());
        ui->playerWhiteTake->setText(takes.c_str());
    }
}

void View::names(std::vector<std::string> & names)
{
    ui->playerBlack->setText(QString::fromStdString(names.at(0)));
    ui->playerWhite->setText(QString::fromStdString(names.at(1)));
    ui->playerBlackTake->setText("Prise : 0");
    ui->playerWhiteTake->setText("Prise : 0");
    ui->pushButton->setText("Jouer un coup !");
    ui->label->setText("C'est au joueur noir de commencer !");
    ui->label->setStyleSheet("color: black");
    selectCurrentPlayer(1);
    layout()->removeWidget(ui->labelBlack);
    layout()->removeWidget(ui->labelWhite);
    layout()->removeWidget(ui->lineEditBlack);
    layout()->removeWidget(ui->lineEditWhite);
    delete ui->labelBlack;
    delete ui->labelWhite;
    delete ui->lineEditBlack;
    delete ui->lineEditWhite;
    givenInfo.clear();
    updateBoard();
}

void View::selectCurrentPlayer(int idPlayer)
{
    if (idPlayer == 1) {
        ui->playerWhite->setStyleSheet("color: black");
        ui->playerBlack->setStyleSheet("color: blue");
    } else {
        ui->playerBlack->setStyleSheet("color: black");
        ui->playerWhite->setStyleSheet("color: blue");
    }
}

void View::update(const std::string & propertyName)
{
    if (propertyName == modelObs().PROPERTY_BOARD) {
        updateBoard();
    }

    if (propertyName == modelObs().PROPERTY_ACTIONSTATUS) {
        ui->label->setStyleSheet("color: green");
        if (modelObs().lastActionStatus() == abalone::ActionStatus::FALLEN) {
            ui->label->setText("Vous avez fait tombé une bille adverse !");
        } else if (modelObs().lastActionStatus()
                   == abalone::ActionStatus::MOVED) {
            ui->label->setText("Vous vous êtes correctement déplacé !");
        } else if (modelObs().lastActionStatus()
                   == abalone::ActionStatus::PUSHED) {
            ui->label->setText("Vous avez poussé une bille ennemie !");
        } else if (modelObs().lastActionStatus()
                   == abalone::ActionStatus::SELF_FALLEN) {
            ui->label->setStyleSheet("color: red");
            ui->label->setText("Vous avez fait tombé votre propre bille !");
        } else {
            ui->label->setStyleSheet("color: red");
            ui->label->setText("Erreur de mouvement, veuillez réessayer.");
        }
    }

    if (propertyName == modelObs().PROPERTY_ENDGAME) {
        ui->label->setStyleSheet("color: green");
        abalone::Player winner{modelObs().players().at(0).nbBall() == 8
                    ? modelObs().players().at(1)
                    : modelObs().players().at(0)};
                               std::string str{"Bravo à "};
                                                  str.append(winner.name())
                                                      .append(" ! Il/elle a gagné en ")
                                                      .append(std::to_string(modelObs().totalMoves()))
                                                      .append(" coups !");
                                                      ui->label->setText(str.c_str());
                              }
    }
