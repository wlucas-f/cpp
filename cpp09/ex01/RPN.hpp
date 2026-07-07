#pragma once

#include <stack>
#include <utility>

enum Type{
    Char,
    Int
};

class RPN{
    private:
        std::stack<std::pair<char, Type>> stack;
    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();
};
