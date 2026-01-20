#include <fstream>
#include <iostream>
#include <sstream>
#include "../../lexer/Lexer.h"

using namespace std;

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
        cout << static_cast<int>(token.type)
             << " "
             << token.lexeme << "\n";
    }

    return 0;
}
