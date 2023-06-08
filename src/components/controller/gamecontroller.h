#ifndef GameController_H
#define GameController_H

#include <QString>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <QHBoxLayout>

class GameController
{
public:
    GameController();
    static inline QString champion = "null";
    static inline QString nameOfPlayer1 = "Player 1";
    static inline QString nameOfPlayer2 = "Player 2";;
    static inline QString wordForPLayer1;
    static inline QString wordForPLayer2;
    static inline int amountOfErrorsForPlayer1 = 0;
    static inline int amountOfCorectnessForPlayer1 = 0;
    static inline int amountOfErrorsForPlayer2 = 0;
    static inline int amountOfCorectnessForPlayer2 = 0;
    static inline std::vector<QString> arrayOfErrorsFor1;
    static inline std::vector<QString> arrayOfErrorsFor2;
    static inline std::vector<QString> arrayOfCorectnessFor1;
    static inline std::vector<QString> arrayOfCorectnessFor2;
    static inline QList<QPushButton *> alphabetButtons;
    static inline int currentPlayer = 1;
    static void AddAmountOfCorectness(QString letter, QString word,
                                      int &amountOfCorectness);
    static void HiglightLetters(std::vector<QString> arrayOfCorectness, std::vector<QString> arrayOfErrors);
    static void CheckMove(QString letter, QString word,
                          std::vector<QString> *arrayOfCorectness,
                          std::vector<QString> *arrayOfErrors, int &amountOfErrorsForPlayer, int &amountOfCorectness);
    static void CheckTheChampion();
    static void ToWinGame(int amountOfCorectness, QString word);
    static void ToLoseGame(std::vector<QString> arrayOfErrors);
    static void ResetGame();
    static void MakeActiveAlphabetButtons();
    static void MakeInertAlphabetButtons();
    static void ChangePicture(int amountOfErrorsForPlayer);
    static inline QPushButton *gameoverButton;
    static inline QPushButton *nextButton;
    static inline QLabel *picture;
    static inline QLabel *usernameLabel;
    static inline QLabel *wordLabel;
    static void ShowWord(std::vector<QString> arrayOfCorectness, QString word);
    static void SetUsername();
    static inline QLabel *labelNameOfWinner;
    static void DefineChampion();

public slots:
    static void ClickLetter(QString letter);
    static void Next();
};

#endif // STYLE_H
