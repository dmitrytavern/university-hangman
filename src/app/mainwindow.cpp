#include "mainwindow.h"
#include "../components/style/style.h"
#include "../widgets/aboutwidget/aboutwidget.h"
#include "../widgets/gameoverwidget/gameoverwidget.h"
#include "../widgets/gamestartwidget/gamestartwidget.h"
#include "../widgets/gamewidget/gamewidget.h"
#include "../widgets/homewidget/homewidget.h"

MainWindow::MainWindow() : QWidget() {
  HomeWidget *homeWidget = new HomeWidget();
  GameWidget *gameWidget = new GameWidget();
  AboutWidget *aboutWidget = new AboutWidget();
  GameOverWidget *gameOverWidget = new GameOverWidget();
  GameStartWidget *gameStartWidget = new GameStartWidget();

  QStackedWidget *stackedWidget = new QStackedWidget();
  stackedWidget->addWidget(homeWidget);
  stackedWidget->addWidget(aboutWidget);
  stackedWidget->addWidget(gameWidget);
  stackedWidget->addWidget(gameOverWidget);
  stackedWidget->addWidget(gameStartWidget);
  stackedWidget->setCurrentWidget(homeWidget);

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(stackedWidget);

  this->setObjectName("mainwindow");
  this->setStyleSheet(Style::GetBG());

  QObject::connect(homeWidget, &HomeWidget::GoToStartGame, [=, this]() {
    stackedWidget->setCurrentWidget(gameStartWidget);
  });

  QObject::connect(homeWidget, &HomeWidget::GoToAbout, [=, this]() {
    stackedWidget->setCurrentWidget(aboutWidget);
  });

  QObject::connect(aboutWidget, &AboutWidget::GoToHome, [=, this]() {
    stackedWidget->setCurrentWidget(homeWidget);
  });

  QObject::connect(gameStartWidget, &GameStartWidget::GoToHome, [=, this]() {
    stackedWidget->setCurrentWidget(homeWidget);
  });

  QObject::connect(gameStartWidget, &GameStartWidget::GoToGame, [=, this]() {
    stackedWidget->setCurrentWidget(gameWidget);
  });

  QObject::connect(gameWidget, &GameWidget::GoToGameOver, [=, this]() {
    stackedWidget->setCurrentWidget(gameOverWidget);
  });

  QObject::connect(gameOverWidget, &GameOverWidget::GoToGame, [=, this]() {
    stackedWidget->setCurrentWidget(gameWidget);
  });

  QObject::connect(gameOverWidget, &GameOverWidget::GoToHome, [=, this]() {
    stackedWidget->setCurrentWidget(homeWidget);
  });

  QObject::connect(homeWidget, &HomeWidget::GoToExit, [=, this]() { exit(0); });
}
