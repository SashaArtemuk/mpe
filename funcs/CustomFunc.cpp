#include "CustomFunc.h"
#include "../Calculator.h"
#include <iostream>

CustomFunc::CustomFunc(std::string name, int priority, Collection *collection, Velement velement, AbstractF::Type type, int count){
    this->name=name;
    this->priority=priority;
    this->collection=collection;
    this->velement=velement;
    this->type=type;
    this->count=count;
}

std::string CustomFunc::createVarName(int a){
    return "arg"+std::to_string(a);
}

double CustomFunc::calc(std::vector<double> a){
    Calculator calc;
    for(int i=0;i<count;i++){
        calc.setVariable(createVarName(i),a[i]);
    }
    calc.setVelement(velement);
    return calc.calc();
}

Velement CustomFunc::getVelement(){
    return velement;
}
