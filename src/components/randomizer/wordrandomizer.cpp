#include "wordrandomizer.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <cstdlib>
#include <ctime>

#define MAX 100

WordRandomizer::WordRandomizer()
{
}

void WordRandomizer::ReadFile()
{
  word_1 = "";
  word_2 = "";

  QFile words("../resources/words-for-hangman.txt");

  if (!words.open(QIODevice::ReadOnly | QIODevice::Text))
    qDebug() << "not open";

  QTextStream in(&words);
  QString line;

  srand(time(NULL));
  int randomNumber_1 = (rand() % MAX) + 1;
  int randomNumber_2 = (rand() % MAX) + 1;

  for (int i = 1; i <= MAX; i++)
  {
    line = in.readLine();
    qDebug() << line;
    if (i == randomNumber_1)
    {
      word_1 = line;
    }
    if (i == randomNumber_2)
    {
      word_2 = line;
    }
    if (word_1 != "" && word_2 != "")
    {
      break;
    }
  }
  qDebug() << word_1 << word_2;
}
