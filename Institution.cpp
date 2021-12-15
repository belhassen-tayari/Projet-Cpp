#include "Institution.h"
#include<iostream>
#include<assert.h>
#include<string.h>
#define NMAX 500
#include "Employee.h"

using namespace std;

//Constructeur et Destructeur
Institution::Institution(){
    nbEmployee = 0;
    t = new Employee[NMAX];
}

Institution::Institution(int max){
      nbEmployee = 0;
      t = new Employee[max];

}


//Get Tableaux
Employee *Institution::getTMember(int n){
    assert((n>=0)&&(n<nbEmployee));
    return t+n;
}


//Recherche d'un employer dans un tableau avec le CIN
Employee* Institution::recherche(char *cin){
    Employee* aux =t ;
    for(int i = 0; i<nbEmployee;i++){
        if(strcmp(cin,aux->getCin()) == 0){
            return aux;
        }
        aux++;
    }
    return NULL;
}

int Institution::getNbEmployee(){
    return nbEmployee;
}

//Recherche d'un employer dans un tableau avec le nom et prenom
Employee* Institution::recherche(char* n, char* p){
    Employee* aux = t;
    for(int i = 0; i<nbEmployee; i++){
        if((strcmp(aux->getNom(), n) == 0)&&(strcmp(aux->getPrenom(), p) == 0)){
            return aux;
        }
        aux++;
    }
}


//L'ajout d'un employer dans un tableau d'employer
void Institution::addEmployee(Employee e){
    assert(nbEmployee < NMAX);
    if(recherche(e.getCin()) != NULL){
        cout<<"Employer deja existe\n";
    }else{
        t[nbEmployee] = e;
        nbEmployee++;
    }

}


//La suppression d'un employer dans un tableau d'employer
void Institution::supprimerEmployee(char *c){
    Employee *aux;
    aux = recherche(c);
    if(aux == NULL){
        cout<<"Employee n'existe pas\n";
    }else{
        int x = aux - t;
        for(int i = x; i<nbEmployee; i++){
            t[x] = t[x+1];
        }
        (t+nbEmployee - 1 )->~Employee();
        nbEmployee--;
    }
}


//Affichage d'un tableau d'employer
void Institution::afficher(){
    cout<<"Les Employer Sont :\n";
    for(int i =0; i<nbEmployee; i++){
        (t+i)->afficher();
    }
}




Institution::~Institution(){}

