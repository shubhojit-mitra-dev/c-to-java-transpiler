#pragma once

/**
 * @file TokenType.h
 * @brief Defines all token types recognized by the lexer.
 *
 * This enum represents the smallest meaningful units (tokens)
 * of the restricted C language supported by the compiler.
 */
enum class TokenType {
    
    /** @name Keywords */
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    IF,
    ELSE,
    FOR,
    WHILE,
    RETURN,
    PRINTF,

    /** @name Identifiers and literals */
    IDENTIFIER,
    NUMBER,
    STRING,

    /** @name Operators */
    PLUS,
    MINUS,
    STAR,
    SLASH,
    MOD,

    ASSIGN,        // =
    EQ,            // ==
    NEQ,           // !=
    LT,            // <
    GT,            // >
    LTE,           // <=
    GTE,           // >=

    /** @name Delimiters */
    LPAREN,        // (
    RPAREN,        // )
    LBRACE,        // {
    RBRACE,        // }
    SEMICOLON,     // ;
    COMMA,

    /** @name Special tokens */
    END_OF_FILE,   // Indicates the end of the input
    UNKNOWN        // Represents an unrecognized token
};
