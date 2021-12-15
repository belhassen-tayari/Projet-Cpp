#ifndef INSTITUTION_H
#define INSTITUTION_H
#include "Employee.h"


class Institution{

    private:
        int nbEmployee;
        Employee *t;

    public:
        Institution();
        Institution(int);
        ~Institution();
        // Methode retourne un employer depuis son indice dans le tableau
        Employee *getTMember(int);

        Employee* recherche(char *);
        Employee* recherche(char *, char *);
        void afficher();
        void addEmployee(Employee);
        void supprimerEmployee(char *);
        int getNbEmployee();
        friend class Fichier;
        friend class Statistique;
};

#endif // INSTITUTION_H
