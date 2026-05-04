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
    RETURN, INCLUDE,
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
    
    Token(TokenType t, const std::string& val, size_t l) : type(t), value(val), line(l){}
};

class Lexer{
    private:
        std::string source;
        std::vector<Token> tokens;
        size_t line = 1;
        size_t pos = 0;
        static const std::unordered_map<std::string, TokenType> keywords;
        char peek();
        char peekNext();
        char advance();
        Token lexNum(char first);
        Token lexString();
        Token lexID(char first);
    public:
        std::vector<Token> tokenize();
        Lexer(std::string src) : source(src){};
};
