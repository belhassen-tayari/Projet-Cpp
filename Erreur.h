#ifndef ERREUR_H
#define ERREUR_H

#include<exception>

using namespace std;

class Erreur:public exception{
    private:
        char msg[50];
    public:
        Erreur(char *);
        ~Erreur();
        char * getMessage();
};

#endif // ERREUR_H
