#include "lexer.h"
#include "../error/error.h"
#include <cctype>

char Lexer::peek(){
    if(pos >= source.length()) return '\0';
    return source[pos];
}

char Lexer::advance(){
    return source[pos++];
}

std::vector<Token> Lexer::tokenize(){
    std::vector<Token> tokens;
    // Make tokens until file ends
    while(pos < source.length()){
        char c = advance();
        if(c == ' ') continue;
        else if(c == '\n') line ++;
        else if(c == '='){
            if(peek() == '='){
                advance();
                tokens.push_back({TokenType::EQEQ, "==", line});
            }
            else tokens.push_back({TokenType::EQUALS, "=", line});
        }
        if(c == '!'){
            if(peek() == '='){
                advance();
                tokens.push_back({TokenType::NEQ, "!=", line});
            }
            else throw(LexError(line, "Unable to tokenize '!'."));
        }
        else if(c == '+'){
            tokens.push_back({TokenType::PLUS, "+", line});
        }
        else if(c == '-'){
            tokens.push_back({TokenType::MINUS, "-", line});
        }
        else if(c == '*'){
            tokens.push_back({TokenType::MULT, "*", line});
        }
        else if(c == '/'){
            tokens.push_back({TokenType::DIV, "/", line});
        }
        else if(c == '%'){
            tokens.push_back({TokenType::MOD, "%", line});
        }
        else if(c == '('){
            tokens.push_back({TokenType::LPAREN, "(", line});
        }
        else if(c == ')'){
            tokens.push_back({TokenType::RPAREN, ")", line});
        }
        else if(c == ','){
            tokens.push_back({TokenType::COMMA, ",", line});
        }
        else if(c == ':'){
            tokens.push_back({TokenType::COLON, ":", line});
        }
        else if(c == '.'){
            tokens.push_back({TokenType::DOT, ".", line});
        }
    }
    tokens.push_back({TokenType::EOF_TOKEN, "EOF", line});
    return tokens;
}