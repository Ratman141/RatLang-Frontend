cmake_minimum_required(VERSION 3.28.3)
project(CalcLang VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_library(AST src/ast.cpp)
set_target_properties(AST PROPERTIES PREFIX "")
target_include_directories(AST PUBLIC src/include)

add_library(LEXER src/lexer.cpp)
set_target_properties(LEXER PROPERTIES PREFIX "")
target_include_directories(LEXER PUBLIC src/include)

add_library(PARSER src/parser.cpp)
set_target_properties(PARSER PROPERTIES PREFIX "")
target_include_directories(PARSER PUBLIC src/include)

add_library(ERROR src/error.cpp)
set_target_properties(ERROR PROPERTIES PREFIX "")
target_include_directories(ERROR PUBLIC src/include)

add_library(INTERPRETER src/interpreter.cpp)
set_target_properties(INTERPRETER PROPERTIES PREFIX "")
target_include_directories(INTERPRETER PUBLIC src/include)

add_executable(CalcLang src/main.cpp)
target_link_libraries(CalcLang PRIVATE AST)
target_link_libraries(CalcLang PRIVATE LEXER)
target_link_libraries(CalcLang PRIVATE PARSER)
target_link_libraries(CalcLang PRIVATE INTERPRETER)
target_link_libraries(CalcLang PRIVATE ERROR)

