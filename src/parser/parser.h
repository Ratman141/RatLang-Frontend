#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "../ast/ast.h"
#include "../lexer/lexer.h"
#include "../error/error.h"

class Parser{
    private:
        std::vector<Token> tokens;
        int current;   
        std::string currentFunction;
        std::string currenFuncKind;

        std::unique_ptr<Stmt> parseStatement();
        std::unique_ptr<Stmt> parseDeclaration();
        std::unique_ptr<Stmt> parseAssignment();
        std::unique_ptr<Stmt> parsePrint();
        std::unique_ptr<Stmt> parseInput();
        std::unique_ptr<Stmt> parseIf();
        std::unique_ptr<Stmt> parseEndLine();
        std::unique_ptr<Stmt> parseGoto();
        std::unique_ptr<Stmt> parseLabel();
        std::unique_ptr<Stmt> parseFuncDef(bool isDefault);
        std::unique_ptr<Stmt> parseReturn();
        std::unique_ptr<Stmt> parseFinish();
        std::unique_ptr<Stmt> parseInclude();
        std::unique_ptr<Stmt> parseDefault();

        std::unique_ptr<Expr> parseLogic();
        std::unique_ptr<Expr> parseComparison();
        std::unique_ptr<Expr> parseExpression();
        std::unique_ptr<Expr> parseTerm();
        std::unique_ptr<Expr> parseFactor();

        std::vector<std::unique_ptr<Stmt>> parseBlock();

        std::vector<std::pair<std::string, std::string>> parseParams();

        Token consume(TokenType type, const std::string& errorMessage);
        Token peek();
        Token peekNext();
        Token advance();
        bool check(TokenType type);
        bool match(TokenType type);
        bool isAtEnd();
        bool isType(TokenType type);
    public:
        Parser(const std::vector<Token>& tokens);
        std::vector<std::unique_ptr<Stmt>> parse();
};