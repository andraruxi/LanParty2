#include"Meci.h"
Meci::Meci()
{
    e1=NULL;
    e2=NULL;
}
Meci::Meci(Echipa *ec1,Echipa*ec2)
{
    if(ec1!=NULL)
    {
        e1=new Echipa();
        e1=ec1;
    }
    else
        e1=NULL;

    if(ec2!=NULL)
    {
        e2=new Echipa();
        e2=ec2;
    }
    else
        e2=NULL;
}
Meci::Meci(const Meci &m)
{
    if(m.e1!=NULL)
    {
        e1=new Echipa();
        e1=m.e1;
    }
    else
        e1=NULL;

    if(m.e2!=NULL)
    {
        e2=new Echipa();
        e1=m.e2;
    }
    else
        e2=NULL;



}
Meci& Meci::operator=(const Meci &m)
{
    if(e1!=NULL)
        delete e1;
    if(m.e1!=NULL)
    {
        e1=new Echipa();
        e1=m.e1;
    }
    else
        e1=NULL;

    if(e2!=NULL)
        delete e2;
    if(m.e2!=NULL)
    {
        e2=new Echipa();
        e2=m.e2;
    }
    else
        e2=NULL;

    return *this;

}
Meci::~Meci()
{
    if(e1!=NULL)
    {
        delete e1;
        e1=NULL;
    }
    if(e2!=NULL)
    {
        delete e2;
        e2=NULL;
    }
}
//avand echipele capointer avem nevoie de const de copiere , op egal si de  destructor ca sa eliberez memorie
Echipa *Meci::getE1()
{
    return e1;
}

Echipa * Meci::getE2()
{
    return e2;

}

void Meci::setE1(Echipa *e1)
{
    this->e1=e1;
}

void Meci::setE2(Echipa *e2)
{
    this->e2=e2;
}

Echipa* Meci::verificaCastigator()
{
    if((e1->verificaMedie())>(e2->verificaMedie()))
        {
            for(int i=0; i<e1->getNr();i++)
                e1->getJuc()[i].setPuncte(e1->getJuc()[i].getPuncte()+1);
            return e1;
        }
    else
        {
            for(int i=0; i<e2->getNr();i++)
                e2->getJuc()[i].setPuncte(e2->getJuc()[i].getPuncte()+1);
            return e2;
        }
}
//Vefiric castrigatori.Iau pe rand echipele si le verific media punctajelor. daca prima echipa are punct mai mare ca a doua
//fac for pentru a creste punctajul echipe cu media mai mare si dupa returnez echipa

Echipa* Meci::verificaInvinsi()
{
    if((e1->verificaMedie())<(e2->verificaMedie()))
        return e1;
    else
        return e2;
}
// la acesta funstie de invinsi pur si simplu verifica care are punctaj mai mic si returneaza cea cu meia cea mai mica

