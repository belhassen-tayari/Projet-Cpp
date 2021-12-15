#include "ALabo.h"

ALabo::ALabo(char *cinp , char* nomp, char *prenomp, int agep, float salairep,int nbCon):Employee(cinp,nomp,prenomp,agep,salairep){
    setNbrJrConge(nbCon);
    setNbrJrCongeRestant(nbCon);
}

ALabo::~ALabo(){}
