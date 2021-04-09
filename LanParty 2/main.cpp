#include <iostream>
#include <fstream>
#include "Aplicatie.h"

using namespace std;



int main(int argc, char** argv)
{

    Aplicatie* app = new Aplicatie(argv[1], argv[2], argv[3]);
    app->run();
    //apelez functia ran cu ajutorul obiectului app care primeste un const cu 3 parametri fisiere

//delete app;
    return 0;

}
