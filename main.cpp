#include <iostream>
#include "Employee.h"
#include "Institution.h"
#include "Administrateur.h"
#include "Ouvrier.h"
#include "Responsable.h"
#include "Technicien.h"
#include "ALabo.h"
#include "Fichier.h"
#include "Statistique.h"
#include "Erreur.h"

//declaration des valeur du congés des employer
#define NBR_OUVRIER 28
#define NBR_TECHNICIEN 35
#define NBR_RESPONSABLE 39
#define NBR_ALABO 43
#define NBR_ADMINISTRATEUR 90

#include<myconio.h>
#include<windows.h>
#include <windowsx.h>


#define BUTTON_CLICKED 150
#define BUTTON_CHARGER_CLICKED 180
#define BUTTON_OPEN 2540
#define BUTTON_ADD_EMPLOYEE 240
#define BUTTON_LOAD_DATA 390
#define BUTTON_SET_DATA_IN_FILE 615
#define BUTTON_AJOUTER 1222
#define BUTTON_SUPPRIMER_EMPLOYER 142
#define BUTTON_SUPP 47
#define BUTTON_AFFICHAGE_EMPLOYER 98
#define BUTTON_RECHERCHE_EMP 114
#define BUTTON_RECH_EMPLOYER 36
#define BUTTON_SET_EN_CONGES 15451
#define BUTTON_SET 1420
#define BUTTON_EMP_EN_CONGE 7843
#define BUTTON_EMP_CONGE_EXP 8569



using namespace std;

