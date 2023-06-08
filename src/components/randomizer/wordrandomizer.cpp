#include "wordrandomizer.h"
#include <fstream>

#define MAX 100

WordRandomizer::WordRandomizer()
{
}

std::string readFile()
{
  std::ifstream fileWithWords("words-for-hangman.txt");

  if (fileWithWords.is_open())
  {
    for (int i = 0; i < 100; i++)
    {
      std::string str((std::istreambuf_iterator<char>(fileWithWords)),
                      std::istreambuf_iterator<char>());
      str >> WordRandomizer::dataWords[i][i];
    }
    fileWithWords.close();
  }
}
