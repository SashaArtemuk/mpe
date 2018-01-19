#include "Stackelement.h"

Stackelement Stackelement::fromFunc(std::string name){
    Stackelement b;
    b.name=name;
    b.isFunc=true;
    b.isOperator=false;
    b.count=0;
    return b;
}

Stackelement Stackelement::fromOperator(std::string name){
    Stackelement b;
    b.name=name;
    b.isFunc=false;
    b.isOperator=true;
    return b;
}

Stackelement Stackelement::fromDelim(){
    Stackelement b;
    b.isFunc=false;
    b.isOperator=false;
    b.name="(";
    return b;
}




