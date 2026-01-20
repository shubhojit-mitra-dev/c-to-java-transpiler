#pragma once

enum class TokenType {
    
    // Keywords
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

    // Identifiers & literals
    IDENTIFIER,
    NUMBER,
    STRING,

    // Operators
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

    // Delimiters
    LPAREN,        // (
    RPAREN,        // )
    LBRACE,        // {
    RBRACE,        // }
    SEMICOLON,     // ;
    COMMA,

    END_OF_FILE,
    UNKNOWN
};
