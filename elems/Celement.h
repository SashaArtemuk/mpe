#ifndef CELEMENT_H
#define CELEMENT_H
#include "../funcs/AbstractF.h"
#include <string>

class Celement
{
    public:
        enum Type{var=1,consta,func};
        double value;
        std::string name;
        Type t;
        AbstractF *f;
        static Celement fromConst(double val);
        static Celement fromVar(std::string str);
        static Celement fromFunc(AbstractF* f);

    protected:

    private:
};

#endif // CELEMENT_H
