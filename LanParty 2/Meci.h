#include"Echipa.h"
#pragma once
//M-am gandit sa fac o clasa meci care are doua atribute de tip echipa ca sa fie mai usor de lucrat
//sa pot sa folosesc la ex 3 sa scot din stive direct  meciuri si sa le bag in coada
//astfel coada mea va primi direct meci
class Meci
{
    Echipa *e1;
    Echipa *e2;
public:
    Meci();
    Meci(Echipa *ec1, Echipa *ec2);
    Meci(const Meci &m);
    Meci& operator=(const Meci &m);
    ~Meci();


    Echipa* getE1();
    Echipa* getE2();

    void setE1(Echipa *e1);
    void setE2(Echipa *e2);

    Echipa *verificaCastigator();
    Echipa *verificaInvinsi();
};
