#define HOMEWIDGET_H
#include <QtWidgets>

class AboutWidget : public QWidget
{
  Q_OBJECT

public:
  AboutWidget();

signals:
  void GoToHome();
};
