#pragma once

#include <stack>
#include <utility>
#include <string>

class RPN{
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();
        void solve(const std::string &str);
        void doOp(std::string token);
        void displayResult();
};
