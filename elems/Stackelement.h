#ifndef STACKELEMENT_H
#define STACKELEMENT_H
#include "../funcs/AbstractF.h"
#include <string>

class Stackelement
{
    public:
        bool isFunc;
        bool isOperator;
        std::string name;
        int count;
        static Stackelement fromOperator(std::string name);
        static Stackelement fromFunc(std::string name);
        static Stackelement fromDelim();

    protected:

    private:
};

#endif // STACKELEMENT_H
