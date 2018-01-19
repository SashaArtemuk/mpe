#include "sincos.h"
#include <math.h>

Pi::Pi()
{
    type=AbstractF::consta;
    name="pi";
    count=0;
    priority=0;
}

double Pi::calc(std::vector<double> a){
    return M_PI;
}

Sin::Sin()
{
    type=AbstractF::func;
    name="sin";
    count=1;
    priority=45;
}

double Sin::calc(std::vector<double> a){
    return (round((sin(a[0]))*10000)/10000.);
}

Cos::Cos()
{
    type=AbstractF::func;
    name="cos";
    count=1;
    priority=45;
}

double Cos::calc(std::vector<double> a){
    return (round((cos(a[0]))*10000)/10000.);
}

Deg::Deg()
{
    type=AbstractF::func;
    name="deg";
    count=1;
    priority=45;
}

double Deg::calc(std::vector<double> a){
    return (round((a[0]*(M_PI/180))*10000)/10000.);
}
