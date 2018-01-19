#ifndef CUSTOMFUNC_H
#define CUSTOMFUNC_H
#include "AbstractF.h"
#include <string>
#include "../collection.h"
#include "../elems/Velement.h"

class CustomFunc : public AbstractF
{
    public:
        CustomFunc(std::string name, int priority, Collection *collection, Velement velement, Type type, int count);
        double calc(std::vector<double> a);
        Velement getVelement();
    protected:

    private:
        Velement velement;
        Collection *collection;
        std::string createVarName(int a);
};

#endif // CUSTOMFUNC_H
