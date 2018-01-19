#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
#include <string>

class ExceptionsVarNotFound: public std::logic_error
{
   public: explicit ExceptionsVarNotFound (std::string varname):
        logic_error("Var '"+varname+"' not found")
    { }
};

class ExceptionsBadInput: public std::logic_error
{
    public: explicit ExceptionsBadInput():
           logic_error("Bad input")
       { }
};
#endif // EXCEPTIONS_H
