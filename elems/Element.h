#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>

class Element
{
    public:
        enum Type{operatr = 1, func, operand, rozdil};
        Type type;
        std::string value;

    protected:

    private:
};

#endif // ELEMENT_H
