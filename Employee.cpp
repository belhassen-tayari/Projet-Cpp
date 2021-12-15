#include "Employee.h"
#include<string.h>
#include<iostream>
#include "Erreur.h"


using namespace std;


//Constructor and Destructor
Employee::Employee(){};

Employee::Employee(char *cinp , char* nomp, char *prenomp, int agep, float salairep){
    strcpy(cin,cinp);
    strcpy(nom,nomp);
    strcpy(prenom,prenomp);
    age = agep;
    salaire = salairep;
    enConges = 0;
}

Employee::~Employee(){};


//Encapsulation

/*-----------CIN-------------*/
char* Employee::getCin(){
    return cin;
}
void Employee::setCin(char* newCin){
    strcpy(cin,newCin);
}
/*-----------Nom-------------*/
char* Employee::getNom(){
    return nom;
}
void Employee::setNom(char *newName){
    strcpy(nom,newName);
}
/*-----------Prenom-------------*/
char* Employee::getPrenom(){
    return prenom;
}
void Employee::setPrenom(char *newPrenom){
    strcpy(prenom,newPrenom);
}
/*-----------Age-------------*/
int Employee::getAge(){
    return age;
}
void Employee::setAge(int newAge){
    age = newAge;
}
/*-----------Salaire-------------*/
float Employee::getSalaire(){
    return salaire;
}
void Employee::setSalaire(float newSalaire){
    salaire = newSalaire;
}

/*-----------En Congés-------------*/
int Employee::estEnConge(){
    return enConges;
}

void Employee::setEnConge(int nbr){
    if(nbrJrCongeRestant - nbr < 0){
        Erreur e("Ce Employer n'a pas le droit de prendre un conges !");
        throw e;
    }else{
        nbrJrCongeRestant-=nbr;

        enConges = 1;
    }
}

void Employee::setFinConge(){
    enConges = 0;
}


//------------------Nombre de Jour du Congés------------------
int Employee:: getNbrJrConge(){
    return nbrJrConge;
}

void Employee:: setNbrJrConge(int nb){
    nbrJrConge = nb;
}
//-----------------Nombre de jour du Congés Restant------------------------
int Employee::getNbrJrCongeRestant(){
    return nbrJrCongeRestant;
}

void Employee::setNbrJrCongeRestant(int nb){
    nbrJrCongeRestant = nb;
}


//Affichage d'un employer
void Employee::afficher(){
    cout<<"\t"<<cin<<" , "<<nom<<" "<<prenom<<" , "<<age<<" Ans , "<<salaire<<" TND\n"<<endl;
}



