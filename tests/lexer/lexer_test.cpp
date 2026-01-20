#include <fstream>
#include <iostream>
#include <sstream>
#include "../../lexer/Lexer.h"

using namespace std;

string tokenTypeToString(TokenType type) {
    switch (type) {
        // Keywords
        case TokenType::INT:         return "INT";
        case TokenType::FLOAT:       return "FLOAT";
        case TokenType::DOUBLE:      return "DOUBLE";
        case TokenType::CHAR:        return "CHAR";
        case TokenType::IF:          return "IF";
        case TokenType::ELSE:        return "ELSE";
        case TokenType::FOR:         return "FOR";
        case TokenType::WHILE:       return "WHILE";
        case TokenType::RETURN:      return "RETURN";
        case TokenType::PRINTF:      return "PRINTF";

        // Identifiers & literals
        case TokenType::IDENTIFIER:  return "IDENTIFIER";
        case TokenType::NUMBER:      return "NUMBER";
        case TokenType::STRING:      return "STRING";

        // Operators
        case TokenType::PLUS:        return "PLUS";
        case TokenType::MINUS:       return "MINUS";
        case TokenType::STAR:        return "STAR";
        case TokenType::SLASH:       return "SLASH";
        case TokenType::MOD:         return "MOD";
        
        case TokenType::ASSIGN:      return "ASSIGN";      // =
        case TokenType::EQ:          return "EQ";          // ==
        case TokenType::NEQ:         return "NEQ";         // !=
        case TokenType::LT:          return "LT";          // <
        case TokenType::GT:          return "GT";          // >
        case TokenType::LTE:         return "LTE";         // <=
        case TokenType::GTE:         return "GTE";         // >=

        case TokenType::AND:         return "AND";         // &&
        case TokenType::OR:          return "OR";          // ||
        case TokenType::NOT:         return "NOT";         // !

        // Delimiters
        case TokenType::LPAREN:      return "LPAREN";      // (
        case TokenType::RPAREN:      return "RPAREN";      // )
        case TokenType::LBRACE:      return "LBRACE";      // {
        case TokenType::RBRACE:      return "RBRACE";      // }
        case TokenType::SEMICOLON:   return "SEMICOLON";   // ;
        case TokenType::COMMA:       return "COMMA";       // ,

        // Special
        case TokenType::END_OF_FILE: return "EOF";
        case TokenType::UNKNOWN:     return "UNKNOWN";
        
        default:                     return "UNKNOWN_TYPE";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: lexer_test <file.c>\n";
        return 1;
    }

    ifstream file(argv[1]);
    if (!file) {
        cerr << "Could not open file\n";
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();

    Lexer lexer(buffer.str());
    auto tokens = lexer.tokenize();

    for (const auto& token : tokens) {
        cout << tokenTypeToString(token.type)
             << " "
             << token.lexeme << "\n";
    }

    return 0;
}
