#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
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
    
    Token(TokenType t, std::string val, int l) : type(t), value(val), line(l){}
    Token(){}
};

class Lexer{
    private:
        std::string source;
        std::vector<Token> tokens;
    public:
        std::vector<std::string> split(const std::string& source, const std::string& delim);        // Makes source code into vector
        std::vector<Token> tokenize(const std::string& source);
        Lexer(std::string src) : source(src){};
};
