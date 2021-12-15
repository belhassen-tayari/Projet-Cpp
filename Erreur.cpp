#include "Erreur.h"
#include <string.h>

Erreur::Erreur(char *ch){
    strcpy(msg, ch);
}

char * Erreur::getMessage(){
    return msg;
}

Erreur::~Erreur(){}
