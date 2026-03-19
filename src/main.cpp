#include "interpreter/interpreter.h"
#include "parser/parser.h"
#include "lexer/lexer.h"
#include "error/error.h"
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    try{
        
    }
    catch(const LangError& e){
        return 1;
    }
    return 0;
}