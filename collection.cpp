#include "collection.h"
#include "funcs/StandartFunctions.h"
#include "elems/Velement.h"
#include "elems/Celement.h"
#include "funcs/CustomFunc.h"
#include "funcs/Compare.h"
#include "funcs/Logical.h"
#include "funcs/sincos.h"
#include "Exceptions.h"

using namespace std;

Collection::Collection()
{
    flist.push_back(new Plus);
    flist.push_back(new Minus);
    flist.push_back(new Mu);
    flist.push_back(new Divide);
    flist.push_back(new Pow);
    flist.push_back(new Negator);
    flist.push_back(new Pi);
    flist.push_back(new Plusator);
    flist.push_back(new Modul);
    flist.push_back(new Log);
    flist.push_back(new Less);
    flist.push_back(new More);
    flist.push_back(new Equals);
    flist.push_back(new Not);
    flist.push_back(new Or);
    flist.push_back(new And);
    flist.push_back(new Sin);
    flist.push_back(new Cos);
    flist.push_back(new Deg);
    flist.push_back(new If);
    flist.push_back(new Round);
    flist.push_back(new Mod);
    flist.push_back(new Div);
    flist.push_back(new E);
}

int Collection::findf(string name, int a){
    for(int i=0;i<flist.size();i++){
        if(flist[i]->getName()==name)
            if(flist[i]->getType()==a || a==0)
            return i;
    }
    return -1;
}

AbstractF* Collection::findf2(std::string name, int type, int count, int priority){
    for(int i=0;i<flist.size();i++){
        if(flist[i]->getName()==name)
            if(flist[i]->getType()==type && flist[i]->getCount()==count)
            return flist[i];
    }
    return 0;
}

AbstractF* Collection::findConst(std::string name){
    return findf2(name,AbstractF::consta,0,0);
}

AbstractF* Collection::findOperator(std::string name){
    AbstractF* res = findf2(name,AbstractF::operatr,2,0);
    if (res == 0)
        throw ExceptionsVarNotFound(name);
    return res;
}

AbstractF* Collection::findFunc(std::string name,int count){
    AbstractF* res = findf2(name,AbstractF::func,count,0);
    if (res == 0)
        throw ExceptionsVarNotFound(name);
    return res;
}


CustomFunc* Collection::loadFunc(std::ifstream &f1){
    int type;
    std::string name;
    int count;
    int priority;
    int nelement;
    Velement vec;
    f1>>type >> name >> count >> priority >> nelement;
    for(int j=0;j<nelement;j++){
            int type2;
            f1 >> type2;
            if(static_cast<Celement::Type>(type2)==Celement::var){
                std::string s;
                f1 >> s;
                vec.vec.push_back(Celement::fromVar(s));
            }
            else if(static_cast<Celement::Type>(type2)==Celement::consta){
                double t;
                f1 >> t;
                vec.vec.push_back(Celement::fromConst(t));
            }
            else if(static_cast<Celement::Type>(type2)==Celement::func){
                int t;
                std::string n;
                int c;
                int p;
                f1 >> c >> t >> p >> n;
                vec.vec.push_back(Celement::fromFunc(findf2(n,t,c,p)));
            }
        }
        return new CustomFunc(name,priority,this,vec,static_cast<AbstractF::Type>(type),count);
}

void Collection::load(std::string name){
    ifstream f1(name);
    int n;
    f1>>n;
    for(int i=0;i<n;i++){
       flist.push_back(loadFunc(f1));
    }
    f1.close();
}

void Collection::saveFunc(CustomFunc* a, ofstream &f1){
    f1<<a->getType()<<endl;
    f1<<a->getName()<<endl;
    f1<<a->getCount()<<endl;
    f1<<a->getPriority()<<endl;
    vector<Celement> vec=a->getVelement().vec;
    f1<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
            f1 << vec[i].t << " ";
        if(vec[i].t==Celement::var)
            f1 << vec[i].name << endl;
        else if(vec[i].t==Celement::consta)
            f1 << vec[i].value << endl;
        else if(vec[i].t==Celement::func){
            f1 << vec[i].f->getCount() << " ";
            f1 << vec[i].f->getType() << " ";
            f1 << vec[i].f->getPriority() << " ";
            f1 << vec[i].f->getName() << endl;
        }
    }
}

void Collection::save(std::string name){
    ofstream f1;
    f1.open(name, std::ofstream::out | std::ofstream::trunc);
    int n=0;
    for(int i=0;i<flist.size();i++)
        if(dynamic_cast<CustomFunc*>(flist[i]))
            n++;
    f1<<n<<std::endl;
    for(int i=0;i<flist.size();i++)
        if(dynamic_cast<CustomFunc*>(flist[i])){
            saveFunc(dynamic_cast<CustomFunc*>(flist[i]),f1);
        }
    f1.close();
}
