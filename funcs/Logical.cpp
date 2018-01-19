#include "Logical.h"

Not::Not(){
    type=AbstractF::func;
    name="!";
    count=1;
    priority=15;
}

double Not::calc(std::vector<double> a){
    return !(a[0]);
}

Or::Or(){
    type=AbstractF::operatr;
    name="||";
    count=2;
    priority=5;
}

double Or::calc(std::vector<double> a){
    return ((a[1])||(a[2]));
}

And::And(){
    type=AbstractF::operatr;
    name="&&";
    count=2;
    priority=10;
}

double And::calc(std::vector<double> a){
    return (a[0]&&a[1]);
}

If::If(){
    type=AbstractF::func;
    name="if";
    count=3;
    priority=0;
}

double If::calc(std::vector<double> a){
    if(a[2])
        return a[1];
    else
        return a[0];
}
