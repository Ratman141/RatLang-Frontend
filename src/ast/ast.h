#pragma once

#include <memory>
#include <string>
#include <vector>

// Base Classes
struct Expr{
    virtual ~Expr() = default;
};

struct Stmt{
    int line;
    virtual ~Stmt() = default;
};


// Expression nodes
struct NumberExpr : Expr{
    double value;
};

struct StringExpr : Expr{
    std::string value;
};

struct BoolExpr : Expr{
    bool value;
};

struct VarExpr : Expr{
    std::string name;
};

struct BinaryExpr : Expr{
    std::string op;
    std::unique_ptr<Expr> left;
    std::unique_ptr<Expr> right;
};

struct CallExpr : Expr{
    std::string name;
    std::vector<std::unique_ptr<Expr>> args;
};

// Statement nodes
struct DeclStmt : Stmt{
    std::string type;
    std::string name;
    std::unique_ptr<Expr> value;
};

struct AssignStmt : Stmt{
    std::string name;
    std::unique_ptr<Expr> value;
};

struct PrintStmt : Stmt{
    std::unique_ptr<Expr> value;
};

struct EndLineStmt : Stmt{};

struct InputStmt : Stmt{
    std::string varName;
};

struct IfStmt : Stmt{
    std::unique_ptr<Expr> cond;
    std::vector<std::unique_ptr<Stmt>> body;
    std::vector<std::unique_ptr<Stmt>> elseBody;
};

struct GotoStmt : Stmt{
    std::string label;
    std::string whenVar;
    std::unique_ptr<Expr> whenVal;
};

struct LabelStmt : Stmt{
    std::string name;
};

struct ReturnStmt : Stmt{
    std::unique_ptr<Expr> value;
};

struct FinishStmt : Stmt{
    int code;
};

struct IncludeStmt : Stmt{
    std::string target;
    bool isFile;
};

struct FuncDefStmt : Stmt{
    std::string kind;
    std::string name;
    bool isDefault;
    std::vector<std::pair<std::string, std::string>> params;
    std::vector<std::unique_ptr<Stmt>> body;
};