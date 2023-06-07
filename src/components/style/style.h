#ifndef STYLE_H
#define STYLE_H
#include <QString>
#include <QFont>

class Style
{
public:
    Style();
    static QFont GetBerkshireSwash();
    static QFont GetMontserrat();
    static QString GetBG();
    static QString GetButtonStyle();
    static QString GetTitleStyle();
    static QString GetAboutDevTitleStyle();
    static QString GetDevNameStyle();
    static QString GetlRequestStyle();
    static QString GetEditStyle();
    static QString GetLetterButtonStyle();
    static QString GetCorrectLetterButtonStyle();
    static QString GetWrongLetterButtonStyle();
    static QString GetPictureStyle(int i);
};

#endif // STYLE_H
