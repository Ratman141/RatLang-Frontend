#include <iostream>
#include "../src/lexer/lexer.h"

std::string tokenTypeToString(TokenType t) {
    switch(t) {
        case TokenType::INT_LIT: return "INT_LIT";
        case TokenType::FLOAT_LIT: return "FLOAT_LIT";
        case TokenType::STRING_LIT: return "STRING_LIT";
        case TokenType::INT: return "INT";
        case TokenType::FLOAT: return "FLOAT";
        case TokenType::STRING: return "STRING";
        case TokenType::BOOL: return "BOOL";

        case TokenType::IF: return "IF";
        case TokenType::ELSE: return "ELSE";
        case TokenType::END: return "END";
        case TokenType::RETURN: return "RETURN";
        case TokenType::FUNC: return "FUNC";
        case TokenType::FLAG: return "FLAG";
        case TokenType::PRINT: return "PRINT";

        case TokenType::PLUS: return "PLUS";
        case TokenType::MINUS: return "MINUS";
        case TokenType::MULT: return "MULT";
        case TokenType::DIV: return "DIV";
        case TokenType::MOD: return "MOD";
        case TokenType::EQUALS: return "EQUALS";
        case TokenType::EQEQ: return "EQEQ";
        case TokenType::NEQ: return "NEQ";

        case TokenType::LT: return "LT";
        case TokenType::GT: return "GT";
        case TokenType::LTE: return "LTE";
        case TokenType::GTE: return "GTE";

        case TokenType::AND: return "AND";
        case TokenType::OR: return "OR";
        case TokenType::NOT: return "NOT";

        case TokenType::LPAREN: return "LPAREN";
        case TokenType::RPAREN: return "RPAREN";
        case TokenType::COMMA: return "COMMA";
        case TokenType::COLON: return "COLON";
        case TokenType::DOT: return "DOT";

        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::EOF_TOKEN: return "EOF";

        default: return "UNKNOWN";
    }
}

void printToken(const Token& t) {
    std::cout
        << "Token(" << tokenTypeToString(t.type)
        << ", \"" << t.value
        << "\", line " << t.line << ")\n";
}

void runTest(const std::string& name, const std::string& input) {
    std::cout << "\n===== " << name << " =====\n";

    Lexer lexer(input);
    std::vector<Token> tokens = lexer.tokenize();

    for (const auto& t : tokens) {
        printToken(t);
    }
}

int main() {

    // Arithmetic
    runTest("Arithmetic", "1 + 2 * 3");

    // Assignment
    runTest("Assignment", "x = 10\ny = x + 5");

    // Floats
    runTest("Floats", "3.14 + 2.0");

    // Strings
    runTest("Strings", "\"hello\" + \"world\"");

    // Keywords + your system types
    runTest("Keywords + Types",
        "flag isTrue\n"
        "func add(a, b)\n"
        "return a + b\n"
        "end"
    );

    // Logic
    runTest("Logic", "a == b && c != d || !flag");

    // Function usage difference (important for your design)
    runTest("Flag vs Func",
        "flag check = true\n"
        "func sum = 10 + 20"
    );

    // Comments
    runTest("Comments",
        "x = 1\n"
        "// comment line\n"
        "y = 2\n"
        "/* block comment */\n"
        "z = 3"
    );

    return 0;
}