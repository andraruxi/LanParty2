#include"Echipe.h"
#include<stack>
#include <fstream>
#pragma once
#include"Echipa.h"

class Stiva
{
    stack<Echipa*> stive;
public:
    Stiva();
    Stiva(stack<Echipa*>s);

    stack<Echipa*> getS();
    void setS(stack<Echipa*>s);

    void puneSpatiiStiva(ofstream& rez, int len);
    void adaugaElement(Echipa *e);
    Echipa* stergeElement();
    void afiseazaStiva(ofstream& rez);
    void stergeStiva();
    void stergeStivaDupaTop8();
    Echipe* creeazaLista();
    int goala();




};
