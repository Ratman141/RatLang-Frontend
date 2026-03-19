#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include "../ast/ast.h"
#include "../error/error.h"


struct Value{
    enum class Type{
        INT, FLOAT, STRING, BOOL, VOID
    };
    Type type;

    int asInt = 0;
    double asFloat = 0.0;
    std::string asString = "";
    bool asBool = false;

    static Value makeInt(int v);
    static Value makeFloat(double v);
    static Value makeString(const std::string& v);
    static Value makeBool(bool v);
    static Value makeVoid();
};

class Interpreter{
    public:
        Interpreter();
        void execute(const std::vector<std::unique_ptr<Stmt>>& program);

    private:
        //execution statements
        void executeStmt(Stmt* stmt);

        void executeDecl(DeclStmt* stmt);
        void executeAssign(AssignStmt* stmt);
        void executePrint(PrintStmt* stmt);
        void executeEndLine(EndLineStmt* stmt);
        void executeIf(IfStmt* stmt);
        void executeGoto(GotoStmt* stmt);
        void executeLabel(LabelStmt* stmt);
        void executeReturn(ReturnStmt* stmt);
        void executeFinish(FinishStmt* stmt);
        void executeInclude(IncludeStmt* stmt);
        void executeFuncDef(FuncDefStmt* stmt);
        void executeBlock(const std::vector<std::unique_ptr<Stmt>>& block);


        // evaluation expressions
        Value evalExpr(Expr* expr);

        Value evalNumber(NumberExpr* expr);
        Value evalString(StringExpr* expr);
        Value evalBool(BoolExpr* expr);
        Value evalVar(VarExpr* expr);
        Value evalBinary(BinaryExpr* expr);
        Value evalCall(CallExpr* expr);

        // scope
        std::stack<std::unordered_map<std::string, Value>> scopeStack;

        void pushScope();
        void popScope();

        Value getVar(const std::string& name, int line);

        void setVar(const std::string& name, const Value& value, int line);

        void declareVar(const std::string& name, const Value& val, int line);

        // function table
        std::unordered_map<std::string, FuncDefStmt*> functionTable;

        Value callFunction(const std::string& name, const std::vector<Value>& args, int line);

        void handleUnknownFunction(const std::string& name, int argCount, int line);

        // Label map
        std::unordered_map<std::string, int> labelMap;
        void buildLabelMap(const std::vector<std::unique_ptr<Stmt>>& program);

        // return handling
        struct ReturnSignal{
            Value value;
        };

        // include handling
        std::unordered_set<std::string> includedFiles;
        void loadBuiltinLibrary(const std::string& name, int line);
        void loadExternalFile(const std::string& path, int line);

        // built in libraries
        void loadMath();
        void loadString();
        void loadIO();
        
        Value callBuiltin(const std::string& name, const std::vector<Value>& args, int line);

        std::unordered_map<std::string, int> builtinTable;
};