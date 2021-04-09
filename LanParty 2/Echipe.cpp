#include"Echipe.h"
Echipe::Echipe()
{

}
Echipe::Echipe(list<Echipa*>e)
{
    list<Echipa*>::iterator i;
    for(i=e.begin();i!=e.end();i++)
    {
        echipe.push_back(*i);
    }
}

list<Echipa*> Echipe::getList()
{
    return echipe;
}
void Echipe::setList(list<Echipa*> e)
{
    echipe=e;
}

void Echipe::afisare()
{
    list<Echipa*>::iterator i;
    for(i=echipe.begin();i!=echipe.end();i++)
    {
        cout<<(*i)->getNech()<<endl;
    }
}
void Echipe::adaugareFront(Echipa *e)
{
    echipe.push_front(e);
}
void Echipe::adaugareBack(Echipa *e)
{
    echipe.push_back(e);

}
void Echipe::citesteList(ifstream &f)
{
    int i,j,n;
    list<Echipa>::iterator k;
    f>>n;
    for(i=0; i<n; i++)
    {
        int nr_jucatori;
        string nume_echipa;
        f>>nr_jucatori;
        f.get();
        getline(f,nume_echipa);
        if(nume_echipa.back() == ' ')
            nume_echipa.pop_back();
       adaugareFront(new Echipa(nr_jucatori, nume_echipa));

        for(j=0; j<nr_jucatori; j++)
        {
            string nume, prenume;
            int puncte;
            f>>nume;
            f>>prenume;
            f>>puncte;
            list<Echipa*>::iterator k=echipe.begin();
            (*k)->addJuc(Jucator(nume, prenume, puncte));
            //k++;

        }
    }
}
string Echipe::puncteMin()
{
    float minim=100000;
    string n;
    list<Echipa*>::iterator i;

    for(i=echipe.begin();i!=echipe.end();i++)
    {
        if(minim>(*i)->verificaMedie())
        {
            minim=(*i)->verificaMedie();
            n=(*i)->getNech();
        }
    }
    return n;
}
void Echipe::stergeEchipe()
{
    int nr_noduri=echipe.size();
    int n_max=1, copie=1;
    list<Echipa*>::iterator i;

    while(nr_noduri>=copie)
    {
        n_max=copie;
        copie = copie * 2;
    }
    while(nr_noduri>n_max)
    {
        string minim = puncteMin();

        for(i=echipe.begin(); i!=echipe.end(); i++)
        {

            if((*i)->getNech()==minim)
            {
                echipe.erase(i);

                nr_noduri--;
                break;
            }
        }
    }
}
void Echipe::afiseazaLista(ofstream& rez)
{
   list<Echipa*>::iterator i;
    for(i=echipe.begin();i!=echipe.end();i++)
    {
        rez<<(*i)->getNech()<<endl;
    }
}


