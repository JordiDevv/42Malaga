#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<int> _stack;
    
        bool isOperator(char c);
        void pushOperand(int n);
        void applyOperator(char op);

    public:
        RPN();
        RPN(const RPN& ref);
        RPN& operator=(const RPN& ref);
        ~RPN();

        bool validLine(const std::string& line);
        void processLine(const std::string& line);
};

#endif
