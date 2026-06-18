#pragma once

#include <memory>
#include <string>
#include <vector>
#include "../parser/parser.h"
struct Node{
    virtual ~Node() = default;
};

struct NumNode{
    double value;
};





