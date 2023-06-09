#ifndef WORDRANDOMIZER_H
#define WORDRANDOMIZER_H
#include <QString>

class WordRandomizer
{
public:
    WordRandomizer();

    static void ReadFile();
    static inline QString word_1;
    static inline QString word_2;
};

#endif // WORDRANDOMIZER_H
