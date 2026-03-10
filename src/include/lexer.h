#include <string>
#include <vector>
#include <unordered_map>

enum class TokenType{
    // literals
    INT_LIT, FLOAT_LIT, STRING_LIT, TRUE, FALSE,
    // types
    INT, FLOAT, STRING, BOOL,
    // keywords
    IF, ELSE, END, GOTO, WHEN, LABEL, PRINT,
    ENDLINE, INPUT, FINISH, FUNC, VOID, FLAG,
    DEFAULT, RETURN, INCLUDE,
    // operators
    PLUS, MINUS, MULT, DIV, MOD, EQUALS, EQEQ, NEQ,
    LT, GT, LTE, GTE, AND, OR, NOT,
    // symbols
    LPAREN, RPAREN, COMMA, COLON, 
    // other
    IDENTIFIER, EOF_TOKEN
};

struct Token{
    TokenType type;
    std::string value;
    int line;
};

class Lexer{
    private:
        std::string source;             //source code
        int start;                      //start position of the current token
        int current;                    //current position in the source code
        int line;                       //current line for error reporting
        std::vector<Token> tokens;      //output tokens
        std::unordered_map<std::string, TokenType> keywords; //map of keywords to token types

        void scanToken();
        void scanString();
        void scanNumber();
        void scanIdentifier();
        void skipComment();
        void skipWhitespace();

        char advance();
        char peek();
        char peekNext();

        bool match(char expected);

        bool isAtEnd();
        bool isDigit(char c);
        bool isAlpha(char c);
        bool isAlphaNumeric(char c);

        void addToken(TokenType type);
        void addToken(TokenType type, const std::string& value);

    public:
        Lexer(const std::string& source);
        std::vector<Token> tokenize();
};
