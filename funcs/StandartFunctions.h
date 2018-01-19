#ifndef STANDARTFUNCTIONS_H
#define STANDARTFUNCTIONS_H
#include "AbstractF.h"
#include <vector>

class Plus : public AbstractF
{
    public:
        Plus();
        double calc(std::vector<double> a);
    protected:

    private:
};

class Minus : public AbstractF
{
    public:
        Minus();
        double calc(std::vector<double> a);

    protected:

    private:
};

class Mu : public AbstractF
{
    public:
        Mu();
        double calc(std::vector<double> a);

    protected:

    private:
};
class Round : public AbstractF
{
    public:
        Round();
        double calc(std::vector<double> a);

    protected:

    private:
};

class Divide : public AbstractF
{
    public:
        Divide();
        double calc(std::vector<double> a);

    protected:

    private:
};

class Pow : public AbstractF
{
    public:
        Pow();
        double calc(std::vector<double> a);

    protected:

    private:
};

class Negator : public AbstractF
{
    public:
        Negator();
        double calc(std::vector<double> a);


    protected:

    private:
};

class Plusator : public AbstractF
{
    public:
        Plusator();
        double calc(std::vector<double> a);


    protected:

    private:
};

class Modul : public AbstractF
{
    public:
        Modul();
        double calc(std::vector<double> a);


    protected:

    private:
};

class Log : public AbstractF
{
    public:
        Log();
        double calc(std::vector<double> a);


    protected:

    private:
};

class Mod : public AbstractF
{
    public:
        Mod();
        double calc(std::vector<double> a);


    protected:

    private:
};

class Div : public AbstractF
{
    public:
        Div();
        double calc(std::vector<double> a);


    protected:

    private:
};
class E : public AbstractF
{
    public:
        E();
        double calc(std::vector<double> a);


    protected:

    private:
};
#endif // STANDARTFUNCTIONS_H
