#define HOMEWIDGET_H
#include <QtWidgets>

class GameOverWidget : public QWidget
{
  Q_OBJECT

public:
  GameOverWidget();

signals:
  void GoToHome();
  void GoToGame();
};
