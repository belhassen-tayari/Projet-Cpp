#include "Fichier.h"
#include "Institution.h"
#include<string.h>
#include<fstream>
#include<iostream>
#include "Administrateur.h"
#include "Ouvrier.h"
#include "Technicien.h"
#include "Responsable.h"
#include "ALabo.h"
#include "Erreur.h"

#define NBR_OUVRIER 28
#define NBR_TECHNICIEN 35
#define NBR_RESPONSABLE 39
#define NBR_ALABO 43
#define NBR_ADMINISTRATEUR 90


using namespace std;

Fichier::Fichier(char *f){
    strcpy(fileName, f);
}

Fichier::~Fichier(){}


//Methode retourne 1 si le fichier existe deja et 0 sinon
int Fichier::isFileExist(){
    fstream f;

    f.open(fileName);

    if(f.fail()){
        f.close();
        return 0;
    }else{
        f.close();
        return 1;
    }
}


//Methode qui charge des donnees dans une fichier
void Fichier::setDataInFile(Institution *i){
    ofstream f;
    int j;
    f.open(fileName);
    Employee *aux = i->t;

    for(j = 0; j<i->nbEmployee; j++){
        f<<aux->getNbrJrConge()<<';'<<aux->getCin()<<';'<<aux->getNom()<<';'<<aux->getPrenom()<<';'<<aux->getAge()<<';'<<aux->getSalaire()<<';'<<aux->estEnConge()<<';'<<aux->getNbrJrCongeRestant()<<';'<<endl;
        aux++;

    }
    f.close();
    cout<<"Les donnees sont stocke avec succees\n";
}


//Methode qui retourne le taille de fichier
int Fichier::tailleFichier(){
    ifstream file;
    file.open(fileName);
    string line;
    int taille;
    while(file.good()){
        getline(file, line ,';');
        getline(file, line ,';');
        getline(file, line ,';');
        getline(file, line ,';');
        getline(file, line ,';');
        getline(file, line ,';');
        getline(file, line ,';');
        getline(file, line ,';');
        taille++;

    }
    file.close();

    return taille-1;
}



//Methode qui charge les donnees a partir d'un fichier
Institution * Fichier::getDataFromFile(){
    if(isFileExist()){
    ifstream file;
    file.open(fileName);
    Institution *s = new Institution;

    if(file.is_open()){
        string line;
        char cin[9], nom[50], prenom[50];
        int age,nbrJrCon,nbrJrConRes,estEnConges;
        float salaire;
        int i = 1;
        while(i<=tailleFichier()){

            getline(file,line,';');
            nbrJrCon = stoi(line);
            getline(file,line,';');
            strcpy(cin, line.c_str());
            getline(file,line,';');
            strcpy(nom, line.c_str());
            getline(file,line,';');
            strcpy(prenom, line.c_str());
            getline(file,line,';');
            age = stoi(line);
            getline(file,line,';');
            salaire = stof(line);
            getline(file,line,';');
            estEnConges = stoi(line);
            getline(file,line,';');
            nbrJrConRes = stoi(line);
            if(nbrJrCon == NBR_ADMINISTRATEUR){
                Administrateur a(cin, nom, prenom, age, salaire, nbrJrCon);
                a.setNbrJrCongeRestant(nbrJrConRes);
                if(estEnConges){
                    a.setEnConge(0);
                }
                s->addEmployee(a);
            }else if(nbrJrCon == NBR_ALABO){
                    ALabo al(cin, nom, prenom , age, salaire, nbrJrCon);
                    al.setNbrJrCongeRestant(nbrJrConRes);
                    if(estEnConges){
                    al.setEnConge(0);
                }
                    s->addEmployee(al);
            }else if(nbrJrCon == NBR_OUVRIER){
                Ouvrier o(cin, nom, prenom, age , salaire, nbrJrCon);
                o.setNbrJrCongeRestant(nbrJrConRes);
                if(estEnConges){
                    o.setEnConge(0);
                }
                s->addEmployee(o);
            }else if(nbrJrCon == NBR_RESPONSABLE){
                Responsable r(cin, nom, prenom, age , salaire, nbrJrCon);
                r.setNbrJrCongeRestant(nbrJrConRes);
                if(estEnConges){
                    r.setEnConge(0);
                }
                s->addEmployee(r);
            }else if(nbrJrCon == NBR_TECHNICIEN){
                Technicien t(cin, nom, prenom, age , salaire, nbrJrCon);
                t.setNbrJrCongeRestant(nbrJrConRes);
                if(estEnConges){
                    t.setEnConge(0);
                }
                s->addEmployee(t);
            }
            i++;
        }

    }



    file.close();
    cout<<"Les donnees sont charger avec succees\n";
    return s;
    }else{
        Erreur e("Le Fichier n'existe pas !");
        throw e;
        cout<<"Le Fichier n'existe pas , veuillez saisir des donnees\n";
        return NULL;
    }
}



