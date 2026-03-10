# RatLang Syntax Guide

main.cl

## Variables
Declare a variable with its type and/or assign a value to it
    int x;
    float y = 3.14
    string name = "Goethe"
    bool flag = true

## Math
Standard math operations, respects precedence
    x = 2 + 3 * 4
    y = x / 2

## Print and Input 
    print x
    print "hello"
    endLine
    input x

## Simple If
Use when you need to handle only 1 case
    if x == 5
        x = 1
    end

## If-Else
Parentheses require an else branch, parser will error without it
    if(x == 5)
        x = 1
    else
        x = 2
    end

## Labels and GOTO
    top:
    goto top
    goto top when x == 5

## Functions
    func add(int a, int b)
        return a + b
    end

    void greet(string name)
        print name
        endLine
    end

    flag isEqual(int a, int b)
        return a == b
    end

## Default functions
Marks an empty function as intentional
    DEFAULT void placeholder()
    end

## Finish
Exits the program
    finish 0
    finish 1
    finish x

## Include
Built-in libraries
    include math
    include string
    include io

User headers
    include "myLibrary.clh"

## Comments
    // this is a comment