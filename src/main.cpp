#include "interpreter/interpreter.h"
#include "parser/parser.h"
#include "lexer/lexer.h"
#include "error/error.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) {
    
    // Checks for correct number of arguments
    if(argc < 2){
        std::cerr<<"Error: No input file provided."<<std::endl;
        return 1;
    }
    if(argc >2){
        std::cerr<<"Error: Too many arguments provided."<<std::endl;
        return 1;
    }


    std::string fileName = argv[1];
    std::string fileExtension = fileName.substr(fileName.size() - 3, fileName.size());

    if(fileExtension != ".rl"){
        std::cerr<<"Error: Invalid file type. Expected .rl file."<<std::endl;
        return 1;
    }

    // Opens file
    std::ifstream file;
    file.open(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    // Interpreter
    try{
        
    }
    catch(const LangError& e){
        file.close();
        return 1;
    }
    file.close();

    return 0;
}