LRESULT CALLBACK WindowProcedure(HWND,UINT, WPARAM,LPARAM);
LRESULT CALLBACK windowprocessforwindow2(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK rechercheWindow(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK affichageWindow(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK rechercheEmp(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK afficheEmp(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK setEnCongeWindow(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK empEnCongWindow(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK empCongeExpireWindow(HWND,UINT,WPARAM,LPARAM);



void AddMenus(HWND);
void AddControls(HWND);
void createButtons(HWND);
void createWindow2(WNDCLASSW, HINSTANCE, int);
void createAddForm(HWND);
void createMainWindow();
void createRechercheWindow();
void addRechercheForm(HWND);
void createAfficheWindow(HWND);
void createAffDesign(HWND);
void createRechercheEmp(HWND);
void addRechercheEmpForm(HWND);
void createAfficheEmp(HWND);
void addAffEmpForm(HWND ,Employee *);
void createSetEnCongesWindow(HWND);
void addSetEnCongeForm(HWND);
void createEmpEnCongWindow(HWND);
void addEmpEnConForm(HWND);
void createEmpCongeExpWindow(HWND);
void addEmpCongeExpireForm(HWND);


HMENU hMenu;
Institution *i = new Institution();
Fichier f("db.csv");
HWND hWnd,buttonAddEmployee ,buttonAfficherEmployee , buttonSupprimerEmployer ,buttonRechercheEmployee, buttonLoadData,buttonEmployerEnConges;
HWND buttonSetDataInFile, buttonMettreEnConges, buttonEmployerCongeeExpire,button,handleForWindow2,hEdit, buttonSubmit,hEditRech,hEditEnCon, hEditNbrJr;
HWND hEditNom, hEditPrenom, hEditAge, hEditCin ,hEditSalary,hWndComboBox,rechercheHandeler ,hEditRechEmp;
HINSTANCE mainHInst;
int mainNCmdShow;
WNDCLASSW wCw,wRw,wAw,wRCHw,wERw,wSECw,wEECw,wCEXw;
HINSTANCE SecondhIns;
int secondnCmdShow;
HBITMAP hBmp;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){


    WNDCLASSW wc;

    wc.hInstance = hInst;
    wc.lpszClassName = L"My Window Class";
    wc.lpfnWndProc = WindowProcedure;
    wc.style = CS_DBLCLKS;

    wc.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.lpszMenuName = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    mainNCmdShow = ncmdshow;
    mainHInst = hInst;

    if(!RegisterClassW(&wc)){
        return -1;
    }

    createMainWindow();
    MSG msg = {0};

    while(GetMessage(&msg, NULL,NULL,NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    //MessageBox(NULL,"Hello World !","First GUI",MB_OK);
    return 0;
}

void createAfficheWindow(HWND handleAffWind){
    wAw.hInstance = mainHInst;
    wAw.lpszClassName = L"Affichage Window";
    wAw.lpfnWndProc = (WNDPROC)affichageWindow;
    wAw.style = CS_DBLCLKS;

    wAw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wAw.hCursor = LoadCursor(NULL, IDC_ARROW);
    wAw.lpszMenuName = NULL;
    wAw.cbClsExtra = 0;
    wAw.cbWndExtra = 0;
    wAw.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    SecondhIns = mainHInst;
    if(!RegisterClassW(&wAw)){
        return ;
    }

    HWND hand = CreateWindowW(
                        L"Affichage Window",
                        L"Affichage",
                        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        530,
                        600,
                        handleAffWind,
                        NULL,
                        mainHInst,
                        NULL
                    );

    ShowWindow(hand, SW_SHOW);
}

void createEmpCongeExpWindow(HWND hWnd){
    wCEXw.hInstance = mainHInst;
    wCEXw.lpszClassName = L"Cong Exp";
    wCEXw.lpfnWndProc = (WNDPROC)empCongeExpireWindow;
    wCEXw.style = CS_DBLCLKS;

    wCEXw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wCEXw.hCursor = LoadCursor(NULL, IDC_ARROW);
    wCEXw.lpszMenuName = NULL;
    wCEXw.cbClsExtra = 0;
    wCEXw.cbWndExtra = 0;
    wCEXw.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    if(!RegisterClassW(&wCEXw)){
        return ;
    }

    rechercheHandeler = CreateWindowW(
                        L"Cong Exp",
                        L"Main Window",
                        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        400,
                        600,
                        hWnd,
                        NULL,
                        mainHInst,
                        NULL
                    );

    ShowWindow(rechercheHandeler, SW_SHOW);
}



void createAfficheEmp(HWND hWnd){
    wERw.hInstance = mainHInst;
    wERw.lpszClassName = L"Aff Emp";
    wERw.lpfnWndProc = (WNDPROC)afficheEmp;
    wERw.style = CS_DBLCLKS;

    wERw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wERw.hCursor = LoadCursor(NULL, IDC_ARROW);
    wERw.lpszMenuName = NULL;
    wERw.cbClsExtra = 0;
    wERw.cbWndExtra = 0;
    wERw.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    SecondhIns = mainHInst;
    if(!RegisterClassW(&wERw)){
        return ;
    }

    HWND handleW2 = CreateWindowW(
                        L"Aff Emp",
                        L"Main Window",
                        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        500,
                        200,
                        HWND_DESKTOP,
                        NULL,
                        mainHInst,
                        NULL
                    );

    ShowWindow(handleForWindow2, SW_SHOW);
}


void createWindow2(){
    wCw.hInstance = mainHInst;
    wCw.lpszClassName = L"Second Window";
    wCw.lpfnWndProc = (WNDPROC)windowprocessforwindow2;
    wCw.style = CS_DBLCLKS;

    wCw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wCw.hCursor = LoadCursor(NULL, IDC_ARROW);
    wCw.lpszMenuName = NULL;
    wCw.cbClsExtra = 0;
    wCw.cbWndExtra = 0;
    wCw.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    SecondhIns = mainHInst;
    if(!RegisterClassW(&wCw)){
        return ;
    }

    HWND handleW2 = CreateWindowW(
                        L"Second Window",
                        L"Main Window",
                        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        600,
                        700,
                        HWND_DESKTOP,
                        NULL,
                        mainHInst,
                        NULL
                    );
    handleForWindow2 = handleW2;

    ShowWindow(handleForWindow2, SW_SHOW);
}

void createRechercheEmp(HWND hand){
    wRCHw.hInstance = mainHInst;
    wRCHw.lpszClassName = L"Rech Emp";
    wRCHw.lpfnWndProc = (WNDPROC)rechercheEmp;
    wRCHw.style = CS_DBLCLKS;

    wRCHw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wRCHw.hCursor = LoadCursor(NULL, IDC_ARROW);
    wRCHw.lpszMenuName = NULL;
    wRCHw.cbClsExtra = 0;
    wRCHw.cbWndExtra = 0;
    wRCHw.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    SecondhIns = mainHInst;
    if(!RegisterClassW(&wRCHw)){
        return ;
    }

    HWND handleW2 = CreateWindowW(
                        L"Rech Emp",
                        L"Main Window",
                        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        600,
                        300,
                        HWND_DESKTOP,
                        NULL,
                        mainHInst,
                        NULL
                    );

    ShowWindow(handleForWindow2, SW_SHOW);
}

void createSetEnCongesWindow(HWND hand){
    wSECw.hInstance = mainHInst;
    wSECw.lpszClassName = L"Set En Conge";
    wSECw.lpfnWndProc = (WNDPROC)setEnCongeWindow;
    wSECw.style = CS_DBLCLKS;

    wSECw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wSECw.hCursor = LoadCursor(NULL, IDC_ARROW);
    wSECw.lpszMenuName = NULL;
    wSECw.cbClsExtra = 0;
    wSECw.cbWndExtra = 0;
    wSECw.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    SecondhIns = mainHInst;
    if(!RegisterClassW(&wSECw)){
        return ;
    }

    HWND handleW2 = CreateWindowW(
                        L"Set En Conge",
                        L"Main Window",
                        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        600,
                        300,
                        HWND_DESKTOP,
                        NULL,
                        mainHInst,
                        NULL
                    );

    ShowWindow(handleW2, SW_SHOW);
}

void createEmpEnCongWindow(HWND hWnd){
    wEECw.hInstance = mainHInst;
    wEECw.lpszClassName = L"EMP EN CON";
    wEECw.lpfnWndProc = (WNDPROC)empEnCongWindow;
    wEECw.style = CS_DBLCLKS;

    wEECw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wEECw.hCursor = LoadCursor(NULL, IDC_ARROW);
    wEECw.lpszMenuName = NULL;
    wEECw.cbClsExtra = 0;
    wEECw.cbWndExtra = 0;
    wEECw.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    if(!RegisterClassW(&wEECw)){
        return ;
    }

    rechercheHandeler = CreateWindowW(
                        L"EMP EN CON",
                        L"Main Window",
                        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        400,
                        600,
                        hWnd,
                        NULL,
                        mainHInst,
                        NULL
                    );

    ShowWindow(rechercheHandeler, SW_SHOW);
}

void createRechercheWindow(){
    wRw.hInstance = mainHInst;
    wRw.lpszClassName = L"Recherche";
    wRw.lpfnWndProc = (WNDPROC)rechercheWindow;
    wRw.style = CS_DBLCLKS;

    wRw.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wRw.hCursor = LoadCursor(NULL, IDC_ARROW);
    wRw.lpszMenuName = NULL;
    wRw.cbClsExtra = 0;
    wRw.cbWndExtra = 0;
    wRw.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    if(!RegisterClassW(&wRw)){
        return ;
    }

    rechercheHandeler = CreateWindowW(
                        L"Recherche",
                        L"Main Window",
                        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        600,
                        300,
                        hWnd,
                        NULL,
                        mainHInst,
                        NULL
                    );

    ShowWindow(rechercheHandeler, SW_SHOW);
    EnableWindow(hWnd, false);
}


LRESULT CALLBACK empEnCongWindow(HWND hWnd1,UINT msg,WPARAM wp,LPARAM lp){
    switch(msg){
        case WM_CREATE:
            EnableWindow(hWnd, false);
            addEmpEnConForm(hWnd1);
            break;
        case WM_COMMAND:

            switch (wp){


            }

            break;
        case WM_DESTROY:
            EnableWindow(hWnd, true);
            break;
        default:
            return DefWindowProcW(hWnd1, msg ,wp, lp);

    }
}

LRESULT CALLBACK empCongeExpireWindow(HWND hWnd1,UINT msg,WPARAM wp,LPARAM lp){
    switch(msg){
        case WM_CREATE:
            EnableWindow(hWnd, false);
            addEmpCongeExpireForm(hWnd1);
            break;
        case WM_COMMAND:

            switch (wp){


            }

            break;
        case WM_DESTROY:
            EnableWindow(hWnd, true);
            break;
        default:
            return DefWindowProcW(hWnd1, msg ,wp, lp);

    }
}


LRESULT CALLBACK rechercheEmp(HWND hWnd1, UINT msg, WPARAM wp, LPARAM lp){
    switch(msg){
        case WM_CREATE:
            EnableWindow(hWnd, false);
            addRechercheEmpForm(hWnd1);
            break;
        case WM_COMMAND:

            switch (wp){
                case BUTTON_RECH_EMPLOYER:
                    createAfficheEmp(hWnd1);
                    break;

            }

            break;
        case WM_DESTROY:
            EnableWindow(hWnd, true);
            break;
        default:
            return DefWindowProcW(hWnd1, msg ,wp, lp);

    }
}


LRESULT CALLBACK afficheEmp(HWND hWnd1, UINT msg, WPARAM wp, LPARAM lp){
    switch(msg){
        case WM_CREATE:
            EnableWindow(hWnd, false);
            if(i->getNbEmployee() == 0){
                MessageBox(NULL,"Il faut charger ou saisir des donnees","ERROR",MB_OK);
            }else{
                char c[9];
                GetWindowText(hEditRechEmp, c,9);
                if(i->recherche(c) != NULL)
                    addAffEmpForm(hWnd1 , i->recherche(c));
                else{
                    MessageBox(NULL,"Employer n'existe pas !","ERROR",MB_OK);
                }
            }
            break;
        case WM_DESTROY:
            EnableWindow(hWnd, true);
            break;
        default:
            return DefWindowProcW(hWnd1, msg ,wp, lp);
}
}



LRESULT CALLBACK rechercheWindow(HWND handeler, UINT msg, WPARAM wp, LPARAM lp){
    switch(msg){
        case WM_CREATE:
            EnableWindow(hWnd, false);
            addRechercheForm(handeler);
            break;
        case WM_COMMAND:

            switch (wp){
                case BUTTON_SUPP:
                    char c[9];
                    GetWindowText(hEditRech,c,9 );
                    if(strlen(c) == 0){
                        MessageBox(NULL,"SVP saisir un cin :","ERROR",MB_OK);
                    }else if(i->recherche(c) == NULL){
                            MessageBox(NULL,"Employer n'existe pas !","ERROR",MB_OK);
                        }else{
                            i->supprimerEmployee(c);
                            MessageBox(NULL,"Employer est Supprimer avec Succees","SUCCESS",MB_OK);
                        }

                    break;
            }

            break;
        case WM_DESTROY:
            EnableWindow(hWnd, true);
            break;
        default:
            return DefWindowProcW(handeler, msg ,wp, lp);

    }
}


LRESULT CALLBACK setEnCongeWindow(HWND hWnd1,UINT msg,WPARAM wp,LPARAM lp){
    switch(msg){
        case WM_COMMAND:
            switch(wp){
                case BUTTON_SET:
                    char cin[10], nb[10];
                    GetWindowText(hEditNbrJr,nb,10);
                    GetWindowText(hEditEnCon,cin, 10);
                    if(!((strlen(cin) == 0)||(strlen(nb) == 0))){
                        if(i->recherche(cin) != NULL){
                            try{
                            i->recherche(cin)->setEnConge(atoi(nb));
                            MessageBox(NULL,"Operation Effectue Avec Succees","SUCCESS",MB_OK);
                            DestroyWindow(hWnd1);
                        }catch(Erreur e){
                            MessageBox(NULL,e.getMessage(),"ERROR",MB_OK);
                        };
                        }else{
                            MessageBox(NULL,"Employer n'existe Pas","ERROR",MB_OK);
                        }
                    }else{
                        MessageBox(NULL,"Les Deux Champs sont Obligatoires","ERROR",MB_OK);
                    }

                    break;
            }
            break;
        case WM_CREATE:
            EnableWindow(hWnd, false);
            addSetEnCongeForm(hWnd1);
            break;
        case WM_DESTROY:
            EnableWindow(hWnd, true);
            break;
        default:
            return DefWindowProcW(hWnd1, msg ,wp, lp);
}
}
LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg, WPARAM wp,LPARAM lp){
    switch(msg){
        static HINSTANCE hInstance;
        case WM_COMMAND :


            switch(wp){
                case 0:
                    MessageBox(NULL,"Voulez Vous quitter!","Goodbye",MB_OKCANCEL);
                    DestroyWindow(hWnd);
                    break;
                case 1:
                    MessageBeep(MB_OK);
                    MessageBox(NULL,"Developpé par Belhassen Tayari CPI 2 avec C++","Developpé Par ",MB_OK);
                    break;
                case BUTTON_ADD_EMPLOYEE:
                    if(f.isFileExist() && i->getNbEmployee() == 0){
                        MessageBox(NULL,"Le Fichier deja existe, il faut charger des donnees","ERROR",MB_OK);
                    }else{
                        createWindow2();
                    }
                    break;

                case BUTTON_LOAD_DATA:
                    try{
                        if(i->getNbEmployee() == 0){
                            cout<<i->getNbEmployee();
                            i = f.getDataFromFile();
                            cout<<i->getNbEmployee();
                            MessageBox(NULL,"Les Donnees sont chargé Avec Succees","SUCCESS",MB_OK);
                        }else{
                            MessageBox(NULL,"Les Donnees seront chargé une Seule fois","ERROR",MB_OK);
                        }
                        cout<<"Hello "<<i->getNbEmployee()<<"\n";
                    }catch(Erreur e){
                        MessageBox(NULL,e.getMessage(),"ERROR",MB_OK);
                    }
                    break;
                case BUTTON_SUPPRIMER_EMPLOYER:
                    if(i->getNbEmployee() == 0){
                        MessageBox(NULL,"il faut charger ou saisir des donnees","ERROR",MB_OK);
                    }else{
                        createRechercheWindow();
                    }
                    break;
                case BUTTON_AFFICHAGE_EMPLOYER:
                    if(i->getNbEmployee() == 0){
                        MessageBox(NULL,"il faut charger ou saisir des donnees","ERROR",MB_OK);
                    }else{
                        createAfficheWindow(hWnd);
                    }
                    break;
                case BUTTON_RECHERCHE_EMP:
                    if(i->getNbEmployee() == 0){
                        MessageBox(NULL,"il faut charger ou saisir des donnees","ERROR",MB_OK);
                    }else{
                        createRechercheEmp(hWnd);
                    }
                    break;
                case BUTTON_SET_EN_CONGES:
                    if(i->getNbEmployee() == 0){
                        MessageBox(NULL,"il faut charger ou saisir des donnees","ERROR",MB_OK);
                    }else{
                        createSetEnCongesWindow(hWnd);
                    }
                    break;
                case BUTTON_EMP_EN_CONGE:
                    if(i->getNbEmployee() == 0){
                        MessageBox(NULL,"il faut charger ou saisir des donnees","ERROR",MB_OK);
                    }else{
                        createEmpEnCongWindow(hWnd);
                    }
                    break;
                case BUTTON_EMP_CONGE_EXP:
                    if(i->getNbEmployee() == 0){
                        MessageBox(NULL,"il faut charger ou saisir des donnees","ERROR",MB_OK);
                    }else{
                        createEmpCongeExpWindow(hWnd);
                    }
                    break;
                case BUTTON_SET_DATA_IN_FILE:
                    if(i->getNbEmployee() == 0){
                        MessageBox(NULL,"il faut charger ou saisir des donnees","ERROR",MB_OK);
                    }else{
                        f.setDataInFile(i);
                        MessageBox(NULL,"Les Donnees sont Stocké Dans le fichier avec Succees","SUCCESS",MB_OK);

                    }
                    break;
            }
            break;
        case WM_PAINT :
            {



         PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            DrawState(hdc,NULL,NULL,(LPARAM)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hWnd, &ps);}
        break;
        case WM_CREATE:
             hBmp=(HBITMAP)LoadImage(NULL,"image.bmp",IMAGE_BITMAP,1500,750,LR_LOADFROMFILE);

            AddMenus(hWnd);
            AddControls(hWnd);
            break;
        case WM_DESTROY:
            //PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd, msg ,wp, lp);
    }
}

LRESULT CALLBACK affichageWindow(HWND handleAffWind, UINT msg, WPARAM wp, LPARAM lp){
    switch(msg){
    case WM_COMMAND:
            break;
        case WM_CREATE:
            EnableWindow(hWnd, false);
            createAffDesign(handleAffWind);
            break;
        case WM_DESTROY:
            EnableWindow(hWnd, true);
            DestroyWindow(handleAffWind);
            break;
        default:
            return DefWindowProcW(handleAffWind, msg ,wp, lp);
    }
}


LRESULT CALLBACK windowprocessforwindow2(HWND handleforwindow2, UINT message, WPARAM wParam, LPARAM lParam){
    switch (message)
    {
    case WM_COMMAND:
    {
        switch (wParam) {
            case BUTTON_AJOUTER:
                char c[9], nom[20] ,prenom[20], age[3], salaire[10],grade[20];
                GetWindowText(hEditCin, c,9);
                GetWindowText(hEditNom, nom,9);
                GetWindowText(hEditPrenom, prenom,9);
                GetWindowText(hEditAge, age,9);
                GetWindowText(hEditSalary, salaire,9);
                GetWindowText(hWndComboBox,grade,30);
                if((strlen(c) == 0)||(strlen(nom) == 0)||(strlen(prenom) == 0)||(strlen(age) == 0)||(strlen(grade) == 0)||(strlen(salaire) == 0)){
                    MessageBox(NULL,"Tous les champs sont obligatoires","ERROR",MB_OK);
                }else if(i->recherche(c) == NULL){
                    if(strcmp(grade,"Ouvrier") == 0){
                        Ouvrier o(c,nom,prenom,atoi(age), atof(salaire),NBR_OUVRIER);
                        i->addEmployee(o);
                    }else if(strcmp(grade,"Technicien") == 0){
                            Technicien t(c, nom, prenom, atoi(age), atof(salaire),NBR_TECHNICIEN);
                            i->addEmployee(t);
                          }else if(strcmp(grade,"Agent Labo") == 0){
                            ALabo al(c, nom, prenom, atoi(age), atof(salaire), NBR_ALABO);
                            i->addEmployee(al);
                          }else if(strcmp(grade,"Responsable") == 0){
                            Responsable r(c, nom, prenom, atoi(age), atof(salaire), NBR_RESPONSABLE);
                            i->addEmployee(r);
                          }else if(strcmp(grade,"Administrateur") == 0){
                            Administrateur a(c, nom, prenom, atoi(age), atof(salaire),NBR_ADMINISTRATEUR);
                            i->addEmployee(a);
                          }
                          MessageBox(NULL,"Employer ajoute Avec Succees","SUCCESS",MB_OK);
                          DestroyWindow(handleforwindow2);

                }else{
                    MessageBox(NULL,"Employer Existe deja","ERROR",MB_OK);
                }
                break;
        }
    }
    return 0;
    case WM_CREATE: {
        EnableWindow(hWnd, false);
        createAddForm(handleforwindow2);
        break;
    }
    case WM_DESTROY:
        //PostQuitMessage(0);
        EnableWindow(hWnd, true);
        DestroyWindow(handleforwindow2);
        break;
    default:

        return DefWindowProc(handleforwindow2, message, wParam, lParam);
    }
    return 0;
}



void AddMenus(HWND hWnd){
    hMenu = CreateMenu();
    HMENU hFichierMenu = CreateMenu();


    AppendMenu(hMenu,MF_STRING,1,"About");

    SetMenu(hWnd, hMenu);


    AppendMenu(hMenu,MF_STRING,0,"Exit");
}


void createButtons(HWND hWnd){

    /*Creation et chargement depuis le fichier*/
    buttonLoadData = CreateWindow(
                              "BUTTON",
                               "Charger Les Donnees Depuis Le fichier",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               10,70,450,100,
                               hWnd,(HMENU)BUTTON_LOAD_DATA, NULL,NULL
                        );


    buttonSetDataInFile = CreateWindow(
                              "BUTTON",
                               "Sauvegarder les donnees dans le fichier",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               10,190,450,100,
                               hWnd,(HMENU) BUTTON_SET_DATA_IN_FILE, NULL, NULL
                        );

    /*Mise a jour et Modification*/

    buttonAddEmployee = CreateWindow(
                              "BUTTON",
                               "Ajouter Un Employer",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               480,70,450,100,
                               hWnd,(HMENU) BUTTON_ADD_EMPLOYEE, NULL, NULL
                        );

    buttonSupprimerEmployer = CreateWindow(
                              "BUTTON",
                               "Supprimer Un Employer",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               480,190,450,100,
                               hWnd,(HMENU) BUTTON_SUPPRIMER_EMPLOYER, NULL, NULL
    );


    buttonMettreEnConges = CreateWindow(
                              "BUTTON",
                               "Mettre un Employer En Conges",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               480,310,450,100,
                               hWnd,(HMENU) BUTTON_SET_EN_CONGES, NULL, NULL
    );

    /*Recherche et Statistique*/
    buttonAfficherEmployee = CreateWindow(
                              "BUTTON",
                               "Afficher Les Employer",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               950,70,450,100,
                               hWnd,(HMENU) BUTTON_AFFICHAGE_EMPLOYER, NULL, NULL
    );

    buttonRechercheEmployee = CreateWindow(
                              "BUTTON",
                               "Rechercher Un Employer",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               950,190,450,100,
                               hWnd,(HMENU) BUTTON_RECHERCHE_EMP, NULL, NULL
    );

    buttonEmployerEnConges = CreateWindow(
                              "BUTTON",
                               "Les Employer qui sont deja en Congee",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               950,310,450,100,
                               hWnd,(HMENU) BUTTON_EMP_EN_CONGE, NULL, NULL
    );

    buttonEmployerCongeeExpire = CreateWindow(
                              "BUTTON",
                               "Les Employer qui ont un nombre de conges expire",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               950,430,450,100,
                               hWnd,(HMENU) BUTTON_EMP_CONGE_EXP, NULL, NULL
    );


}

void AddControls(HWND hWnd){
    CreateWindowW(L"static", L"Bienvenu Dans Notre Systeme de Gestion des Conges", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,465,10,500,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"static", L"Creation et Chargement", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,40,450,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"static", L"Mise a jour et Modification", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,480,40,450,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"static", L"Recherche et Statistique", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,950,40,450,20,hWnd,NULL,NULL,NULL);

}


void createAddForm(HWND handle){

    CreateWindowW(L"static", L"Remplir Les Donnees ci_desous", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,150,10,300,25,handle,NULL,NULL,NULL);

    CreateWindowW(L"static", L"Cin :", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,50,100,25,handle,NULL,NULL,NULL);
    hEditCin = CreateWindowW(L"Edit", L"", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,120,50,450,25,handle,NULL,NULL,NULL);

    CreateWindowW(L"static", L"Nom :", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,85,100,25,handle,NULL,NULL,NULL);
    hEditNom = CreateWindowW(L"Edit", L"", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,120,85,450,25,handle,NULL,NULL,NULL);

    CreateWindowW(L"static", L"Prenom :", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,120,100,25,handle,NULL,NULL,NULL);
    hEditPrenom = CreateWindowW(L"Edit", L"", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,120,120,450,25,handle,NULL,NULL,NULL);

    CreateWindowW(L"static", L"Age :", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,155,100,25,handle,NULL,NULL,NULL);
    hEditAge = CreateWindowW(L"Edit", L"", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,120,155,450,25,handle,NULL,NULL,NULL);

    CreateWindowW(L"static", L"Salaire :", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,190,100,25,handle,NULL,NULL,NULL);
    hEditSalary = CreateWindowW(L"Edit", L"", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,120,190,450,25,handle,NULL,NULL,NULL);

    CreateWindowW(L"static", L"Grade :", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,220,100,25,handle,NULL,NULL,NULL);
    hWndComboBox = CreateWindowW(L"Combobox", NULL,CBS_DROPDOWN|CBS_HASSTRINGS|WS_VISIBLE | WS_CHILD | WS_BORDER,300,220,260,400,handle,NULL,NULL,NULL);
    SendMessage (
        hWndComboBox,
        (UINT) CB_ADDSTRING,
        (WPARAM) 0, (LPARAM) TEXT ("Administrateur"));

    SendMessage (
        hWndComboBox,
        (UINT) CB_ADDSTRING,
        (WPARAM) 1, (LPARAM) TEXT ("Responsable"));
    SendMessage (
        hWndComboBox,
        (UINT) CB_ADDSTRING,
        (WPARAM) 2, (LPARAM) TEXT ("Agent Labo"));

    SendMessage (
        hWndComboBox,
        (UINT) CB_ADDSTRING,
        (WPARAM) 3, (LPARAM) TEXT ("Technicien"));
    SendMessage (
        hWndComboBox,
        (UINT) CB_ADDSTRING,
        (WPARAM) 4, (LPARAM) TEXT ("Ouvrier"));


    CreateWindowW(L"static", L"Tous Les Champs Sonts Obligatoires *", WS_VISIBLE|WS_CHILD|SS_CENTER,10,280,300,20,handle,NULL,NULL,NULL);
    buttonSubmit = CreateWindow(
                              "BUTTON",
                               "AJOUTER",
                               WS_VISIBLE|WS_CHILD|WS_BORDER,
                               225,350,150,50,
                               handle,(HMENU) BUTTON_AJOUTER, NULL, NULL
    );

}


void createMainWindow(){
    hWnd = CreateWindowW(
        L"My Window Class",
        L"Main Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        1430,
        700,
        HWND_DESKTOP,
        NULL,
        mainHInst,
        NULL
    );
    ShowWindow(hWnd,mainNCmdShow);
    createButtons(hWnd);
}

void addRechercheForm(HWND handeler){
    CreateWindowW(L"static", L"Saisir Le Cin de l'employer a supprimer:", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,40,50,300,20,handeler,NULL,NULL,NULL);
    hEditRech = CreateWindowW(L"Edit", L"", WS_VISIBLE|WS_CHILD|WS_BORDER,350,50,70,20,handeler,NULL,NULL,NULL);
    CreateWindow("BUTTON",
                 "SUPPRIMER",
                 WS_VISIBLE|WS_CHILD|WS_BORDER,
                 335,80,100,30,
                 handeler,(HMENU) BUTTON_SUPP, NULL, NULL
    );

}


void createAffDesign(HWND handle){
    CreateWindowW(L"static", L"Les Employer De Cette Institution Sont :", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,110,50,300,20,handle,NULL,NULL,NULL);
    int j;
    int s = 130;
    char grade[50];


        CreateWindowW(L"static", L"CIN", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,80,100,20,handle,NULL,NULL,NULL);
        CreateWindowW(L"static", L"Prenom", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,140,80,100,20,handle,NULL,NULL,NULL);
        CreateWindowW(L"static", L"Nom", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,270,80,100,20,handle,NULL,NULL,NULL);
        CreateWindowW(L"static", L"Grade", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,400,80,100,20,handle,NULL,NULL,NULL);


        for(j = 0; j<i->getNbEmployee() ; j++){
            switch(i->getTMember(j)->getNbrJrConge()){
                case NBR_ADMINISTRATEUR:
                    strcpy(grade, "Administrateur");
                    break;
                case NBR_ALABO:
                    strcpy(grade, "Agen Labo");
                    break;
                case NBR_OUVRIER:
                    strcpy(grade, "Ouvrier");
                    break;
                case NBR_RESPONSABLE:
                    strcpy(grade, "Responsable");
                    break;
                case NBR_TECHNICIEN:
                    strcpy(grade, "Technicicen");
                    break;
            }
            CreateWindow("static", (i->getTMember(j)->getCin()), WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,s,100,20,handle,NULL,NULL,NULL);
            CreateWindow("static", (i->getTMember(j)->getNom()), WS_VISIBLE|WS_CHILD|SS_CENTER,140,s,100,20,handle,NULL,NULL,NULL);
            CreateWindow("static", (i->getTMember(j)->getPrenom()), WS_VISIBLE|WS_CHILD|SS_CENTER,270,s,100,20,handle,NULL,NULL,NULL);
            CreateWindow("static", grade, WS_VISIBLE|WS_CHILD|SS_CENTER,400,s,100,20,handle,NULL,NULL,NULL);
            s+= 30;
        }
}


void addRechercheEmpForm(HWND hWnd){
    CreateWindowW(L"static", L"Saisir Le Cin de l'employer:", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,40,50,300,20,hWnd,NULL,NULL,NULL);
    hEditRechEmp = CreateWindowW(L"Edit", L"", WS_VISIBLE|WS_CHILD|WS_BORDER,350,50,70,20,hWnd,NULL,NULL,NULL);
    CreateWindow("BUTTON",
                 "RECHERCHER",
                 WS_VISIBLE|WS_CHILD|WS_BORDER,
                 335,80,150,30,
                 hWnd,(HMENU) BUTTON_RECH_EMPLOYER, NULL, NULL
    );
}


void addAffEmpForm(HWND hWnd , Employee * e){
    CreateWindowW(L"static", L"CIN", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,40,100,20,hWnd,NULL,NULL,NULL);
        CreateWindowW(L"static", L"Prenom", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,140,40,100,20,hWnd,NULL,NULL,NULL);
        CreateWindowW(L"static", L"Nom", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,270,40,100,20,hWnd,NULL,NULL,NULL);

        CreateWindow("static", (e->getCin()), WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,70,100,20,hWnd,NULL,NULL,NULL);
            CreateWindow("static", (e->getNom()), WS_VISIBLE|WS_CHILD|SS_CENTER,140,70,100,20,hWnd,NULL,NULL,NULL);
            CreateWindow("static", (e->getPrenom()), WS_VISIBLE|WS_CHILD|SS_CENTER,270,70,100,20,hWnd,NULL,NULL,NULL);
}


void addSetEnCongeForm(HWND hWnd){
    CreateWindowW(L"static", L"Saisir Le Cin de l'employer:", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,40,50,300,20,hWnd,NULL,NULL,NULL);
    hEditEnCon = CreateWindowW(L"Edit", L"", WS_VISIBLE|WS_CHILD|WS_BORDER,350,50,70,20,hWnd,NULL,NULL,NULL);

    CreateWindowW(L"static", L"Saisir Le Nombre de Jour:", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,40,80,300,20,hWnd,NULL,NULL,NULL);
    hEditNbrJr = CreateWindowW(L"Edit", L"", WS_VISIBLE|WS_CHILD|WS_BORDER,350,80,70,20,hWnd,NULL,NULL,NULL);

    CreateWindow("BUTTON",
                 "SET",
                 WS_VISIBLE|WS_CHILD|WS_BORDER,
                 335,120,150,30,
                 hWnd,(HMENU) BUTTON_SET, NULL, NULL
    );
}

void addEmpEnConForm(HWND hWnd){

    int j;
    int s = 130;

    CreateWindowW(L"static", L"Les Employer En Conges Sont:", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,40,50,300,20,hWnd,NULL,NULL,NULL);

        CreateWindowW(L"static", L"CIN", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,80,100,20,hWnd,NULL,NULL,NULL);
        CreateWindowW(L"static", L"Prenom", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,140,80,100,20,hWnd,NULL,NULL,NULL);
        CreateWindowW(L"static", L"Nom", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,270,80,100,20,hWnd,NULL,NULL,NULL);


        for(j = 0; j<i->getNbEmployee() ; j++){
            if(i->getTMember(j)->estEnConge()){
                CreateWindow("static", (i->getTMember(j)->getCin()), WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,s,100,20,hWnd,NULL,NULL,NULL);
                CreateWindow("static", (i->getTMember(j)->getNom()), WS_VISIBLE|WS_CHILD|SS_CENTER,140,s,100,20,hWnd,NULL,NULL,NULL);
                CreateWindow("static", (i->getTMember(j)->getPrenom()), WS_VISIBLE|WS_CHILD|SS_CENTER,270,s,100,20,hWnd,NULL,NULL,NULL);
                s+= 30;
            }
        }
}



void addEmpCongeExpireForm(HWND hWnd){
    int j;
    int s = 130;

    CreateWindowW(L"static", L"Les Employer En Conges Sont:", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,40,50,300,20,hWnd,NULL,NULL,NULL);

        CreateWindowW(L"static", L"CIN", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,80,100,20,hWnd,NULL,NULL,NULL);
        CreateWindowW(L"static", L"Prenom", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,140,80,100,20,hWnd,NULL,NULL,NULL);
        CreateWindowW(L"static", L"Nom", WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,270,80,100,20,hWnd,NULL,NULL,NULL);


        for(j = 0; j<i->getNbEmployee() ; j++){
            if(i->getTMember(j)->getNbrJrCongeRestant() == 0){
                CreateWindow("static", (i->getTMember(j)->getCin()), WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,10,s,100,20,hWnd,NULL,NULL,NULL);
                CreateWindow("static", (i->getTMember(j)->getNom()), WS_VISIBLE|WS_CHILD|SS_CENTER,140,s,100,20,hWnd,NULL,NULL,NULL);
                CreateWindow("static", (i->getTMember(j)->getPrenom()), WS_VISIBLE|WS_CHILD|SS_CENTER,270,s,100,20,hWnd,NULL,NULL,NULL);
                s+= 30;
            }
        }
}
