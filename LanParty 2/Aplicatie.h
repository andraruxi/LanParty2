#include <iostream>
#include <fstream>
#include"Jucator.h"
#include"Echipe.h"
#include"Meciuri.h"
#include"Stiva.h"
#pragma once

class Aplicatie
{
    ifstream cerinte;
    ifstream date;
    ofstream rezultate;

    Echipe *e;
    Meciuri *m;
    Stiva *s;
    Echipe*listaTop8;
   /* Liste *lista;
    Liste *listaTop8;
    Coada *coada;*/
    Stiva *castigatori;
    Stiva *invinsi;
    /*BTS* bts;
    AVL* avl;
    Liste *BOMBA;*/

public:
    Aplicatie();
    Aplicatie(char* fisier1, char* fisier2, char* fisier3);
    ~Aplicatie();

    void completeazaStivele();
    void creareMeciStiva();
    //void stergeCoada(Coada *c);*/

    void run();
    void cerinta1();
    void cerinta2();
    void cerinta3();
    void cerinta4();
    void cerinta5();
};
