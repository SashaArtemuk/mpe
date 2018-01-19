#include "Compilator.h"
#include "Exceptions.h"
#include <vector>
#include <iostream>

using namespace std;


bool Compilator::toNum(std::string a, double &b){
    if((a[0]>'9' || a[0]<'0')&&(a[0]!='.'))
        return false;
    std::string::size_type sz;
    b=std::stod(a,&sz);
    return (sz==a.length());
}


void Compilator::addDelim(Element e){
    while(!s.empty() && s.back().name!="("){
        if(s.back().isOperator)
            v.vec.push_back(Celement::fromFunc(collection->findOperator(s.back().name)));
        else
             v.vec.push_back(Celement::fromFunc(collection->findFunc(s.back().name,1)));
        s.pop_back();
    }
    if(s.empty())
        throw ExceptionsBadInput();
    if(e.value==")"){
        s.pop_back();
        if(!s.empty() && s.back().isFunc){
            s.back().count++;
            if(!(collection->findFunc(s.back().name,s.back().count)))
                throw ExceptionsBadInput();
             v.vec.push_back(Celement::fromFunc(collection->findFunc(s.back().name,s.back().count)));
             s.pop_back();
        }
    }else{
        if(s.size()>=2){
            if(s[s.size()-2].isFunc)
                s[s.size()-2].count++;
            else{
                    throw ExceptionsBadInput();
            }
        }
        else{
                throw ExceptionsBadInput();
        }
    }

}

void Compilator::push(Element e){
    int p=collection->findOperator(e.value)->getPriority();
    int p1;
    AbstractF* a;
    while(!s.empty() && s.back().name!="("){
        if(s.back().isFunc){
            a=collection->findFunc(s.back().name,1);
            p1=a->getPriority();
        }
        else{
            a=collection->findOperator(s.back().name);
            p1=a->getPriority();
        }
        if(p<=p1){
            v.vec.push_back(Celement::fromFunc(a));
            s.pop_back();
        }
        else
            break;
    }
    s.push_back(Stackelement::fromOperator(e.value));
}

void Compilator::compile(Melements* vec){
    Element *e;
    for(int i=0;i<vec->elements.size();i++){
        e=vec->elements[i];
        if(e->type==Element::operand){
            double d;
            if(toNum(e->value,d))
                v.vec.push_back(Celement::fromConst(d));
            else if(collection->findConst(e->value))
                 v.vec.push_back(Celement::fromFunc(collection->findConst(e->value)));
            else
                v.vec.push_back(Celement::fromVar(e->value));
            continue;
        }
        if(e->type==Element::rozdil){
            if(e->value=="(")
               s.push_back(Stackelement::fromDelim());
            else
                addDelim(*e);
            continue;
        }
        if(i-1>=0 &&((vec->elements[i-1]->type==Element::operand)||(vec->elements[i-1]->value==")")))
            push(*e);
        else
            s.push_back(Stackelement::fromFunc(e->value));

    }
     while(s.size()){
        if(s.back().name!="("){
            if(s.back().isOperator)
                v.vec.push_back(Celement::fromFunc(collection->findOperator(s.back().name)));
            else
                v.vec.push_back(Celement::fromFunc(collection->findFunc(s.back().name,s.back().count+1)));
        s.pop_back();
    }else
            throw ExceptionsBadInput();
    }
}
