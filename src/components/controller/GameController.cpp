#include "gamecontroller.h"
#include "../../components/style/style.h"
#include <QObject>
#include <QPushButton>

GameController::GameController() {}

void GameController::HiglightLetters(std::vector<QString> arrayOfCorectness,
                                     std::vector<QString> arrayOfErrors) {
  for (int i = 0; i < alphabetButtons.size(); i++) {
    for (int j = 0; j < arrayOfCorectness.size(); j++) {
      if (alphabetButtons[i]->text() == arrayOfCorectness[j]) {
        alphabetButtons[i]->setStyleSheet(Style::GetCorrectLetterButtonStyle());
      }
    }
    for (int j = 0; j < arrayOfErrors.size(); j++) {
      if (alphabetButtons[i]->text() == arrayOfErrors[j]) {
        alphabetButtons[i]->setStyleSheet(Style::GetWrongLetterButtonStyle());
      }
    }
  }
}

void GameController::CheckMove(QString letter, QString word,
                               std::vector<QString> *arrayOfCorectness,
                               std::vector<QString> *arrayOfErrors) {
  for (int i = 0; i < word.size(); i++) {
    if (letter == word[i]) {
      arrayOfCorectness->push_back(letter);
      return;
    }
  }
  arrayOfErrors->push_back(letter);
}

void GameController::ClickLetter(QString letter) {
  if (currentPlayer == 1) {
    CheckMove(letter, wordForPLayer1, &arrayOfCorectnessFor1,
              &arrayOfErrorsFor1);
    HiglightLetters(arrayOfCorectnessFor1, arrayOfErrorsFor1);
  } else {
    CheckMove(letter, wordForPLayer2, &arrayOfCorectnessFor2,
              &arrayOfErrorsFor2);
    HiglightLetters(arrayOfCorectnessFor2, arrayOfErrorsFor2);
  }
  //
  qDebug() << letter;
  qDebug() << arrayOfCorectnessFor1;
  qDebug() << arrayOfErrorsFor1;
  //
}

void GameController::Next() { currentPlayer = currentPlayer == 1 ? 2 : 1; }
