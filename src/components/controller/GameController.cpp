#include "gamecontroller.h"
#include "../../components/style/style.h"
#include <QObject>
#include <QPushButton>

GameController::GameController() {}

void GameController::MakeActiveAlphabetButtons() {
  for (int i = 0; i < alphabetButtons.size(); i++)
    alphabetButtons[i]->setEnabled(true);
}

void GameController::MakeInertAlphabetButtons() {
  for (int i = 0; i < alphabetButtons.size(); i++)
    alphabetButtons[i]->setEnabled(false);
}

void GameController::ChangePicture(int amountOfErrorsForPlayer) {
  picture->setStyleSheet(Style::GetPictureStyle(amountOfErrorsForPlayer + 1));
}

void GameController::ShowWord(std::vector<QString> arrayOfCorectness,
                              QString word) {
  QString text;
  for (int i = 0; i < word.size(); i++) {
    bool is = false;
    QLabel *label;
    for (int j = 0; j < arrayOfCorectness.size(); j++) {
      if (word[i] == arrayOfCorectness[j]) {
        text.append(" ");
        text.append(word[i]);
        text.append(" ");
        is = true;
      }
    }
    if (!is) {
      text.append(" _ ");
    }
    wordLabel->setText(text);
  }
}

void GameController::SetUsername() {
  if (currentPlayer == 1)
    usernameLabel->setText(nameOfPlayer1);
  else
    usernameLabel->setText(nameOfPlayer2);
}

void GameController::HiglightLetters(std::vector<QString> arrayOfCorectness,
                                     std::vector<QString> arrayOfErrors) {

  for (int i = 0; i < alphabetButtons.size(); i++) {
    alphabetButtons[i]->setStyleSheet(Style::GetLetterButtonStyle());
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

  nextButton->setEnabled(true);
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

void GameController::ResetGame() {
  champion = "null";

  wordForPLayer1 = "QWE";
  wordForPLayer2 = "ASD";

  amountOfErrorsForPlayer1 = 0;
  amountOfErrorsForPlayer2 = 0;

  arrayOfErrorsFor1.clear();
  arrayOfErrorsFor2.clear();

  arrayOfCorectnessFor1.clear();
  arrayOfCorectnessFor2.clear();

  ChangePicture(0);

  for (int i = 0; i < alphabetButtons.size(); i++)
    alphabetButtons[i]->setEnabled(true);

  currentPlayer = 1;
  SetUsername();
  HiglightLetters(arrayOfCorectnessFor1, arrayOfErrorsFor1);
  ShowWord(arrayOfCorectnessFor1, wordForPLayer1);

  gameoverButton->setEnabled(false);
  nextButton->setEnabled(false);
}

void GameController::ClickLetter(QString letter) {
  if (currentPlayer == 1) {
    CheckMove(letter, wordForPLayer1, &arrayOfCorectnessFor1,
              &arrayOfErrorsFor1, amountOfErrorsForPlayer1);
    HiglightLetters(arrayOfCorectnessFor1, arrayOfErrorsFor1);

    ChangePicture(amountOfErrorsForPlayer1);

    ShowWord(arrayOfCorectnessFor1, wordForPLayer1);

    ToWinGame(arrayOfCorectnessFor1, wordForPLayer1);
    ToLoseGame(arrayOfErrorsFor1);

  } else {
    CheckMove(letter, wordForPLayer2, &arrayOfCorectnessFor2,
              &arrayOfErrorsFor2, amountOfErrorsForPlayer2);
    HiglightLetters(arrayOfCorectnessFor2, arrayOfErrorsFor2);

    ChangePicture(amountOfErrorsForPlayer2);

    ShowWord(arrayOfCorectnessFor2, wordForPLayer2);

    ToWinGame(arrayOfCorectnessFor2, wordForPLayer2);
    ToLoseGame(arrayOfErrorsFor2);
  }
  CheckTheChampion();
}

void GameController::Next() {
  currentPlayer = currentPlayer == 1 ? 2 : 1;
  MakeActiveAlphabetButtons();
  if (currentPlayer == 1) {
    HiglightLetters(arrayOfCorectnessFor1, arrayOfErrorsFor1);
    ChangePicture(amountOfErrorsForPlayer1);
    ShowWord(arrayOfCorectnessFor1, wordForPLayer1);
  } else {
    HiglightLetters(arrayOfCorectnessFor2, arrayOfErrorsFor2);
    ChangePicture(amountOfErrorsForPlayer2);
    ShowWord(arrayOfCorectnessFor2, wordForPLayer2);
  }
  SetUsername();
  nextButton->setEnabled(false);
}
