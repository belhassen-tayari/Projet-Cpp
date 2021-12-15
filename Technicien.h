#ifndef TECHNICIEN_H
#include "Employee.h"
#define TECHNICIEN_H


class Technicien:public Employee{
    public:
        Technicien(char *,char *, char *, int , float, int);
        ~Technicien();

};

#endif // TECHNICIEN_H
