#include "parser.h"

void Parser::load_tokens(std::vector<Token> t){
    tokens = t;
}

Token Parser::peek(){
    return tokens[pos];
}

Token Parser::peekNext(){
    if(pos + 1>=tokens.size()) 
        return tokens.back();
    return tokens[pos + 1];
}

Token Parser::advance(){
    return tokens[pos++];
}