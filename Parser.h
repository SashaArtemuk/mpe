#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include "collection.h"
#include "elems/melements.h"

class Parser
{
    public:
        Parser(Collection *a, Melements *b);
        void parse(std::string a);
        Collection *collection;
        Melements *elems;
        void setLengs();
    protected:

    private:
        std::string str;
        std::vector<int> lengs;
        void push(Element::Type prev, std::string a);

        void operandr(int &p1,int &p2);
};

#endif // PARSER_H
