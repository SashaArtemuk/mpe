#ifndef ABSTRACTF_H
#define ABSTRACTF_H
#include <string>
#include <vector>

class AbstractF
{
    public:
        enum Type{operatr=1,func,consta};
        typedef std::vector<double> Arguments ;
        Type getType();
        std::string getName();
        int getCount();
        int getPriority();
        virtual double calc(Arguments a=Arguments());
        static const int funcPriority=100000000;
    protected:
        Type type;
        std::string name;
        int count;
        int priority;


    private:
};

#endif // ABSTRACTF_H
