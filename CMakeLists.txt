cmake_minimum_required(VERSION 3.28.3)
project(RatLang 
    VERSION 0.1.0 
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_library(AST src/ast/ast.cpp)
set_target_properties(AST PROPERTIES PREFIX "")
target_include_directories(AST PUBLIC src/ast)

add_library(LEXER src/lexer/lexer.cpp)
set_target_properties(LEXER PROPERTIES PREFIX "")
target_include_directories(LEXER PUBLIC src/lexer)

add_library(PARSER src/parser/parser.cpp)
set_target_properties(PARSER PROPERTIES PREFIX "")
target_include_directories(PARSER PUBLIC src/parser)

add_library(ERROR src/error/error.cpp)
set_target_properties(ERROR PROPERTIES PREFIX "")
target_include_directories(ERROR PUBLIC src/error)

add_library(INTERPRETER src/interpreter/interpreter.cpp)
set_target_properties(INTERPRETER PROPERTIES PREFIX "")
target_include_directories(INTERPRETER PUBLIC src/interpreter)

add_executable(RatLang src/main.cpp)

target_link_libraries(RatLang PRIVATE
    AST
    LEXER
    PARSER
    INTERPRETER
    ERROR
)

