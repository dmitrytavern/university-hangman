#include "homewidget.h"
#include "../../components/style/style.h"

HomeWidget::HomeWidget() : QWidget()
{
  QLabel *label = new QLabel("Hangman");
  label->setStyleSheet(Style::GetTitleStyleForHangman());
  label->setFont(Style::GetBerkshireSwash());
  QPushButton *gameButton = new QPushButton("Start");
  gameButton->setStyleSheet(Style::GetButtonStyleStartAndExit());
  gameButton->setFont(Style::GetBerkshireSwash());
  QPushButton *aboutButton = new QPushButton("About Dev");
  aboutButton->setStyleSheet(Style::GetButtonStyleMiddle());
  aboutButton->setFont(Style::GetBerkshireSwash());
  QPushButton *exitButton = new QPushButton("Exit");
  exitButton->setStyleSheet(Style::GetButtonStyleStartAndExit());
  exitButton->setFont(Style::GetBerkshireSwash());

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(label);
  layout->addWidget(gameButton);
  layout->addWidget(aboutButton);
  layout->addWidget(exitButton);
  layout->setAlignment(Qt::AlignCenter);
  layout->setAlignment(gameButton, Qt::AlignCenter);
  layout->setAlignment(exitButton, Qt::AlignCenter);
  connect(gameButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToStartGame(); });

  connect(aboutButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToAbout(); });

  connect(exitButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToExit(); });
}
