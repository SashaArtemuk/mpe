#include "StandartFunctions.h"
#include <math.h>



Plus::Plus(){
    type=AbstractF::operatr;
    name="+";
    count=2;
    priority=25;
}

double Plus::calc(std::vector<double> a){
    return a[0]+a[1];
}

Minus::Minus(){
    type=AbstractF::operatr;
    name="-";
    count=2;
    priority=25;
}

double Minus::calc(std::vector<double> a){
    return (a[1]-a[0]);
}

Mu::Mu(){
    type=AbstractF::operatr;
    name="*";
    count=2;
    priority=30;
}

double Mu::calc(std::vector<double> a){
    return a[0]*a[1];
}


Divide::Divide(){
    type=AbstractF::operatr;
    name="/";
    count=2;
    priority=30;
}

double Divide::calc(std::vector<double> a){
    return a[1]/a[0];
}


Pow::Pow(){
    type=AbstractF::operatr;
    name="^";
    count=2;
    priority=40;
}

double Pow::calc(std::vector<double> a){
    double t=0.5;
    for(int i=0;i<10;i++){
        if(a[0]==t)
            return pow(a[1],a[0]);
        t/=2;
    }
    if(a[0]!=int(a[0]))
    if(a[1]<0){
        a[1]*=-1;
        return (pow(a[1],a[0]))*-1;
    }
        return pow(a[1],a[0]);
}

Negator::Negator(){
    type=AbstractF::func;
    name="-";
    count=1;
    priority=35;
}

double Negator::calc(std::vector<double> a){
    return a[0]*-1;
}

Plusator::Plusator(){
    type=AbstractF::func;
    name="+";
    count=1;
    priority=35;
}

double Plusator::calc(std::vector<double> a){
    return a[0];
}

Modul::Modul(){
    type=AbstractF::func;
    name="abs";
    count=1;
    priority=50;
}

double Modul::calc(std::vector<double> a){
    return fabs(a[0]);
}

Log::Log(){
    type=AbstractF::func;
    name="log";
    count=2;
    priority=55;
}

double Log::calc(std::vector<double> a){
    return log(a[0])/log(a[1]);
}

Round::Round(){
    type=AbstractF::func;
    name="round";
    count=1;
    priority=45;
}

double Round::calc(std::vector<double> a){
    return round(a[0]);
}

Mod::Mod(){
    type=AbstractF::operatr;
    name="mod";
    count=2;
    priority=45;
}

double Mod::calc(std::vector<double> a){
    return (int(a[1])%int(a[0]));
}

Div::Div(){
    type=AbstractF::operatr;
    name="div";
    count=2;
    priority=45;
}

double Div::calc(std::vector<double> a){
    return int(a[1]/a[0]);
}

E::E(){
    type=AbstractF::consta;
    name="e";
    count=0;
    priority=0;
}

double E::calc(std::vector<double> a){
    return M_E;
}


