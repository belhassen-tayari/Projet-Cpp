#include "Technicien.h"
#include "Employee.h"

Technicien::Technicien(char *cinp , char* nomp, char *prenomp, int agep, float salairep,int nbCon):Employee(cinp,nomp,prenomp,agep,salairep){
    setNbrJrConge(nbCon);
    setNbrJrCongeRestant(nbCon);
}

Technicien::~Technicien(){}
