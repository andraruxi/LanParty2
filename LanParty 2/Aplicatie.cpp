#include"Aplicatie.h"
//Aceasta clasa preia tot rolul mainului si imi face legatura dintre clase ca sa nu folosesc functiile frind care
//imi distrug incapsulare dateleo
//astfel programul incearca sa fie cat mai mult POO
Aplicatie::Aplicatie()
{
    /*lista=new Liste();
    coada=new Coada();
    castigatori=new Stiva();
    invinsi=new Stiva();
    bts=new BTS();
    avl=new AVL();*/
    e=new Echipe();
    m=new Meciuri();
    s=new Stiva();
    castigatori=new Stiva();
    invinsi=new Stiva();

    cerinte.open("c.in");
    if(!cerinte) cout<<"Eroare";
    date.open("d.in");
    if(!date) cout<<"Eroare";
    rezultate.open("r.out", ios::app);
    if(!rezultate)cout<<"Eroare";
}
//constructor fara parametrii care imi aloca spatiu pentru toate structurile mele de date
//si deschide si testeaza fisierele
Aplicatie::Aplicatie(char* fisier1, char* fisier2, char* fisier3)
{
    /*lista=new Liste();
    coada=new Coada();
    castigatori=new Stiva();
    invinsi=new Stiva();
    bts=new BTS();
    avl=new AVL();
    BOMBA=new Liste();*/
    e= new Echipe();
    m=new Meciuri();
    s=new Stiva();
    castigatori=new Stiva();
    invinsi=new Stiva();

    cerinte.open(fisier1);
    if(!cerinte) cout<<"Eroare";
    date.open(fisier2);
    if(!date) cout<<"Eroare";
    rezultate.open(fisier3, ios::app);
    if(!rezultate)cout<<"Eroare";
}
//imi pune echipe in stivele de invinsi si castigatori din coada

void Aplicatie::completeazaStivele()
{
    while(m!=NULL)
    {

        castigatori->adaugaElement(m->stergeElement()->verificaCastigator());
        invinsi->adaugaElement(m->stergeElement()->verificaInvinsi());

    }
}


void Aplicatie::creareMeciStiva()
{
    Meci*mec;
    while(!castigatori->goala())
    {
         mec=NULL;

         mec->setE1(castigatori->stergeElement());
         mec->setE2(castigatori->stergeElement());
         m->adaugaElement(mec);

    }
}
//preia echipele din stiva de catsigatori si face meciuri pentru a le baga iar in coada
void Aplicatie::run()
{
    int v[5] = {0};
    for(int i = 0; i < 5; i++)
    {
        cerinte>>v[i];
    }

    e->citesteList(date);

    if(v[4] == 1)
        cerinta5();
    else if(v[3] == 1)
        cerinta4();
    else if(v[2] == 1)
        cerinta3();
    else if(v[1] == 1)
        cerinta2();
    else if(v[0] == 1)
        cerinta1();

    cerinte.close();
    date.close();
    rezultate.close();
}
//run e functia care  imi ruleaza toate cerintele si practic e singura functie pe care trebuie sa o pun in main
void Aplicatie::cerinta1()
{
    e->afiseazaLista(rezultate);
}

void Aplicatie::cerinta2()
{
    e->stergeEchipe();
    e->afiseazaLista(rezultate);
}

void Aplicatie::cerinta3()
{

    cerinta2();

    m->creeazaMeciuriInitiale(e);
    int runda = 1;
    int nr_echipe = 100000;

    while(nr_echipe>1)
    {
        nr_echipe=m->puneEchipe(castigatori, invinsi, rezultate, runda);
        if(nr_echipe==8)
            listaTop8=castigatori->creeazaLista();
        m->creeazaMeciuri(castigatori);
        runda++;
    }
}

void Aplicatie::cerinta4()
{
  /*  cerinta3();
    bts->creeazaBTS(listaTop8);

    rezultate<<endl<<"TOP 8 TEAMS:"<<endl;
    bts->afiseazaDescresc(bts->getRadacina(), rezultate, BOMBA);*/
}

void Aplicatie::cerinta5()
{
    /*cerinta4();
    avl->creeazaAVL(BOMBA);
    Liste* aux = new Liste();
    //Nod* tmp = BOMBA->getCap();
    //while(tmp!=NULL)
    //    aux->
    avl->afiseazaNivel2(rezultate);*/
}
// cele 5 dunctii de tip cerinta imi afiseaza in fisiere in creeaza si afiseaza toate structurile de date acestea fiind
//apelate ulterior in run

/*Aplicatie::~Aplicatie()
{
    if(lista)
        delete lista;
    if(coada)
        delete coada;
    if(castigatori)
        delete castigatori;
    if(invinsi)
        delete invinsi;
    if(bts)
        delete bts;
    if(avl)
        delete avl;

}*/


