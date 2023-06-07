#include "gamewidget.h"
#include "../../components/controller/gamecontroller.h"
#include "../../components/style/style.h"

GameWidget::GameWidget() : QWidget() {
  QVBoxLayout *layout = new QVBoxLayout(this);
  QPushButton *letterButton;
  QHBoxLayout *layoutAlphabetAndPicture = new QHBoxLayout(this);

  QGridLayout *alphabetLayout = new QGridLayout(this);
  int row = 0, col = 0;
  for (int i = 65; i <= 90; i++) {
    letterButton = new QPushButton(this);
    letterButton->setText(QString(static_cast<char>(i)));
    letterButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    letterButton->setFont(Style::GetBerkshireSwash());
    letterButton->setStyleSheet(Style::GetLetterButtonStyle());
    connect(letterButton, &QPushButton::clicked, this, [=, this]() {
      emit GameController::ClickLetter(letterButton->text());
    });
    alphabetLayout->addWidget(letterButton, row, col);
    GameController::alphabetButtons.push_back(letterButton);
    col++;
    if (col >= 7) {
      col = 0;
      row++;
    }
  }
  alphabetLayout->setContentsMargins(0, 0, 0, 0);
  alphabetLayout->setHorizontalSpacing(0);
  alphabetLayout->setVerticalSpacing(0);
  alphabetLayout->columnStretch(0);
  alphabetLayout->rowStretch(0);

  QLabel *picture = new QLabel(this);
  picture->setStyleSheet("image: url(../resources/1.png); height: 300px;");

  layoutAlphabetAndPicture->addLayout(alphabetLayout);
  layoutAlphabetAndPicture->addWidget(picture);

  QHBoxLayout *layoutButtons = new QHBoxLayout(this);

  GameController::gameoverButton = new QPushButton("Finish");
  GameController::gameoverButton->setStyleSheet(Style::GetButtonStyle());
  GameController::gameoverButton->setFont(Style::GetBerkshireSwash());
  GameController::gameoverButton->setSizePolicy(QSizePolicy::Fixed,
                                                QSizePolicy::Fixed);
  GameController::gameoverButton->setEnabled(false);

  GameController::nextButton = new QPushButton("Next");
  GameController::nextButton->setStyleSheet(Style::GetButtonStyle());
  GameController::nextButton->setFont(Style::GetBerkshireSwash());
  GameController::nextButton->setSizePolicy(QSizePolicy::Fixed,
                                            QSizePolicy::Fixed);
  GameController::nextButton->setEnabled(false);

  layoutButtons->addWidget(GameController::gameoverButton);
  layoutButtons->addWidget(GameController::nextButton);

  layout->addLayout(layoutAlphabetAndPicture);
  layout->addLayout(layoutButtons);
  layout->setAlignment(Qt::AlignCenter);

  connect(GameController::gameoverButton, &QPushButton::clicked, this,
          [=, this]() {
            GameController::ResetGame();
            emit GoToGameOver();
          });

  connect(GameController::nextButton, &QPushButton::clicked, this,
          [=, this]() { emit GameController::Next(); });
}
