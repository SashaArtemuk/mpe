#ifndef COMPILATOR_H
#define COMPILATOR_H
#include "elems/melements.h"
#include "elems/Velement.h"
#include <string>
#include "collection.h"
#include "elems/Stackelement.h"
#include <deque>

class Compilator
{
    public:
        void compile(Melements *vec);
        Collection* collection;
        Velement v;
    protected:

    private:
        void addDelim(Element e);
        void push(Element e);
        bool toNum(std::string a, double &b);
        std::deque<Stackelement> s;
};

#endif // COMPILATOR_H
