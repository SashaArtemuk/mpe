#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <map>
#include "elems/Velement.h"
#include "Exceptions.h"
#include <string>
#include <list>

class Calculator
{
    public:
        Calculator();
        void setVelement(Velement a);
        std::list<std::string> getVariables();
        std::vector<std::string> getUnknownVariables();
        double calc();
        void setVariable(std::string name, double val);

    protected:

    private:
        Velement a;
        std::map<std::string,double> variables;
        double getVariable(std::string name);
};

#endif // CALCULATOR_H
