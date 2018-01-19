#ifndef COMPARE_H
#define COMPARE_H
#include "AbstractF.h"

class Less : public AbstractF
{
    public:
        Less();
        double calc(std::vector<double> a);
    protected:

    private:
};

class More : public AbstractF
{
    public:
        More();
        double calc(std::vector<double> a);
    protected:

    private:
};

class Equals : public AbstractF
{
    public:
        Equals();
        double calc(std::vector<double> a);
    protected:

    private:
};


#endif // COMPARE_H
