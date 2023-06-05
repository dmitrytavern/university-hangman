#include "gamewidget.h"
#include "../../components/style/style.h"

GameWidget::GameWidget() : QWidget() {
  QVBoxLayout *layout = new QVBoxLayout(this);

  QList<QPushButton *> alphabetButtons;
  QPushButton *letterButton;

  //
  QLabel *label = new QLabel("Game Widget");
  layout->addWidget(label);
  //

  QGridLayout *alphabetLayout = new QGridLayout(this);
  int row = 0, col = 0;
  for (int i = 65; i <= 90; i++) {
    letterButton = new QPushButton(this);
    letterButton->setText(QString(static_cast<char>(i)));
    letterButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    letterButton->setFont(Style::GetBerkshireSwash());
    letterButton->setStyleSheet(Style::GetLetterButtonStyle());

    // connect(letterButton, &QPushButton::clicked, this,
    // &Widget::FUNCTION_NAME);

    alphabetLayout->addWidget(letterButton, row, col);
    alphabetButtons.push_back(letterButton);

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

  QPushButton *gameoverButton = new QPushButton("Go to GameOver");
  gameoverButton->setStyleSheet(Style::GetButtonStyle());
  gameoverButton->setFont(Style::GetBerkshireSwash());
  gameoverButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  layout->addLayout(alphabetLayout);
  layout->addWidget(gameoverButton);
  layout->setAlignment(Qt::AlignTop);

  connect(gameoverButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToGameOver(); });
}
