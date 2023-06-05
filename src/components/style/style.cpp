#include "style.h"
#include <QFontDatabase>
#include <QStyleOption>

Style::Style() {}

QString Style::GetBG() {
  return QString{
      "#mainwindow { border-image: "
      "url(:/resources/BGGameStartWidget.png) 0 0 0 0 stretch stretch; }"};
}

QString Style::GetButtonStyle() {
  return QString{"QPushButton {"
                 "width: 250px;"
                 "height: 63px;"
                 "background-color: rgba(217, 217, 217, 1);"
                 "font-size: 55px;"
                 "border-radius: 20px;"
                 "}"};
}

QString Style::GetTitleStyle() {
  return QString{"QLabel {"
                 "color: rgba(255, 255, 255, 1);"
                 "font-size: 85px;"
                 "}"};
}

QString Style::GetlRequestStyle() {
  return QString{"QLabel {"
                 "color: rgba(255, 255, 255, 1);"
                 "font-size: 54px;"
                 "margin-top: 27px;"
                 "}"};
}

QFont Style::GetBerkshireSwash() {
  int id = QFontDatabase::addApplicationFont("../resources/"
                                             "BerkshireSwash-Regular.ttf");
  QString font = QFontDatabase::applicationFontFamilies(id).at(0);
  QFont BerkshireSwash(font);
  return BerkshireSwash;
}

QFont Style::GetMontserrat() {
  int id =
      QFontDatabase::addApplicationFont("../resources/"
                                        "Montserrat-VariableFont_wght.ttf");
  QString font = QFontDatabase::applicationFontFamilies(id).at(0);
  QFont Montserrat(font);
  return Montserrat;
}

QString Style::GetEditStyle() {
  return QString{"QLineEdit {"
                 "width: 350px;"
                 "height: 54px;"
                 "font-size: 28px;"
                 "background-color: #1C1E2A;"
                 "color: white;"
                 "border-style: outset;"
                 "border-width: 3px;"
                 "border-radius: 30px;"
                 "border-color: white;"
                 "padding: 10 0 10 70;"
                 "background-image: url(../resources/user.svg);"
                 "background-repeat: no-repeat;"
                 "}"};
}
