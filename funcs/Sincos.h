#ifndef SINCOS_H
#define SINCOS_H
#include "AbstractF.h"

class Sin : public AbstractF
{
    public:
        Sin();
        double calc(std::vector<double> a);
    protected:

    private:
};

class Cos : public AbstractF
{
    public:
        Cos();
        double calc(std::vector<double> a);
    protected:

    private:
};

class Deg : public AbstractF
{
    public:
        Deg();
        double calc(std::vector<double> a);
    protected:

    private:
};

class Pi : public AbstractF
{
    public:
        Pi();
        double calc(std::vector<double> a);
    protected:

    private:
};
#endif // SINCOS_H
