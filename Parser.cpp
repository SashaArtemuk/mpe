#include "Parser.h"
#include <iostream>
#include <algorithm>

using namespace std;


Parser::Parser(Collection *a, Melements *b){
    collection=a;
    elems=b;
}

void Parser::parse(string a){
    int p1=0,p2,oppose1=0,oppose2=0;
    str=a;
    while(p1!=a.length()){
        p2=a.length();
        if(a[p1]=='(' || a[p1]==')' || a[p1]==','){
            string temp;
            temp+=a[p1];
            operandr(oppose1,p1);
                oppose1=p1+1;
            push(Element::rozdil,temp);
        }
        else{
            bool breik=false;
            int r=0;
            while(!breik){
                int c=lengs[r];
                p2=p1+c;
                string temp;
                temp=a.substr(p1,p2-p1);
                int e=collection->findf(temp,0);
                if(e>=0){
                    int t=collection->flist[e]->getType();
                    operandr(oppose1,p1);
                        oppose1=p1+collection->flist[e]->getName().length();
                    if(t==AbstractF::consta)
                        push(Element::operand,temp);
                    else
                        push(Element::operatr,temp);
                    p1 = oppose1 -1;
                    break;

                }
                if(p2==p1 || r==lengs.size()){
                    breik=true;
                }
                r++;
            }
        }
        p1++;
    }
    p1=a.length();
    operandr(oppose1,p1);
}

void Parser::push(Element::Type prev, string a){
    if(a.length()){
        Element *b=new Element;
        b->type=prev;
        b->value=a;
        elems->elements.push_back(b);
    }
}


void Parser::operandr(int &p1, int &p2){
    string temp;
    temp=str.substr(p1,p2-p1);
    push(Element::operand,temp);
    p1=p2;

}

void Parser::setLengs(){
    for(int i=0;i<collection->flist.size();i++){
        string a=collection->flist[i]->getName();
        int e=a.length();
if((find(lengs.begin(),lengs.end(),e))==lengs.end())
            lengs.push_back(e);

    }
    sort(lengs.begin(),lengs.end(),greater<int>());
}
