#include"Echipa.h"
#include<list>
#include<algorithm>
#include <fstream>
#pragma once
#include <string>



class Echipe
{
    list<Echipa*> echipe;
public:
    Echipe();
    Echipe(list<Echipa*>e);

    list<Echipa*> getList();
    void setList(list<Echipa*> l);

    void afisare();
    void afiseazaLista(ofstream& rez);
    void adaugareFront(Echipa *e);
    void adaugareBack(Echipa *e);
    void citesteList(ifstream &f);
    string puncteMin();
    void stergeEchipe();
};
