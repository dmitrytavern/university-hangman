#include "gameoverwidget.h"
#include "../../components/controller/gamecontroller.h"
#include "../../components/style/style.h"

GameOverWidget::GameOverWidget() : QWidget() {
  QVBoxLayout *layout = new QVBoxLayout(this);
  QHBoxLayout *layoutPictureAndLabels = new QHBoxLayout(this);
  QLabel *labelScull = new QLabel(this);
  labelScull->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  labelScull->setStyleSheet(Style::GetScullStyle());

  QLabel *labelVictory = new QLabel("PLAYER");
  labelVictory->setStyleSheet(Style::GetWinStyle());
  labelVictory->setAlignment(Qt::AlignCenter);
  labelVictory->setFont(Style::GetBerkshireSwash());
  layoutPictureAndLabels->addWidget(labelScull);

  GameController::labelNameOfWinner = new QLabel(GameController::champion);
  GameController::labelNameOfWinner->setStyleSheet(Style::GetWinStyle());
  GameController::labelNameOfWinner->setAlignment(Qt::AlignCenter);
  GameController::labelNameOfWinner->setFont(Style::GetBerkshireSwash());

  QLabel *labelWin = new QLabel("WIN");
  labelWin->setStyleSheet(Style::GetWinStyle());
  labelWin->setAlignment(Qt::AlignCenter);
  labelWin->setFont(Style::GetBerkshireSwash());

  QVBoxLayout *namesLayout = new QVBoxLayout(this);
  namesLayout->addWidget(labelVictory);
  namesLayout->setSpacing(10);
  namesLayout->addWidget(GameController::labelNameOfWinner);
  namesLayout->setSpacing(10);
  namesLayout->addWidget(labelWin);
  namesLayout->setAlignment(labelWin, Qt::AlignCenter);

  layoutPictureAndLabels->addLayout(namesLayout);
  layoutPictureAndLabels->setSpacing(30);

  QHBoxLayout *layoutButtons = new QHBoxLayout(this);

  QPushButton *gameButton = new QPushButton("Retry");
  gameButton->setFont(Style::GetBerkshireSwash());
  gameButton->setStyleSheet(Style::GetGameOverButtonStyle());
  QPushButton *homeButton = new QPushButton("Exit");
  homeButton->setFont(Style::GetBerkshireSwash());
  homeButton->setStyleSheet(Style::GetGameOverButtonStyle());

  layoutButtons->addWidget(gameButton);
  layoutButtons->addWidget(homeButton);
  layoutButtons->setSpacing(30);
  layoutButtons->setContentsMargins(0, 50, 0, 0);

  layout->addLayout(layoutPictureAndLabels);
  layout->addLayout(layoutButtons);
  layout->setAlignment(Qt::AlignCenter);

  connect(homeButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToHome(); });

  connect(gameButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToGame(); });
}
