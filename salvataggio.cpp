#include <iostream>
#include <fstream>
#include "salvataggio.h"
#include "player.h"
using namespace std;
void caricasalvataggio(warrior& pwarrior, mage& pmage){

    ifstream file("salvataggio.txt");
file >> pwarrior.vita >> pwarrior.difesa >> pwarrior.livello >> pwarrior.exp >> pwarrior.armaEquipaggiata.id >> pwarrior.armaturaEquipaggiata.id;
file >> pmage.vita >> pmage.difesa >> pmage.livello >> pmage.exp >> pmage.armaEquipaggiata.id >> pmage.armaturaEquipaggiata.id;
}

void salvasalvataggio(warrior& pwarrior, mage& pmage){
    ofstream file("salvataggio.txt");
file << pwarrior.vita << " "<< pwarrior.difesa << " "  <<  pwarrior.livello <<" "<<pwarrior.exp <<" "<<pwarrior.armaEquipaggiata.id <<" "<<pwarrior.armaturaEquipaggiata.id<<endl;
file << pmage.vita << " "<< pmage.difesa<<" "<< pmage.livello <<" "<<pmage.exp<<" "<< pmage.armaEquipaggiata.id << " "<<pmage.armaturaEquipaggiata.id<<endl;
}