#include "gamestartwidget.h"
#include <QLineEdit>

GameStartWidget::GameStartWidget() : QWidget() {
  QVBoxLayout *layout = new QVBoxLayout(this);

  //
  QLabel *label = new QLabel("Game Start Widget");
  layout->addWidget(label);
  //

  QVBoxLayout *layoutTitle = new QVBoxLayout(this);
  QLabel *labelTitle = new QLabel("Hangman");
  layoutTitle->addWidget(labelTitle);

  QVBoxLayout *layoutRequest = new QVBoxLayout(this);
  QLabel *labelRequest = new QLabel("Enter names of players");
  layoutRequest->addWidget(labelRequest);

  QHBoxLayout *layoutEdits = new QHBoxLayout(this);
  QLineEdit *editNameOfPlayer1 = new QLineEdit("USERNAME1");
  QLineEdit *editNameOfPlayer2 = new QLineEdit("USERNAME2");
  layoutEdits->addWidget(editNameOfPlayer1);
  layoutEdits->addWidget(editNameOfPlayer2);

  QHBoxLayout *layoutButtons = new QHBoxLayout(this);
  QPushButton *gameButton = new QPushButton("Start (Go to Game)");
  QPushButton *homeButton = new QPushButton("Back (Go to Home)");
  layoutButtons->addWidget(homeButton);
  layoutButtons->addWidget(gameButton);

  layout->addLayout(layoutTitle);
  layout->addLayout(layoutRequest);
  layout->addLayout(layoutEdits);
  layout->addLayout(layoutButtons);
  layout->setAlignment(Qt::AlignTop);

  connect(homeButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToHome(); });

  connect(gameButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToGame(); });
}
