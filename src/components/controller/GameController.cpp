#include "gamecontroller.h"
#include <QObject>
#include <QPushButton>

GameController::GameController() {}

void GameController::ClickLetter(QString letter) { qDebug() << letter; }

void GameController::Next() { currentPlayer = currentPlayer == 1 ? 2 : 1; }
