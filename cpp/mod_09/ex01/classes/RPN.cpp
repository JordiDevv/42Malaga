#include "RPN.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    RPN::RPN() {}
    RPN::RPN(const RPN& ref) : _stack(ref._stack) {}

    RPN& RPN::operator=(const RPN& ref)
    {
        if (this != &ref) _stack = ref._stack;
        return *this;
    }

    RPN::~RPN() {}


  // **************************************************** //
 //                  Operators utils                     //
// **************************************************** //

    bool RPN::isOperator(char c)
    {
        switch (c)
        {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            default:
                return false;
        }
    }


  // **************************************************** //
 //                    Public API                        //
// **************************************************** //

    bool RPN::validLine(const std::string& line)
    {
        size_t n = 0;
        size_t op = 0;
    
        for (size_t i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i])) n++;
            else if (isOperator(line[i])) op++;
            else if (isspace(line[i])) continue;
            else return false;
            
            if ((isdigit(line[i]) || isOperator(line[i]))
                && i + 1 < line.size() && line[i + 1] != ' ')
                return false;

            if (n - op < 1) return false;
        }

        return n - op == 1 ? true : false;
    }

    void RPN::processLine(const std::string& line)
    {
        
    }
