#ifndef WORDRANDOMIZER_H
#define WORDRANDOMIZER_H
#include <vector>
#include <string>

class WordRandomizer
{
public:
    WordRandomizer();

    static std::string readFile();
    static inline std::string dataWords[10][100];
};

#endif // WORDRANDOMIZER_H
