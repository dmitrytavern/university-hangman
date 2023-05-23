#include "aboutwidget.h"

AboutWidget::AboutWidget() : QWidget()
{
  QLabel *label = new QLabel("About Widget");
  QPushButton *startButton = new QPushButton("Back");

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(label);
  layout->addWidget(startButton);
  layout->setAlignment(Qt::AlignTop);

  connect(startButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToHome(); });
}
