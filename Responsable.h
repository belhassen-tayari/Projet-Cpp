#ifndef RESPONSABLE_H
#define RESPONSABLE_H

#include "Employee.h"


class Responsable:public Employee{
    public:
        Responsable(char *,char *, char *, int , float, int);
        ~Responsable();

    protected:

    private:
};

#endif // RESPONSABLE_H
