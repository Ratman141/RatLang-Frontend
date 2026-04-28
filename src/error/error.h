#pragma once

#include <string>
#include <stdexcept>

std::string formatMessage(const int line, const std::string& kind, const std::string& message);

class LangError : public std::runtime_error{
    public:
        int line;
        LangError(const int line, const std::string &kind, const std::string& message) : std::runtime_error(formatMessage(line, kind, message)), line(line) {}
};

class LexError : public LangError{
    public:
        LexError(const int line, const std::string& message) : LangError(line, "Lex", message) {}
};

class ParseError :public LangError{
    public:
        ParseError(const int line, const std::string& message) : LangError(line, "Parse", message) {}
};