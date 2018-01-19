#include "Celement.h"

Celement Celement::fromConst(double val){
    Celement a;
    a.t=consta;
    a.value=val;
    return a;
}

Celement Celement::fromVar(std::string str){
    Celement a;
    a.t=var;
    a.name=str;
    return a;
}

Celement Celement::fromFunc(AbstractF* f){
    Celement a;
    a.t=func;
    a.f=f;
    return a;
}
