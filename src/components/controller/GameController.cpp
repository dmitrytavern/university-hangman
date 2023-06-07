#include "gamecontroller.h"
#include "../../components/style/style.h"
#include <QObject>
#include <QPushButton>

GameController::GameController() {}

void GameController::HiglightLetters(std::vector<QString> arrayOfCorectness,
                                     std::vector<QString> arrayOfErrors) {
  for (int i = 0; i < alphabetButtons.size(); i++) {
    alphabetButtons[i]->setStyleSheet(Style::GetLetterButtonStyle());
    alphabetButtons[i]->setEnabled(true);
    for (int j = 0; j < arrayOfCorectness.size(); j++) {
      if (alphabetButtons[i]->text() == arrayOfCorectness[j]) {
        alphabetButtons[i]->setStyleSheet(Style::GetCorrectLetterButtonStyle());
        alphabetButtons[i]->setEnabled(false);
      }
    }
    for (int j = 0; j < arrayOfErrors.size(); j++) {
      if (alphabetButtons[i]->text() == arrayOfErrors[j]) {
        alphabetButtons[i]->setStyleSheet(Style::GetWrongLetterButtonStyle());
        alphabetButtons[i]->setEnabled(false);
      }
    }
  }
}

void GameController::CheckMove(QString letter, QString word,
                               std::vector<QString> *arrayOfCorectness,
                               std::vector<QString> *arrayOfErrors,
                               int &amountOfErrorsForPlayer) {
  for (int i = 0; i < word.size(); i++) {
    if (letter == word[i]) {
      arrayOfCorectness->push_back(letter);
      return;
    }
  }
  amountOfErrorsForPlayer++;
  arrayOfErrors->push_back(letter);
  for (int i = 0; i < alphabetButtons.size(); i++)
    alphabetButtons[i]->setEnabled(false);
}

void GameController::CheckTheChampion() {
  if (champion != "null") {
    gameoverButton->setEnabled(true);
    nextButton->setEnabled(false);
    for (int i = 0; i < alphabetButtons.size(); i++)
      alphabetButtons[i]->setEnabled(false);
  }
}

void GameController::ToWinGame(std::vector<QString> arrayOfCorectness,
                               QString word) {
  if (arrayOfCorectness.size() == word.size()) {
    champion = currentPlayer == 1 ? nameOfPlayer1 : nameOfPlayer2;
  }
}

void GameController::ToLoseGame(std::vector<QString> arrayOfErrors) {
  if (arrayOfErrors.size() == 7) {
    champion = currentPlayer == 1 ? nameOfPlayer2 : nameOfPlayer1;
  }
}

void GameController::ClickLetter(QString letter) {
  if (currentPlayer == 1) {
    CheckMove(letter, wordForPLayer1, &arrayOfCorectnessFor1,
              &arrayOfErrorsFor1, amountOfErrorsForPlayer1);
    HiglightLetters(arrayOfCorectnessFor1, arrayOfErrorsFor1);
    ToWinGame(arrayOfCorectnessFor1, wordForPLayer1);
    ToLoseGame(arrayOfErrorsFor1);
  } else {
    CheckMove(letter, wordForPLayer2, &arrayOfCorectnessFor2,
              &arrayOfErrorsFor2, amountOfErrorsForPlayer2);
    HiglightLetters(arrayOfCorectnessFor2, arrayOfErrorsFor2);
    ToWinGame(arrayOfCorectnessFor2, wordForPLayer2);
    ToLoseGame(arrayOfErrorsFor2);
  }
  //
  qDebug() << letter;
  qDebug() << arrayOfCorectnessFor1;
  qDebug() << arrayOfErrorsFor1;
  qDebug() << amountOfErrorsForPlayer1;
  qDebug() << amountOfErrorsForPlayer2;
  //
}

void GameController::Next() {
  currentPlayer = currentPlayer == 1 ? 2 : 1;
  if (currentPlayer == 1) {
    HiglightLetters(arrayOfCorectnessFor1, arrayOfErrorsFor1);
  } else {
    HiglightLetters(arrayOfCorectnessFor2, arrayOfErrorsFor2);
  }
  CheckTheChampion();
}
