#include "homewidget.h"

HomeWidget::HomeWidget() : QWidget()
{
  QLabel *label = new QLabel("Home Widget");
  QPushButton *gameButton = new QPushButton("Start game");
  QPushButton *aboutButton = new QPushButton("About dev");
  QPushButton *exitButton = new QPushButton("Exit");

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(label);
  layout->addWidget(gameButton);
  layout->addWidget(aboutButton);
  layout->addWidget(exitButton);
  layout->setAlignment(Qt::AlignTop);

  connect(gameButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToStartGame(); });

  connect(aboutButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToAbout(); });

  connect(exitButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToExit(); });
}
