program     =   statement* EOF
statement   =   declaration | assignment | print | input
                if_simple | if_else | goto | label
                func_def | void_def | flag_def 
                finish | include | endLine | return

declaration =   ( "int" | "float" | "string" | "bool" )   IDENTIFIER
                ( "int" | "float" | "string" | "bool" )   IDENTIFIER "=" expression

assignment  =   IDENTIFIER "=" expression

func_def    =   ["DEFAULT"] "func" IDENTIFIER "(" params ")"
                    body
                "end"

void_def    =   ["DEFAULT"] "void" IDENTIFIER "(" params ")"
                    body
                "end"

flag_def    =   ["DEFAULT"] "flag" IDENTIFIER "(" params ")"
                    body
                "end"

return      =   "return" expression

params      =   (type IDENTIFIER ("," type IDENTIFIER)*)?
type        =   "int" | "float" | "string" | "bool"

if_simple   =   "if" condition
                    body
                "end"
if_else     =   "if(" conditions ")"
                    body
                "else"
                    body
                "end"
condition   =   expression ( "==" | "!=" | "<" | ">" | "<=" | ">=" ) expression

goto        =   "goto" IDENTIFIER
                "goto" IDENTIFIER "when" IDENTIFIER "==" expression

label       =   IDENTIFIER ":"

print       =   "print(" expression ")"
endLine     =   "endLine"
input       =   "input" IDENTIFIER
finish      =   "finish" NUMBER
include     =   "include" STRING | "include" IDENTIFIER

expression  =   term (( "+" | "-" ) term)*
term        =   factor (( "*" | "/" ) factor)*
factor      =   NUMBER | FLOAT | STRING | "true" | "false"
                IDENTIFIER | IDENTIFIER "(" args ")"

args        =   (expression ("," expression)*)?