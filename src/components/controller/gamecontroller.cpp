#include "gamecontroller.h"
#include "../../components/randomizer/wordrandomizer.h"
#include "../../components/style/style.h"
#include <QObject>
#include <QPushButton>

GameController::GameController() {}

void GameController::AddAmountOfCorectness(QString letter, QString word,
                                           int &amountOfCorectness) {
  for (int i = 0; i < word.size(); i++) {
    if (letter == word[i])
      amountOfCorectness++;
  }
}

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
    for (int j = 0; j < arrayOfCorectness.size(); j++) {
      if (word[i] == arrayOfCorectness[j]) {
        text.append("  ");
        text.append(word[i]);
        text.append("  ");
        is = true;
      }
    }
    if (!is) {
      text.append(" __ ");
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

void GameController::DefineChampion() { labelNameOfWinner->setText(champion); }

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
                               int &amountOfErrorsForPlayer,
                               int &amountOfCorectness) {
  for (int i = 0; i < word.size(); i++) {
    if (letter == word[i]) {
      AddAmountOfCorectness(letter, word, amountOfCorectness);
      arrayOfCorectness->push_back(letter);
      return;
    }
  }
  amountOfErrorsForPlayer++;
  arrayOfErrors->push_back(letter);

  for (int i = 0; i < alphabetButtons.size(); i++)
    alphabetButtons[i]->setEnabled(false);

  nextButton->setEnabled(true);
  nextButton->setStyleSheet(Style::GetButtonStyle());
}

void GameController::CheckTheChampion() {
  if (champion != "null") {
    gameoverButton->setEnabled(true);
    gameoverButton->setStyleSheet(Style::GetButtonStyle());
    nextButton->setEnabled(false);
    nextButton->setStyleSheet(Style::GetButtonStyleDisabled());
    for (int i = 0; i < alphabetButtons.size(); i++)
      alphabetButtons[i]->setEnabled(false);
  }
}

void GameController::ToWinGame(int amountOfCorectness, QString word) {
  if (amountOfCorectness == word.size()) {
    champion = currentPlayer == 1 ? nameOfPlayer1 : nameOfPlayer2;
  }
  DefineChampion();
}

void GameController::ToLoseGame(std::vector<QString> arrayOfErrors) {
  if (arrayOfErrors.size() == 7) {
    champion = currentPlayer == 1 ? nameOfPlayer2 : nameOfPlayer1;
  }
  DefineChampion();
}

void GameController::ResetGame() {
  champion = "null";

  WordRandomizer::ReadFile();
  wordForPLayer1 = WordRandomizer::word_1;
  wordForPLayer2 = WordRandomizer::word_2;

  amountOfErrorsForPlayer1 = 0;
  amountOfCorectnessForPlayer1 = 0;
  amountOfErrorsForPlayer2 = 0;
  amountOfCorectnessForPlayer2 = 0;

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
  gameoverButton->setStyleSheet(Style::GetButtonStyleDisabled());
  nextButton->setEnabled(false);
  nextButton->setStyleSheet(Style::GetButtonStyleDisabled());
}

void GameController::ClickLetter(QString letter) {
  if (currentPlayer == 1) {
    CheckMove(letter, wordForPLayer1, &arrayOfCorectnessFor1,
              &arrayOfErrorsFor1, amountOfErrorsForPlayer1,
              amountOfCorectnessForPlayer1);
    HiglightLetters(arrayOfCorectnessFor1, arrayOfErrorsFor1);

    ChangePicture(amountOfErrorsForPlayer1);

    ShowWord(arrayOfCorectnessFor1, wordForPLayer1);

    ToWinGame(amountOfCorectnessForPlayer1, wordForPLayer1);
    ToLoseGame(arrayOfErrorsFor1);

  } else {
    CheckMove(letter, wordForPLayer2, &arrayOfCorectnessFor2,
              &arrayOfErrorsFor2, amountOfErrorsForPlayer2,
              amountOfCorectnessForPlayer2);
    HiglightLetters(arrayOfCorectnessFor2, arrayOfErrorsFor2);

    ChangePicture(amountOfErrorsForPlayer2);

    ShowWord(arrayOfCorectnessFor2, wordForPLayer2);

    ToWinGame(amountOfCorectnessForPlayer2, wordForPLayer2);
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
  nextButton->setStyleSheet(Style::GetButtonStyleDisabled());
}
