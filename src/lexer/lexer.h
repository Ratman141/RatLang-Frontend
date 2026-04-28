#pragma once

#include <string>
#include <vector>
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
    LPAREN, RPAREN, COMMA, COLON, DOT,
    // other
    IDENTIFIER, EOF_TOKEN
};

struct Token{
    TokenType type;
    std::string value;
    size_t line;
    
    Token(TokenType t, std::string val, int l) : type(t), value(val), line(l){}
    Token(){}
};

class Lexer{
    private:
        std::string source;
        std::vector<Token> tokens;
        size_t line = 1;
        size_t pos = 0;
        char peek();
        char advance();
    public:
        std::vector<Token> tokenize();
        Lexer(std::string src) : source(src){};
};
