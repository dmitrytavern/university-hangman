#ifndef GameController_H
#define GameController_H

#include <QString>

class GameController
{
public:
    GameController();
    static inline QString nameOfPlayer1;
    static inline QString nameOfPlayer2;
    static inline QString wordForPLayer1;
    static inline QString wordForPLayer2;
    static inline int currentPlayer = 1;

//signals:
public slots:
    static void ClickLetter(QString letter);
    static void Next();
};

#endif // STYLE_H
