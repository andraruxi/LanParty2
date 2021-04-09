#include"Meci.h"
#include"Echipe.h"
#include"Stiva.h"
#include<queue>

class Meciuri
{
    queue<Meci*> meciuri;
public:
    Meciuri();
    Meciuri(queue<Meci*>m);

    queue<Meci*> getM();
    void setM(queue<Meci*>m);

    void creeazaMeciuriInitiale(Echipe* lista);
    void adaugaElement (Meci*m);
    int coadaGoala();
    Meci* stergeElement();
    void puneSpatiiMeciuri(ofstream& rez, int len);
    void creeazaMeciuri(Stiva* castigatori);
    void afiseazaMeci(ofstream& rez, Meci* m);
     int puneEchipe(Stiva* castigatori, Stiva* invinsi, ofstream& rez, int nr_meci);

};
