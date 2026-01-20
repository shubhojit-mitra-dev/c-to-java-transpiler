#pragma once

#include <string>
#include <vector>
#include "Token.h"

using namespace std;

/**
 * @file Lexer.h
 * @brief Declares the Lexer class responsible for lexical analysis.
 */

/**
 * @class Lexer
 * @brief Converts C source code into a stream of tokens.
 *
 * The Lexer performs lexical analysis by:
 * - Reading raw source code
 * - Ignoring whitespace, comments, and preprocessor directives
 * - Producing a sequence of tokens for the parser
 *
 * The lexer does NOT:
 * - Perform syntax validation
 * - Understand program structure
 * - Perform semantic analysis
 */
class Lexer {
public:
    /**
     * @brief Constructs a lexer with the given source code.
     * @param source Full contents of the input C source file.
     */
    Lexer(const string& source);

    /**
     * @brief Tokenizes the input source code.
     *
     * Iterates through the source character-by-character and
     * produces a vector of Token objects.
     *
     * @return Vector of tokens ending with END_OF_FILE token.
     */
    vector<Token> tokenize();

private:
    /** Raw source code */
    string source;

    /** Current index in the source string */
    size_t pos;

    /** Current line number (for diagnostics) */
    int line;

    // =========================
    // Character-level helpers
    // =========================

    /**
     * @brief Returns the current character without consuming it.
     */
    char peek();

    /**
     * @brief Returns the next character without consuming it.
     */
    char peekNext();

    /**
     * @brief Consumes and returns the current character.
     */
    char advance();

    /**
     * @brief Conditionally consumes a character if it matches.
     * @param expected The expected character.
     * @return true if the character was consumed, false otherwise.
     */
    bool match(char expected);

    // =========================
    // Skipping helpers
    // =========================

    /**
     * @brief Skips whitespace characters (spaces, tabs, newlines).
     */
    void skipWhitespace();

    /**
     * @brief Skips C-style comments.
     *
     * Supports:
     * - Single-line comments (//)
     * - Multi-line comments (/* *\/)
     */
    void skipComment();

    /**
     * @brief Skips preprocessor directives.
     *
     * Used to ignore lines starting with '#'
     * such as #include or #define.
     */
    void skipPreprocessor();

    // =========================
    // Token creation helpers
    // =========================

    /**
     * @brief Creates a numeric literal token.
     */
    Token makeNumber();

    /**
     * @brief Creates an identifier or keyword token.
     */
    Token makeIdentifier();

    /**
     * @brief Creates a string literal token.
     */
    Token makeString();
};
