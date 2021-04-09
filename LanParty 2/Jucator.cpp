#include<iostream>
#include"Jucator.h"
using namespace std;
//Creez constructor fara parametrii
Jucator::Jucator():nume(""),prenume(""),puncte(0)
{
    //cout<<"Jucatorul initializat standard";
}

//creez const cu un par
Jucator::Jucator(string n):nume(n),prenume(""),puncte(0)
{
    //cout<<"Jucatorul primeste doar nume ";

}

//Creez juc cu toti param
Jucator::Jucator(string n1,string pr1, int p1):nume(n1),prenume(pr1),puncte(p1)
{
    //cout<<"Jucatorr primeste nume si puncte";
}
//Nu avem nevoie de constructor de copiere , operator egal si destructor pentru ca nu trebuie
//alocare dinamica=>cele create automata functioneaza bine;

//Nu am nevoie de destructor memoria se sterge automat deoarece nu am niciun pointer

string Jucator::getNume()
{
    return nume;
}

string Jucator::getPre()
{
    return prenume;
}

int Jucator::getPuncte()
{
    return puncte;
}

//am facut getteri si setteri pentru ca ma vor ajuta mai tarziu in progrma

void Jucator::setNume(string nume)
{
    this->nume=nume;
}

void Jucator::setPre(string prenume)
{
    this->prenume=prenume;
}

void Jucator::setPuncte(int puncte)
{
    this->puncte=puncte;
}

void Jucator::afisare()const
{
    //cout<<"Nume:";
    cout<<nume<<" "<<prenume<<" "<<puncte<<endl;
    //cout<<"Prenume";
    //cout<<prenume<<endl;
    //cout<<"Puncte";
    //cout<<puncte<<endl;
}
// am facut afisrae pentru a testa programul fara checker
ostream &operator<<(ostream &dev, const Jucator &j)
{

    dev<<"Nume jucator"<<j.nume<<endl;
    dev<<"Prenume"<<j.prenume<<endl;
    dev<<"Puncte"<<j.puncte<<endl;
    return dev;

}

istream &operator>>(istream &dov,  Jucator &j)
{
    cout<<"Nume jucator";
    dov>>j.nume;
    cout<<"Prenume";
    dov>>j.prenume;
    cout<<"Puncte";
    dov>>j.puncte;
    return dov;
}

bool operator!=(const Jucator &j1, const Jucator &j2)
{
    return((j1.nume!=j2.nume)&&(j1.prenume!=j2.prenume)&&(j1.puncte!=j2.puncte));
}
// de operatori ma voi folosi atunci cand citesc si scriu in fisier
