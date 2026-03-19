#include "interpreter/interpreter.h"
#include "commands/commands.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) {

    // Checks for correct number of arguments
    if(argc < 2){
        std::cerr<<"Error: Not enough arguments provided."<<std::endl;
        return 1;
    }
    if(argc > 3){
        std::cerr<<"Error: Too many arguments provided."<<std::endl;
        return 1;
    }

    bool fileRun = false;

    try{
        cmd::manager(argv[1], fileRun);
    }
    catch(const std::runtime_error& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    if(fileRun){

        if(argc < 3){
            std::cerr<<"Error: No file provided to run."<<std::endl;
            return 1;
        }

        std::string fileName = argv[2];


        if(fileName.size() < 4){
            std::cerr<<"Error: Invalid file name."<<std::endl;
            return 1;
        }
        
        std::string fileExtension = fileName.substr(fileName.size() - 3);

        if(fileExtension != ".rl"){
            std::cerr<<"Error: Invalid file type. Expected .rl file."<<std::endl;
            return 1;
        }
        // Opens file
        std::ifstream file;
        file.open(fileName);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open file.\n";
            return 1;
        }

    // Interpreter
        try{
        
        }
        catch(const LangError& e){
            std::cerr << e.what() << std::endl;
            return 1;
        }
        file.close();
    }

    return 0;
}