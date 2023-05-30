#include "style.h"

Style::Style()
{

}

QString Style::GetBG()
{
    return QString {
        "#mainwindow { border-image: "
        "url(:/resources/BGGameStartWidget.png) 0 0 0 0 stretch stretch; }"
    };
}
