#ifndef FICHIER_H
#include "Employee.h"
#include "Institution.h"
#define FICHIER_H


class Fichier{
    private:
        char fileName[50];

    public:
        Fichier(char *);
        ~Fichier();

        //Methode retourne 1 si le fichier existe deja et 0 sinon
        int isFileExist();

        //Methode qui retourne le taille de fichier
        int tailleFichier();

        /*Methode qui lire des objet de type Administrateur/Responsable/Ouvrier/... depuis un fichier et le charge
          dans le tableau des employers dans le classe Institution puisque le classe Fichier et
          un classe Amis de Institution et puis il aura l'accées au differente membre de la classe*/
        void setDataInFile(Institution*);

        //Methode qui charge les objet dans un tableau a partir d'un fichier
        Institution * getDataFromFile();
};

#endif
