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
    static QString GetlRequestStyle();
    static QString GetEditStyle();
    static QString GetLetterButtonStyle();

};

#endif // STYLE_H
