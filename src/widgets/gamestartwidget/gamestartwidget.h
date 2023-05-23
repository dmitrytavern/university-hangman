#define HOMEWIDGET_H
#include <QtWidgets>

class GameStartWidget : public QWidget
{
  Q_OBJECT

public:
  GameStartWidget();

signals:
  void GoToHome();
  void GoToGame();
};
