#include"Echipa.h"
//creez const fara par
Echipa::Echipa():nr_juc(0),nume_echipa("")
{
    juc=NULL;
}

Echipa::Echipa(int nr,string n_e):nr_juc(nr),nume_echipa(n_e)
{
    juc=new Jucator[nr];
}

//Creez constructori cu toti parametrii
Echipa::Echipa(int nr,string n_e, const Jucator *j):nr_juc(nr),nume_echipa(n_e)
{
    int i;
    if(j!=NULL)
    {
        juc=new Jucator[nr];
        for(i=0;i<nr;i++)
        {
            juc[i]=j[i];
        }
    }
}

//constructor de copiere pentru ca trenuie sa alocam urm
Echipa::Echipa(const Echipa&l):nr_juc(l.nr_juc),nume_echipa(l.nume_echipa)
{
    int i;
    if(l.juc!=NULL)
    {
        juc=new Jucator[l.nr_juc];
        for(i=0;i<l.nr_juc;i++)
        {
            juc[i]=l.juc[i];
        }
    }
}

//operatorul egal
Echipa & Echipa::operator=(const Echipa &l)
{
    int i;
    nr_juc=l.nr_juc;
    nume_echipa=l.nume_echipa;
    if(l.juc!=NULL)
    {
        juc=new Jucator[l.nr_juc];
        for(i=0;i<l.nr_juc;i++)
        {
            juc[i]=l.juc[i];
        }
    }

    return *this;
}

//destructor
Echipa::~Echipa()
{
    if(juc!=NULL)
    {
        delete [] juc;
        juc=NULL;
    }
}
//Pentru ca vectorul de jucatori este unul alocat dinamic am nevoie de implementare const de copiere destructor si operatorul egal pentru
// deoarece cele automate nu funtioneaza corect
//Face, getteri
int Echipa::getNr()
{
    return nr_juc;

}

string Echipa::getNech()
{
    return nume_echipa;
}

Jucator* Echipa::getJuc()
{
    return juc;
}

//facem setteri;
void  Echipa::setNr(int nr_juc)
{

    this->nr_juc=nr_juc;
}

void Echipa::setNech(string nume_echipa)
{
    this->nume_echipa=nume_echipa;

}

void Echipa::setJuc(Jucator *juc)
{
    int i;
    delete[] this->juc;
    this->juc=new Jucator[nr_juc];
    for(i=0;i<nr_juc;i++)
    {
        this->juc[i]=juc[i];
    }
}

void Echipa::afisare()const
{
    int i;
    cout<<nr_juc<<" "<<nume_echipa<<endl;
    for(i=0;i<nr_juc;i++)
    {
        juc[i].afisare();
    }

}

ostream &operator<<(ostream &dev, const Echipa &e)
{
    int i;
    dev<<"Nr_juc";
    dev<<e.nr_juc<<endl;
    dev<<"Nume echipa:";
    dev<<e.nume_echipa<<endl;
    dev<<"Jucatori";
    for(i=0;i<11;i++)
    {
        dev<<e.juc[i]<<endl;
    }
    return dev;

}
istream &operator>>(istream &dov, Echipa  &e)
{
    int i;
    cout<<"Nr juc:";
    dov>>e.nr_juc;
    cout<<"Nume_echipa:";
    dov>>e.nume_echipa;
    cout<<"Jucatori";
    e.juc=new Jucator[e.nr_juc];
    for(i=0;i<e.nr_juc;i++)
    {
        dov>>e.juc[i];
    }
    return dov;

}

float Echipa::verificaMedie()
{
    float medie;
    int sum=0;
    int i;
    for(i=0;i<nr_juc;i++)
    {
        sum=sum+juc[i].getPuncte();
    }
    medie=sum/float(nr_juc);
    return medie;
}
//Verifica media face punctajul echipei de care voi avea nevoie pe tot parcursul programului

void Echipa::addJuc(Jucator j)
{
    juc[index_ramas]=j;
    index_ramas++;
}

//adaug un jucator cu ajutorul indexului care imi indica unde am ramas in momentrl in care bag in lista sau cand citesc din fisiere / bag in fisiere

bool operator!=(const Echipa &e1, const Echipa &e2)
{
    return ((e1.nr_juc!=e2.nr_juc) && (e1.nume_echipa!=e2.nume_echipa) && (e1.juc!=e2.juc));
}


Echipa* Echipa::getCopieEp()
{
    return new Echipa(nr_juc,nume_echipa,juc);
}

