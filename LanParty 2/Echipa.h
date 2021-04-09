#include<string>
#include"Jucator.h"
#include<iostream>
#pragma once
using namespace std;
class Echipa
{
    int nr_juc;
    string nume_echipa;
    Jucator *juc;//fac un vector de jucatori
    int index_ramas=0;


public:
     Echipa();
     Echipa(int nr,string n_e);
     Echipa(int nr,string n_e, const Jucator *j);
     Echipa(const Echipa &l);
     Echipa&operator=(const Echipa &l);
     ~Echipa();

    int getNr();
    string getNech();
    Jucator *getJuc();


    void setNr( int nr_juc);
    void setNech(string nume_echipa);
    void setJuc(Jucator *juc);

    void afisare()const;
    float verificaMedie();
    void addJuc(Jucator j);
    friend bool operator!=(const Echipa& e1, const Echipa &e2);


    friend ostream &operator<<(ostream &dev, const Echipa &e);
    friend istream &operator>>(istream &dov,  Echipa  &e);
    Echipa* getCopieEp();

};
