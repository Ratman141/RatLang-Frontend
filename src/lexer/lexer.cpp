#include "lexer.h"
#include "../error/error.h"
#include <cctype>
#include <sstream>

const std::unordered_map<std::string, TokenType> Lexer::keywords = {
    {"int", TokenType::INT},
    {"float", TokenType::FLOAT},
    {"char", TokenType::CHAR},
    {"string", TokenType::STRING},
    {"bool", TokenType::BOOL},
    {"if", TokenType::IF},
    {"else", TokenType::ELSE},
    {"end", TokenType::END},
    {"goto", TokenType::GOTO},
    {"when", TokenType::WHEN},
    {"print", TokenType::PRINT},
    {"endline", TokenType::ENDLINE},
    {"input", TokenType::INPUT},
    {"finish", TokenType::FINISH},
    {"func", TokenType::FUNC},
    {"void", TokenType::VOID},
    {"flag", TokenType::FLAG},
    {"return", TokenType::RETURN},
    {"include", TokenType::INCLUDE},
    {"AND", TokenType::AND},
    {"OR", TokenType::OR},
    {"NOT", TokenType::NOT}
};

char Lexer::peek(){
    if(pos >= source.length()) return '\0';
    return source[pos];
}

char Lexer::peekNext(){
    if(pos + 1 >= source.length()) return '\0';
    return source[pos + 1];
}

char Lexer::advance(){
    return source[pos++];
}

Token Lexer::lexNum(char first){
    std::string num = {};
    num += first;
    int dot_count = 0;
    while(isdigit(static_cast<unsigned char>(peek())) || peek() == '.'){
        if(peek() == '.'){
            dot_count++;
            if(!isdigit(peekNext())) 
                throw(LexError(line, "Unable to tokenize: " + (num + peek())));
        }
        if(dot_count > 1) throw(LexError(line, "Unable to tokenize: " + num));
        num += advance();
    }
    if(dot_count == 0){
        return {TokenType::INT_LIT, num, line};
    }
    else return {TokenType::FLOAT_LIT, num, line};
}

Token Lexer::lexString(){
    std::string value;
    while(peek() != '"' && peek() != '\0'){
        value += advance();
    }
    if(peek() == '\0') throw(LexError(line, "String unable to be tokenized."));
    advance();
    return {TokenType::STRING_LIT, value, line};
}

Token Lexer::lexID(char first){
    std::string id = {};
    id += first;
    while(isalnum(static_cast<unsigned char>(peek())) || peek() == '_'){
        id += advance();
    }
    auto key = keywords.find(id);
    if(key != keywords.end())  return {key->second, id, line};
    return {TokenType::IDENTIFIER, id, line};
}

std::vector<Token> Lexer::tokenize(){
    std::vector<Token> tokens;
    // Make tokens until file ends
    while(pos < source.length()){
        char c = advance();
        switch(c){
            case '/': 
                if(peek() == '/'){
                    while(peek() != '\n' && peek() != '\0') advance();
                    break;
                }
                if(peek() == '*'){
                    advance();
                    while(!(peek() == '*' && peekNext() == '/')) {
                        if(peek() == '\0') throw(LexError(line, "Failed to comment."));
                        if(peek() == '\n') line++;
                        advance();
                    }
                    advance();
                    advance();
                    break;
                }
                tokens.push_back({TokenType::DIV, "/", line});
                break;
            case ' ': 
                break;
            case '\n': 
                line++; 
                break;
            case '=':
                if(peek() == '='){
                    advance();
                    tokens.push_back({TokenType::EQEQ, "==", line});
                }
                else tokens.push_back({TokenType::EQUALS, "=", line});
                break;
            case '!':
                if(peek() == '='){
                    advance();
                    tokens.push_back({TokenType::NEQ, "!=", line});
                }
                else tokens.push_back({TokenType::NOT, "!", line});
                break;
            case '+': 
                if(peek() == '+'){
                    advance();
                    tokens.push_back({TokenType::PLUSPLUS, "++", line});
                }
                else tokens.push_back({TokenType::PLUS, "+", line}); 
                break;
            case '-': 
                 if(peek() == '-'){
                    advance();
                    tokens.push_back({TokenType::MINUSMINUS, "++", line});
                }
                else tokens.push_back({TokenType::MINUS, "-", line}); 
                break;
            case '*': 
                tokens.push_back({TokenType::MULT, "*", line}); 
                break;
            case '%':
                tokens.push_back({TokenType::MOD, "%", line});
                break;
            case '(': 
                tokens.push_back({TokenType::LPAREN, "(", line});
                break;
            case ')': 
                tokens.push_back({TokenType::RPAREN, ")", line});
                break;
            case ',':
                tokens.push_back({TokenType::COMMA, ",", line});
                break;
            case ':': 
                tokens.push_back({TokenType::COLON, ":", line});
                break;
            case '.':
                tokens.push_back({TokenType::DOT, ".", line});
                break;
            case '<':
                if(peek() == '='){
                    advance();
                    tokens.push_back({TokenType::LTE, "<=", line});
                }
                else tokens.push_back({TokenType::LT, "<", line});
                break;
            case '>':
                if(peek() == '='){
                    advance();
                    tokens.push_back({TokenType::GTE, ">=", line});
                }
                else tokens.push_back({TokenType::GT, ">", line});
                break;
            case '&':
                if(peek() == '&'){
                    advance();
                    tokens.push_back({TokenType::AND, "&&", line});
                }
                else throw(LexError(line, "Unknown token: '&'."));
                break;
            case '|':
                if(peek() == '|'){
                    advance();
                    tokens.push_back({TokenType::OR, "||", line});
                }
                else throw(LexError(line, "Unknown token: '|'."));
                break;
            case '"':
                tokens.push_back(lexString());
                break;
            default:
                if(isalpha(c) || c == '_'){
                    tokens.push_back(lexID(c));
                }
                else if(isdigit(c)){
                    tokens.push_back(lexNum(c));
                }
                else throw(LexError(line, "Unknown token: " + std::string(1, c)));
        }   //Switch
    }   //While loop
    tokens.push_back({TokenType::EOF_TOKEN, "EOF", line});
    return tokens;
}   //tokenize function