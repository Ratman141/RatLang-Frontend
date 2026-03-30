#include "lexer.h"

std::vector<std::string> split(const std::string& source, const std::string delim){
    std::vector<std::string> src;
    size_t start = 0, pos;
    if(delim == ""){
        for(char c : source){
            src.push_back(std::string(1, c));
        }
        return src;
    }
    while((pos = source.find(delim, start)) != std::string::npos){
        src.push_back(source.substr(start, pos - start));
        start = pos + delim.size();
    }
    src.push_back(source.substr(start));
    return src;
}

std::vector<Token> Lexer::tokenize(const std::string& source){
    auto vec = split(source, "");
    std::deque<std::string> src(vec.begin(), vec.end());
    std::vector<Token> tokens;
    Token token;
    // Make tokens untill file ends
    while(src.size() > 0){
        if(src[0] == ""){
            src.pop_front();
        }
        else if(src[0] == "("){
            token.type = TokenType::LPAREN;
            token.value = "(";
            tokens.push_back(token);
            src.pop_front();
        }
        else if(src[0] == ")"){
            token.type = TokenType::RPAREN;
            token.value = ")";
            tokens.push_back(token);
            src.pop_front();
        }
        else if(src[0] == ","){
            token.type = TokenType::COMMA;
            token.value = ",";
            tokens.push_back(token);
            src.pop_front();
        }
        else if(src[0] == ":"){
            token.type = TokenType::COLON;
            token.value = ":";
            tokens.push_back(token);
            src.pop_front();
        }
        else if(src[0] == "."){
            token.type = TokenType::DOT;
            token.value = ".";
            tokens.push_back(token);
            src.pop_front();
        }
    }
    token.type = TokenType::EOF_TOKEN;
    token.value = "EOF";
    tokens.push_back(token);
    return tokens;
}