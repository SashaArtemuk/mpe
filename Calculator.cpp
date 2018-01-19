#include "Calculator.h"
using namespace std;
#include <stack>
#include <iterator>
#include <iostream>


Calculator::Calculator(){
}

void Calculator::setVariable(string name,double val){
    variables[name]=val;
}

void Calculator::setVelement(Velement a){
    this->a=a;
}

std::list<std::string> Calculator::getVariables(){
    std::list<std::string> vec;
    for(int i=0;i<a.vec.size();i++){
        if(a.vec[i].t==Celement::var){
            vec.push_back(a.vec[i].name);
        }
    }
    vec.unique();
    return vec;
}

std::vector<std::string> Calculator::getUnknownVariables(){
    std::list<std::string> vec=getVariables();
    std::vector<std::string> v;
    for(auto i=vec.begin();i!=vec.end();i++){
        map<std::string,double>::iterator it=variables.find((*i));
        if (it == variables.end())
            v.push_back((*i));
    }
    return v;
}

double Calculator::getVariable(string name){
    //std::cout << name << endl;
    map<std::string,double>::iterator it=variables.find(name);
    if (it == variables.end())
        throw ExceptionsVarNotFound(name);

    return variables[name];
}

double Calculator::calc(){
    stack<double> s;
    for(int i=0;i<a.vec.size();i++){
        if(a.vec[i].t==Celement::consta){
            s.push(a.vec[i].value);
            continue;
        }
        if(a.vec[i].t==Celement::var){
                double aaa = getVariable(a.vec[i].name);
        std::string sss = a.vec[i].name;
            s.push(getVariable(a.vec[i].name));
            continue;
        }
        if(a.vec[i].f->getType()==AbstractF::consta){
            s.push(a.vec[i].f->calc());
            continue;
        }
        AbstractF::Arguments arg;
        if(s.size()<a.vec[i].f->getCount())
            throw ExceptionsBadInput();
        for(int j=0;j<a.vec[i].f->getCount();j++){
            arg.push_back(s.top());
            s.pop();
        }
        s.push(a.vec[i].f->calc(arg));
    }


    if(s.size()!=1)
        throw ExceptionsBadInput();

    return s.top();
}
