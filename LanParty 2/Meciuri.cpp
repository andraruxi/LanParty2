#include"Meciuri.h"

Meciuri::Meciuri()
{

}
Meciuri::Meciuri(queue<Meci*>m)
{
   Meci* a;
   while(!m.empty())
    {
        a=m.front();
        meciuri.push(a);
        m.pop();
    }

}

queue<Meci*> Meciuri::getM()
{
    return meciuri;
}
void Meciuri::setM(queue<Meci*>m)
{
   Meci *a;
   while(!m.empty())
    {
        a=m.front();
        meciuri.push(a);
        m.pop();
    }
}
 void Meciuri::adaugaElement (Meci*m)
 {
    meciuri.push(m);
 }
Meci* Meciuri::stergeElement()
{
    Meci*m=meciuri.front();
    meciuri.pop();
    return m;
}

void Meciuri::creeazaMeciuriInitiale(Echipe* lista)
{
    list<Echipa*>::iterator i;
    list<Echipa*> e=lista->getList();
    for(i=e.begin();i!=e.end();i++)
    {
        meciuri.push(new Meci((*i),(*(++i))));//aici ce fac??????????????????????????????????????
    }
}

void Meciuri::creeazaMeciuri(Stiva* castigatori)
{
    while(!castigatori->goala())
        adaugaElement(new Meci(castigatori->stergeElement(), castigatori->stergeElement()));

}
void Meciuri::puneSpatiiMeciuri(ofstream& rez, int len)
{
    for(int i=0; i<len; i++)
        rez<<" ";
        //o functie de adaugare a spatiilor
}
int Meciuri::coadaGoala()
{
    return meciuri.empty();
}

void Meciuri::afiseazaMeci(ofstream& rez, Meci* m)
{
    rez<<m->getE1()->getNech();
    puneSpatiiMeciuri(rez, 33-m->getE1()->getNech().length());
    rez<<"-";
    puneSpatiiMeciuri(rez, 33-m->getE2()->getNech().length());
    rez<<m->getE2()->getNech()<<endl;
}

int Meciuri::puneEchipe(Stiva* castigatori, Stiva* invinsi, ofstream& rez, int nr_meci)
{
    int nr_castigatori=0;
    rez<<endl<<"--- ROUND NO:"<<nr_meci<<endl;
    while(!coadaGoala())//verific daca e coada goala
    {
        Meci* m = stergeElement();//sterg meciri

        afiseazaMeci(rez, m);

        castigatori->adaugaElement(m->verificaCastigator());// pun in stiva de castigatori si invinsi cu ajuto funtiilor din meci
        invinsi->adaugaElement(m->verificaInvinsi());
        nr_castigatori++;//cresc nr de castigatori
    }

    rez<<endl<<"WINNERS OF ROUND NO:"<<nr_meci<<endl;
    castigatori->afiseazaStiva(rez);// afisez

    if(nr_castigatori>=8)
        invinsi->stergeStiva();//sterg stiva de invinsi daca daca nr de castig e mai mare ca 8
    else
    {
        invinsi->stergeStivaDupaTop8();//daca nu sterg stiva dupa ce fac lista cu cei top 8
    }
    return nr_castigatori;// afisez nr de catsigatori
}
