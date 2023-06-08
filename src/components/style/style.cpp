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

QString Style::GetButtonStyleStartAndExit() {
  return QString{"QPushButton {"
                 "width: 300px;"
                 "height: 85px;"
                 "background-color: rgba(217, 217, 217, 1);"
                 "font-size: 60px;"
                 "border-radius: 20px;"
                 "margin-bottom: 30px"
                 "}"};
}

QString Style::GetButtonStyleMiddle() {
  return QString{"QPushButton {"
                 "width: 380px;"
                 "height: 85px;"
                 "background-color: rgba(217, 217, 217, 1);"
                 "font-size: 60px;"
                 "border-radius: 20px;"
                 "margin-bottom: 30px"
                 "}"};
}

QString Style::GetTitleStyle() {
  return QString{"QLabel {"
                 "color: rgba(255, 255, 255, 1);"
                 "font-size: 85px;"
                 "}"};
}

QString Style::GetTitleStyleForHangman() {
  return QString{"QLabel {"
                 "color: rgba(255, 255, 255, 1);"
                 "font-size: 85px;"
                 "margin-bottom: 60px;"
                 "}"};
}

QString Style::GetAboutDevTitleStyle() {
  return QString{"QLabel {"
                 "color: rgba(255, 255, 255, 1);"
                 "font-size: 85px;"
                 "margin-top: 45px;"
                 "}"};
}

QString Style::GetDevNameStyle() {
  return QString{"QLabel {"
                 "color: rgba(255, 255, 255, 1);"
                 "font-size: 40px;"
                 "margin-top: 10px;"
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

QString Style::GetLetterButtonStyle() {
  return QString{"QPushButton {"
                 "width: 60px;"
                 "height: 60px;"
                 "background: none;"
                 "font-size: 50px;"
                 "color: rgba(240, 231, 222, 0.6);"
                 "border: none;"
                 "}"};
}

QString Style::GetCorrectLetterButtonStyle() {
  return QString{"QPushButton {"
                 "color: rgba(240, 231, 222, 1);"
                 "width: 60px;"
                 "height: 60px;"
                 "background: none;"
                 "font-size: 50px;"
                 "border: none;"
                 "}"};
}

QString Style::GetWrongLetterButtonStyle() {
  return QString{"QPushButton {"
                 "width: 60px;"
                 "height: 60px;"
                 "background: none;"
                 "font-size: 50px;"
                 "border: none;"
                 "color: rgba(240, 231, 222, 0.2);"
                 "}"};
}

QString Style::GetPictureStyle(int i) {
  return QString{"QLabel {"
                 "min-height: 350px; min-width: 350px; "
                 "image: url(../resources/Hangman_" +
                 QString::number(i) +
                 ".svg);"
                 "}"};
}
QString Style::GetScullStyle() {
  return QString{"QLabel {"
                 "min-height: 250px; min-width: 250px; "
                 "image: url(../resources/BigScull.svg);"
                 "}"};
}
QString Style::GetGameOverButtonStyle() {
  return QString{"QPushButton {"
                 "width: 250px;"
                 "height: 63px;"
                 "background-color: rgba(217, 217, 217, 1);"
                 "font-size: 45px;"
                 "border-radius: 20px;"
                 "}"};
}
QString Style::GetWinStyle() {
  return QString{"QLabel {"
                 "color: rgba(255, 255, 255, 1);"
                 "font-size: 54px;"
                 "margin-top: 10px;"
                 "}"};
}
