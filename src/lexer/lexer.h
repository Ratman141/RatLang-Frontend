#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "../error/error.h"

enum class TokenType{
    // literals
    INT_LIT, FLOAT_LIT, STRING_LIT, TRUE, FALSE,
    // types
    INT, FLOAT, STRING, BOOL,
    // keywords
    IF, ELSE, END, GOTO, WHEN, LABEL, PRINT,
    ENDLINE, INPUT, FINISH, FUNC, VOID, FLAG,
    DEFAULT, RETURN, INCLUDE,
    // operators
    PLUS, MINUS, MULT, DIV, MOD, EQUALS, EQEQ, NEQ,
    LT, GT, LTE, GTE, AND, OR, NOT,
    // symbols
    LPAREN, RPAREN, COMMA, COLON, 
    // other
    IDENTIFIER, EOF_TOKEN
};

struct Token{
    TokenType type;
    std::string value;
    int line;
};

class Lexer{
    private:
    public:
};
