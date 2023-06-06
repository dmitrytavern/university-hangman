#ifndef GameController_H
#define GameController_H

#include <QString>
#include <QPushButton>
#include <vector>

class GameController
{
public:
    GameController();
    static inline QString nameOfPlayer1;
    static inline QString nameOfPlayer2;
    static inline QString wordForPLayer1 = "QWERT";
    static inline QString wordForPLayer2 = "ASDFG";
    static inline std::vector<QString> arrayOfErrorsFor1;
    static inline std::vector<QString> arrayOfErrorsFor2;
    static inline std::vector<QString> arrayOfCorectnessFor1;
    static inline std::vector<QString> arrayOfCorectnessFor2;
    static inline QList<QPushButton *> alphabetButtons;
    static inline int currentPlayer = 1;
    static void HiglightLetters(std::vector<QString> arrayOfCorectness, std::vector<QString> arrayOfErrors);
    static void CheckMove(QString letter, QString word,
                          std::vector<QString> *arrayOfCorectness,
                          std::vector<QString> *arrayOfErrors);
public slots:
    static void ClickLetter(QString letter);
    static void Next();
};

#endif // STYLE_H
