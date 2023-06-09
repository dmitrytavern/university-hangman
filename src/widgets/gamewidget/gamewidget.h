#define HOMEWIDGET_H
#include <QtWidgets>

class GameWidget : public QWidget
{
  Q_OBJECT

public:
  GameWidget();

signals:
  void GoToGameOver();
};
