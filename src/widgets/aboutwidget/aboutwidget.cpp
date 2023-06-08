#include "aboutwidget.h"
#include "../../components/style/style.h"

AboutWidget::AboutWidget() : QWidget()
{

  QVBoxLayout *layout = new QVBoxLayout(this);

  QVBoxLayout *layoutTilte = new QVBoxLayout(this);

  QLabel *labelTitle = new QLabel("About Dev");
  labelTitle->setStyleSheet(Style::GetAboutDevTitleStyle());
  labelTitle->setAlignment(Qt::AlignCenter);
  labelTitle->setFont(Style::GetBerkshireSwash());

  layoutTilte->addWidget(labelTitle);

  QVBoxLayout *layoutDevs = new QVBoxLayout(this);

  QLabel *devname_1 = new QLabel("Kyrylo Muzychka");
  devname_1->setStyleSheet(Style::GetDevNameStyle());
  devname_1->setAlignment(Qt::AlignCenter);
  devname_1->setFont(Style::GetBerkshireSwash());

  layoutDevs->addWidget(devname_1);

  QLabel *devname_2 = new QLabel("Denis Stratii");
  devname_2->setStyleSheet(Style::GetDevNameStyle());
  devname_2->setAlignment(Qt::AlignCenter);
  devname_2->setFont(Style::GetBerkshireSwash());

  layoutDevs->addWidget(devname_2);

  QLabel *devname_3 = new QLabel("Rodion Bozhok");
  devname_3->setStyleSheet(Style::GetDevNameStyle());
  devname_3->setAlignment(Qt::AlignCenter);
  devname_3->setFont(Style::GetBerkshireSwash());

  layoutDevs->addWidget(devname_3);

  QLabel *devname_4 = new QLabel("Olga Kostrenko");
  devname_4->setStyleSheet(Style::GetDevNameStyle());
  devname_4->setAlignment(Qt::AlignCenter);
  devname_4->setFont(Style::GetBerkshireSwash());

  layoutDevs->addWidget(devname_4);

  QLabel *devname_5 = new QLabel("Dmitry Tavern");
  devname_5->setStyleSheet(Style::GetDevNameStyle());
  devname_5->setAlignment(Qt::AlignCenter);
  devname_5->setFont(Style::GetBerkshireSwash());

  layoutDevs->addWidget(devname_5);

  layoutDevs->setSpacing(30);

  QVBoxLayout *layoutButton = new QVBoxLayout(this);
  QPushButton *backButton = new QPushButton();
  backButton->setStyleSheet(Style::GetAboutButtonStyle());
  backButton->setFont(Style::GetBerkshireSwash());
  backButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  layoutButton->addWidget(backButton);
  layoutButton->setAlignment(Qt::AlignCenter);
  layoutButton->setContentsMargins(0,0,890,0);

  layoutDevs->setContentsMargins(0,30,0,0);

  layout->addLayout(layoutTilte);
  layout->addLayout(layoutDevs);
  layout->addLayout(layoutButton);

  layout->setAlignment(Qt::AlignCenter);

  connect(backButton, &QPushButton::clicked, this,
          [=, this]() { emit GoToHome(); });
}
