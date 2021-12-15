#ifndef ADMINISTRATEUR_H
#include "Employee.h"
#define ADMINISTRATEUR_H


class Administrateur:public Employee{
    public:
        Administrateur(char *,char *, char *, int , float, int);
        virtual ~Administrateur();


};

#endif // ADMINISTRATEUR_H
