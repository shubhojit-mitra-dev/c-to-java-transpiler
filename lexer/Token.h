#pragma once

#include <string>
#include "TokenType.h"
using namespace std;

/**
 * @file Token.h
 * @brief Defines the Token structure used by the lexer and parser.
 */

/**
 * @struct Token
 * @brief Represents a single lexical token.
 *
 * A token consists of:
 * - its type (from TokenType)
 * - the exact lexeme (text) from source code
 * - the line number where it occurred
 *
 * Tokens are produced by the lexer and consumed by the parser.
 */
struct Token {

    /** The category/type of the token */
    TokenType type;

    /** The raw text (lexeme) corresponding to the token */
    string lexeme;

    /** Line number in source code where the token appears */
    int line;
};
