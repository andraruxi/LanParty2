<h1 align="center">
  OOP Lan Party Checker  
</h1>

OOP Lan Party Checker is a script designed to automate the homework testing. It's an open-source project build by teaching assistants for students of Faculty of Automatic Control & Systems Engineering - PUB. Its purpose is to make the grading systems more transparent and easier for both students & teaching assistants.


## Running the Checker
To verify that the checker is working on your computer follow the next steps:
  - download this repo
  - open a terminal in the root folder of the downloaded repo
  - type the following command: ```./checker.sh```
    - if you get a permission error type the following command: ```chmod +x checker.sh```

Read Me
	Am folosit aceleasi functii , dar de data acesta am folosit stl pentru stiva coada si lista si vector.In rest, totul este la fel.
Am implementat doar primele 3 cerinte.
	Tema urmareste sa atinga punctele cele mai importante din POO si anume incapsularea datelor, polimorfisme , 
agregare, supradefinirea operatorilor si asa mai departe.Insa, ca sa facem aceste lucru cat mai bine, incercam pe cat
 posibil sa cream cat mai multe clase si sa nu utilizam asa mult main-ul.
De aceea, am incercat sa fac o clasa numita Aplicatie, care sa preia tot rolul mainului. Astfel , in main apelez doar 
functia run care imi executa intreaga problema.
	Astfel, am creat echipa care va avea un vector de tip jucator(o alta clasa) si va preia folosind agregarea astfel incerc 
sa reutilizez cat mai mult codul.In unele parti se putea face chiar cu mostenire, dar mi s-a parut normal sa nu o folosesc 
deoarece tema se bazeaza pe primele 6 capitole.
	Pentru crearea listei ma voi folosi de o alta clasa numita nod pe care o sa o folosesc si la stiva => mai eficient.
Nodul meu primeste o echipa si un atribut de tip nod care reprezinta urmatorul(legatura dintre noduri).In lista efecitv, 
voi avea un atribut de tip nod care reprezinta capul.In acesta clasa , lista(Liste) voi face citirea din fisier, crearea liste,
adaugarea unui nod, stergerea , si chiar eliberarea de memorie.Cerinta 2 imi  cere insa sa elimin niste echipe, astfel,
in echipa voi avea o functie care imi verifica scorul , iar in lista o metoda care se foloseste de aceasta functie pentru a gasi
valoarea minima si sa elimine echipa respectiva.Voi sterge pana voi ajunge la nr specificat in enunt. 
	La cerinta 3, am nevoie de alte structuri de date , asadar voi face alte clase una pentru stiva unde folosesc acelasi nod ca la stiva,
insa pentru coada voi folosi nod coada care primeste un atribut de tip meci si legatura. Meci este o alta clasa care are ca atribute 2 echipe,
care vor fi comparate in functie de punctaj si cu ajutorul acesti clase vom forma si stivele de castigatori, respectiv invinsi.
In coada, vom avea doua atribute de tip nod coada =>o fata si un spate. Ca metode avem adaugare meci, eliminare, creare coada, afisare 
si asa mai departe.Clasa stiva e formata pentru a putea crea stivele de invinsi si castigatori.In aplicatie, facem legatura intre coada stiva si liste.
Altfel, ar trebui sa folosim functii friend care ne strica incapsularea datelor si nu vrem acest lucru.Asa avem acces usor la tot ce am creat si puteam 
pune echipe in stive si din stiva de castigatori inapoi in coada sub forma de meci.
	De asemenea, cerinta 4 ne spune sa folosim arbori BST => trebuie sa formam alte clase nod arbore si clasa BTS. Ca la cerinta 3 si 2, 
vom implmentat ce este nevoie pentru a face radacini si a afisa descrescator arborele asa cum ne zice checkerul.
Asemanator se intampla si la arborele AVL, insa aici vom avea un nod Avl care va avea in plus in atribut int inaltime . Iar  clasa 
AVL va primi atr de tip nod AVL. Crearea acestuia insa va avea nevoie de 4 rotatii=> la stanga , la dreapta , LR si RL.
	In final, in clasa aplicatie se vor implementa toate cele 5 cerinte, iar in main se va apela functia run care pune cap la cap tot
programul.
 
