#include "error.h"
#include <iostream>
#include <cctype>

std::string formatMessage(int line, const std::string& kind, 
                        const std::string& message)
{
    return "[" + kind + " error] at line " + std::to_string(line) + ": " + message;
}