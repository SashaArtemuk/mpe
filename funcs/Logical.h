#ifndef LOGICAL_H
#define LOGICAL_H
#include "AbstractF.h"

class Not : public AbstractF
{
    public:
        Not();
        double calc(std::vector<double> a);
    protected:

    private:
};

class Or : public AbstractF
{
    public:
        Or();
        double calc(std::vector<double> a);
    protected:

    private:
};

class And : public AbstractF
{
    public:
        And();
        double calc(std::vector<double> a);
    protected:

    private:
};

class If : public AbstractF
{
    public:
        If();
        double calc(std::vector<double> a);
    protected:

    private:
};

#endif // LOGICAL_H
