#ifndef COLLECTION_H
#define COLLECTION_H
#include <vector>
#include "funcs/AbstractF.h"
#include <fstream>
class CustomFunc;


class Collection
{
    public:
        Collection();
        std::vector<AbstractF*> flist;
        int findf(std::string name, int a);
        void load(std::string name);
        void save(std::string name);
        AbstractF* findConst(std::string name);
        AbstractF* findOperator(std::string name);
        AbstractF* findFunc(std::string name,int count);
        AbstractF* findf2(std::string name, int type, int count, int priority);
    protected:

    private:

        CustomFunc* loadFunc(std::ifstream &f1);
        void saveFunc(CustomFunc* a, std::ofstream &f1);
};

#endif // COLLECTION_H
