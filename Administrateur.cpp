#include "Administrateur.h"

Administrateur::Administrateur(char *cinp , char* nomp, char *prenomp, int agep, float salairep,int nbCon):Employee(cinp,nomp,prenomp,agep,salairep){
    setNbrJrConge(nbCon);
    setNbrJrCongeRestant(nbCon);
}

Administrateur::~Administrateur()
{
    //dtor
}
