#include "gamestartwidget.h"
#include "../../components/style/style.h"
#include <QLineEdit>

GameStartWidget::GameStartWidget() : QWidget() {
  QVBoxLayout *layout = new QVBoxLayout(this);

  QVBoxLayout *layoutTitle = new QVBoxLayout(this);
  QLabel *labelTitle = new QLabel("Hangman");
  labelTitle->setStyleSheet(Style::GetTitleStyle());
  labelTitle->setAlignment(Qt::AlignCenter);
  labelTitle->setFont(Style::GetBerkshireSwash());

  layoutTitle->addWidget(labelTitle);

  QVBoxLayout *layoutRequest = new QVBoxLayout(this);
  QLabel *labelRequest = new QLabel("Enter names of players");
  labelRequest->setAlignment(Qt::AlignCenter);
  labelRequest->setStyleSheet(Style::GetlRequestStyle());
  labelRequest->setFont(Style::GetBerkshireSwash());
  layoutRequest->addWidget(labelRequest);

  QHBoxLayout *layoutEdits = new QHBoxLayout(this);
  QLineEdit *editNameOfPlayer1 = new QLineEdit();
  QLineEdit *editNameOfPlayer2 = new QLineEdit();
  editNameOfPlayer1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  editNameOfPlayer1->setStyleSheet(Style::GetEditStyle());
  editNameOfPlayer1->setFont(Style::GetMontserrat());
  editNameOfPlayer1->setPlaceholderText("USERNAME 1");

  editNameOfPlayer2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  editNameOfPlayer2->setStyleSheet(Style::GetEditStyle());
  editNameOfPlayer2->setFont(Style::GetMontserrat());
  editNameOfPlayer2->setPlaceholderText("USERNAME 2");

  layoutEdits->addWidget(editNameOfPlayer1);
  layoutEdits->addWidget(editNameOfPlayer2);
  layoutEdits->setContentsMargins(0, 65, 0, 65);
  layoutEdits->setSpacing(26);

  QHBoxLayout *layoutButtons = new QHBoxLayout(this);
  QPushButton *gameButton = new QPushButton("Start");
  gameButton->setFont(Style::GetBerkshireSwash());
  QPushButton *homeButton = new QPushButton("Back");
  homeButton->setFont(Style::GetBerkshireSwash());
  homeButton->setStyleSheet(Style::GetButtonStyle());
  homeButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  gameButton->setStyleSheet(Style::GetButtonStyle());
  gameButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  layoutButtons->addWidget(homeButton);
  layoutButtons->addWidget(gameButton);
  layoutButtons->setSpacing(45);

  layout->addLayout(layoutTitle);
  layout->addLayout(layoutRequest);
  layout->addLayout(layoutEdits);
  layout->addLayout(layoutButtons);
  layout->setAlignment(Qt::AlignCenter);

  connect(homeButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToHome(); });

  connect(gameButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToGame(); });
}
