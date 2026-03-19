#include "commands.h"

namespace cmd{
    void Help(){
        std::cout<<"Usage: ratlang <file.rl>\n";
        std::cout<<"Commands:\n";
        std::cout<<"  --help               Show this help message\n";
        std::cout<<"  --version            Show version information\n";
        std::cout<<"  --license            Show license information\n";
        std::cout<<"  --about              Show information about the project\n";
        std::cout<<"  --run <file.rl>      Run the interpreter\n";
    }

    void Version(){
        std::cout<<"RatLang version 1.0.0\n";
    }

    void License(){
        std::cout<<"RatLang is licensed under the GPL v3 License.\n";
    }

    void About(){
        std::cout<<"Empty for the time of development.\n";
    }

    void run(bool& runFile){
        runFile = true;
    }

    void manager(const std::string& arg, bool& runFile){
        if(arg == "--help"){
            Help();
        }
        else if(arg == "--version"){
            Version();
        }
        else if(arg == "--license"){
            License();
        }
        else if(arg == "--about"){
            About();
        }
        else if(arg == "--run"){
            run(runFile);
        }
        else{
            std::cerr<<"Error: Invalid command. Use '--help' for a list of commands.\n";
            std::cerr<<"Usage: ratlang <command> [arguments]\n";
            std::cerr<<"If you want to run a file, use 'ratlang --run <file.rl>'\n";
            throw std::runtime_error("Invalid command");
        }
    }
}