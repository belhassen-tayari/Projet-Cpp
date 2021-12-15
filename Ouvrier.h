#ifndef OUVRIER_H
#define OUVRIER_H
#include "Employee.h"


class Ouvrier:public Employee{
    public:
        Ouvrier(char *,char *, char *, int , float,int);
        ~Ouvrier();

    protected:

    private:
};

#endif // OUVRIER_H
