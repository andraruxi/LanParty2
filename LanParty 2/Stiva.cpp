#include"Stiva.h"
#include <iomanip>
#include<vector>

Stiva::Stiva()
{

}
Stiva::Stiva(stack<Echipa*>s)
{
    Echipa* e;
    while(!s.empty())
    {
        e=s.top();
        stive.push(e);
        s.pop();
    }
}

stack<Echipa*> Stiva::getS()
{
    return stive;
}
void Stiva::setS(stack<Echipa*>s)
{
     Echipa *e;
    while(!s.empty())
    {
        e=s.top();
        stive.push(e);
        s.pop();
    }

}

void Stiva::puneSpatiiStiva(ofstream& rez, int len)
{
    for(int i=0; i<len; i++)
        rez<<" ";
}
void Stiva::afiseazaStiva(ofstream& rez)
{
     vector<Echipa*> auxiliar;
    while(!goala())
    {
        rez<<stive.top()->getNech();
        auxiliar.push_back(stive.top());
        puneSpatiiStiva(rez, 34-stive.top()->getNech().length());
        rez<<"-  "<<setprecision(2)<<fixed<<stive.top()->verificaMedie()<<endl;//imi aranjeaza frumos stiva  si pune sa afiseze scorul fix cu 2 zecimale
        stergeElement();
    }

    for(int i=auxiliar.size()-1;i>=0;i--)
    {
        stive.push(auxiliar[i]);
    }
}

Echipa* Stiva::stergeElement()
{
    Echipa* e=stive.top();
    stive.pop();
    return e;
}
int Stiva::goala()
{

    return stive.empty();
}

void Stiva::adaugaElement(Echipa *e)
{
    stive.push(e);
}
void Stiva::stergeStiva()
{
    while(!stive.empty())
    {
        stive.pop();
    }
}
void Stiva::stergeStivaDupaTop8()
{

    while(!stive.empty())
    {
        stive.pop();
    }

}

Echipe* Stiva::creeazaLista()
{
    Echipe *l=new Echipe();
    list<Echipa*>::iterator i;//=l->getList().begin();
    for(i=l->getList().begin();i!=l->getList().end();i++)
    {
        l->adaugareFront((*i)->getCopieEp());// unde pun aia get copie o am momentan in Echipe

    }
    return l;
}
