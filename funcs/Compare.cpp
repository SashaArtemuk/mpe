#include "Compare.h"

Less::Less(){
    type=AbstractF::operatr;
    name="<";
    count=2;
    priority=20;
}

double Less::calc(std::vector<double> a){
    return (a[1]<a[0]);
}

More::More(){
    type=AbstractF::operatr;
    name=">";
    count=2;
    priority=20;
}

double More::calc(std::vector<double> a){
    return (a[1]>a[0]);
}

Equals::Equals(){
    type=AbstractF::operatr;
    name="=";
    count=2;
    priority=20;
}

double Equals::calc(std::vector<double> a){
    return (a[1]==a[0]);
}
