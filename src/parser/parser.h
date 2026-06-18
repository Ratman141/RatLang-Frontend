#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <unordered_map>
#include "../ast/ast.h"
#include "../lexer/lexer.h"
#include "../error/error.h"

class Parser{
    private:
        std::vector<Token> tokens;
        size_t pos = 0;
    public:
        void load_tokens(std::vector<Token> t);
        Token advance();
        Token peek();
        Token peekNext();
};