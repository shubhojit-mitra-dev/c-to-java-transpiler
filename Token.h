#pragma once
#include <string>
#include "TokenType.h"
using namespace std;

struct Token {
    TokenType type;
    string lexeme;
    int line;
};
