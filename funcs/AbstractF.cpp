#include "AbstractF.h"

AbstractF::Type AbstractF::getType(){
    return type;
}

std::string AbstractF::getName(){
    return name;
}

int AbstractF::getCount(){
    return count;
}

int AbstractF::getPriority(){
     return priority;
}

double AbstractF::calc(AbstractF::Arguments a){
}

