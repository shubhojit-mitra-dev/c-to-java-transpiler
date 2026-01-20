#pragma once
#include <string>
#include <vector>
#include "Token.h"
using namespace std;

class Lexer {
public:
    Lexer(const string& source);
    vector<Token> tokenize();

private:
    string source;
    size_t pos;
    int line;

    // Helper methods
    char peek();
    char peekNext();
    char advance();
    bool match(char expected);

    // Skipping methods
    void skipWhitespace();
    void skipComment();
    void skipPreprocessor();

    // Token creation methods
    Token makeNumber();
    Token makeIdentifier();
    Token makeString();
};
