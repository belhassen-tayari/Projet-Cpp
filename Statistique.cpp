#include "Statistique.h"
#include "Institution.h"
#include<iostream>

using namespace std;

Statistique::Statistique(){

}

Statistique::~Statistique(){

}


//Affichage des employer qui ont un nombre de jour du conges expiré
void Statistique::afficheEmployeeCongeExpire(Institution in){
    cout<<"Les Employer qui ont un nombre de jour du conges expire sont :\n";
    Employee *aux = in.t;
    for(int i = 0; i<in.nbEmployee; i++){
        if(aux->getNbrJrCongeRestant() == 0){
            cout<<"\t";
            cout <<aux->getCin()<<" , "<<aux->getNom()<<" "<<aux->getPrenom()<<"\n"<<endl;
        }
        aux++;
    }
}

//Affichage des Employer qui sont deja en congés
void Statistique::afficheemployeeEnCongee(Institution in){
    cout<<"Les Employers qui sonts en Conges:\n";
    Employee *aux = in.t;
    for(int i = 0; i<in.nbEmployee; i++){
        if(aux->estEnConge()){
            cout<<"\t";
            cout <<aux->getCin()<<" , "<<aux->getNom()<<" "<<aux->getPrenom()<<"\n"<<endl;
        }
        aux++;
    }
}


