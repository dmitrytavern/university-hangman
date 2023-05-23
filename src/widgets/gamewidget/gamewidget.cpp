#include "gamewidget.h"

GameWidget::GameWidget() : QWidget()
{
  QLabel *label = new QLabel("Game Widget");
  QPushButton *gameoverButton = new QPushButton("Go to GameOver");

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(label);
  layout->addWidget(gameoverButton);
  layout->setAlignment(Qt::AlignTop);

  connect(gameoverButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToGameOver(); });
}
