#pragma once

#include <string>
#include <stdexcept>

class LangError : public std::runtime_error{
    public:
        int line;
        LangError(int line, const std::string& message) : std::runtime_error(message), line(line) {}
};

class LexError : public LangError{
    public:
        LexError(int line, const std::string& message) : LangError(line, message) {}
};

class ParseError :public LangError{
    public:
        ParseError(int line, const std::string& message) : LangError(line, message) {}
};

void lexError(int line, const std::string& message);
void parseError(int line, const std::string& message);

std::string formatMessage(int line, const std::string& kind, const std::string& message);