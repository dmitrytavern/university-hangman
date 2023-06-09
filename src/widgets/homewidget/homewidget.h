#define HOMEWIDGET_H
#include <QtWidgets>

class HomeWidget : public QWidget
{
  Q_OBJECT

public:
  HomeWidget();

signals:
  void GoToStartGame();
  void GoToAbout();
  void GoToExit();
};
