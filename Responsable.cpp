#include "Responsable.h"

Responsable::Responsable(char *cinp , char* nomp, char *prenomp, int agep, float salairep,int nbCon):Employee(cinp,nomp,prenomp,agep,salairep){
    setNbrJrConge(nbCon);
    setNbrJrCongeRestant(nbCon);
}

Responsable::~Responsable()
{
    //dtor
}
