#include<iostream>
#include<string>
#pragma once
using namespace std;
class Jucator
{
    string nume;
    string prenume;
    int puncte;

public:

    Jucator();
    Jucator(string n);
    Jucator(string n1,string pr1, int p1);


    string getNume();
    string getPre();
    int getPuncte();

    void setNume(string nume);
    void setPre(string prenume);
    void setPuncte(int puncte);

    void afisare()const;

    friend ostream &operator<<(ostream &dev, const Jucator &j);
    friend istream &operator>>(istream &dov, Jucator &j);
    friend bool operator!=(const Jucator &j1, const Jucator &j2);
};
