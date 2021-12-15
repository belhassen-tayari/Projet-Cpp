#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee{
    private:
        char cin[10];
        char nom[50];
        char prenom[50];
        int age;
        float salaire;
        int enConges;
        int nbrJrConge;
        int nbrJrCongeRestant;
    public:
        //Constructor and Destructor
        Employee();
        Employee(char *,char *, char *, int , float);
        ~Employee();

        //Encapsulation
        char* getCin();
        void setCin(char*);

        char* getNom();
        void setNom(char *);

        char* getPrenom();
        void setPrenom(char *);

        int getAge();
        void setAge(int);

        float getSalaire();
        void setSalaire(float);

        int estEnConge();
        void setEnConge(int);
        void setFinConge();

        int getNbrJrConge();
        void setNbrJrConge(int);

        int getNbrJrCongeRestant();
        void setNbrJrCongeRestant(int);


        //Affichage d'un Employer
        void afficher();
};

#endif // EMPLOYEE_H
