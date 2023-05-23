#include "gameoverwidget.h"

GameOverWidget::GameOverWidget() : QWidget()
{
  QLabel *label = new QLabel("Game Over Widget");
  QPushButton *gameButton = new QPushButton("Go to Game");
  QPushButton *homeButton = new QPushButton("Go to Home");

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(label);
  layout->addWidget(gameButton);
  layout->addWidget(homeButton);
  layout->setAlignment(Qt::AlignTop);

  connect(homeButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToHome(); });

  connect(gameButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToGame(); });
}
