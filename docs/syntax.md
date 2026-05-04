# RatLang Syntax Guide

main.rl

## Variables
Declare a variable with its type and/or assign a value to it
```RatLang
    int x
    float y = 3.14
    string name = "Goethe"
    bool flag = true
```

## Math
Standard math operations, respects precedence
```RatLang
    x = 2 + 3 * 4
    y = x / 2
```

## Print and Input 
```RatLang
    print x
    print "hello"
    endLine
    input x
```

## Simple If
Use when you need to handle only 1 case
```RatLang
    if x == 5
        x = 1
    end
```

## If-Else
Parentheses require an else branch, parser will error without it
```RatLang
    if(x == 5)
        x = 1
    else
        x = 2
    end
```

## Labels and GOTO
```RatLang
    top:
    goto top
    goto top when x == 5
```

## Functions
```RatLang
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
```

## Finish
Exits the program
```RatLang
    finish 0
    finish 1
    finish x
```

## Include
Built-in libraries
```RatLang
    include math
    include string
    include io
```

##User headers
```RatLang
    include "myLibrary.rlh"
```

## Comments
```RatLang
    // this is a comment
    /* another comment */
    /* third
    comment
    */
```