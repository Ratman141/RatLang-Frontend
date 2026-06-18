#include <iostream>
#include "../src/ast/ast.h"
#include <string>
using namespace std;

int main(){
    string source = "";
    Lexer lexer(source);
    Parser parser;
    parser.load_tokens(lexer.tokenize());
    
    return 0;
}