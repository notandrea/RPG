#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include "inventario.h"
#include "salvataggio.h"
#include "player.h"
#include "equip.h"
#include "nemici.h"
#include "combattimento.h"
#include "turni.h"
using namespace std;

void caricadainventario(map<int, int>& inventario);
void salvainventario(map<int, int>& inventario);
void mostrainventario(map<int, int>& inventario);
void aggiungiinventario(map<int, int>& inventario, int id);
void rimuovidallinventario(map<int, int> &inventario, int id);
void caricasalvataggio(warrior& pwarrior, mage& pmage);
void salvasalvataggio(warrior& pwarrior, mage& pmage);
void equipaggia(player& p, int id);
bool éItemValido(int id);

/*
Cose da vedere/reference:
https://forums.rpgmakerweb.com/index.php
Rivedere sempre da questo sito il sistema di danno https://forums.rpgmakerweb.com/index.php?threads/a-guide-to-damage-formulas.145148/
https://howtomakeanrpg.com/r/a/how-to-make-an-rpg-levels.html <=== per esperienza.
Exp <==fatta
Drop <== fatto
Uso item <== fatto
Sistemare la UI in generale, magari aggiungere qualche clear del cmd ogni tanto, sistemare spazi e cose varie
Iniziare a buttare giú una lore
Migliorare il sistema di danno dei nemici
Bilanciare meglio lo start del gioco, ma serve una lore imo

*/
//dizionario degli item presenti nel gioco


// ======= CLASSI PLAYER =======

struct Drop {
    int itemID;               // ID dell'oggetto che può droppare
    int peso;                 // peso relativo per la selezione (es. 10, 20, 50)
};
map<string, vector<Drop>> tabellaDrop = {
    {"Scheletro", {{110, 20}, {1, 50}, {111, 10}}}, // Spada(20), Erba(50), Scudo(10)
    {"Orco", {{111, 30}, {2, 10}}}                   // Scudo(30), Cristallo(10)
};


// ======= FUNZIONI SALVATAGGIO =======

// ======= STRUTTURA EQUIPAGGIAMENTO =======
/*void caricadainventario(vector<int> &inventario){ //legge l'inventario
    ifstream file("inventario.txt");
    string riga;
    getline(file, riga);
    int id;
    while(file >> id){
        inventario.push_back(id); //salva nel vettore
    }
}*/




bool éItemValido(int id) {
    return dizionarioitem.count(id) > 0;
}
int schermatainiziale(){
cout<<"--------"<<endl;
cout<<"continuare la partita? (1)"<<endl;
cout<<"nuova partita? (2)"<<endl;
cout<<"--------"<<endl;
int scelta;
cin>>scelta;

    return scelta;
}


void calcololvl(player &giocatore){
    int soglia = giocatore.livello * giocatore.livello * giocatore.livello;
    if(giocatore.exp >= soglia){
        giocatore.exp -=soglia;
        giocatore.livello++;
        /*    if(giocatore.éMago() == true){
        cout<<"Il Mago ha raggiunto il livello"<<giocatore.livello<<endl;
    } else{
        cout<<"Il Guerriero ha raggiunto il livello"<<giocatore.livello<<endl;
    } */
    giocatore.éMago() ? cout<<"Il Mago ha raggiunto il livello: "<<giocatore.livello<<endl : cout<<"Il Guerriero ha raggiunto il livello: "<<giocatore.livello<<endl;
        //bonus comuni per entrambi
        giocatore.vita += 5;
        giocatore.difesa += 1;
        giocatore.bonusLevelUp();
    }
}
void calcolaDrop(nemico& nem, map<int, int>& inventario) {
    if (tabellaDrop.count(nem.nomeClasse()) == 0) return;

    int probDropTotale = 30; // percentuale complessiva di drop (es. 30%)

    int provaDrop = rand() % 100 + 1;
    if (provaDrop > probDropTotale) {
        cout << nem.nomeClasse() << " non ha lasciato nulla.\n";
        return; // niente drop
    }

    vector<Drop> drops = tabellaDrop[nem.nomeClasse()];
    int sommaPesi = 0;
    for (auto& d : drops) sommaPesi += d.peso;

    int rnd = rand() % sommaPesi + 1;
    int cumulativo = 0;

    for (auto& d : drops) {
        cumulativo += d.peso;
        if (rnd <= cumulativo) {
            aggiungiinventario(inventario, d.itemID);
            cout << "Hai ottenuto un oggetto dal nemico: " << dizionarioitem[d.itemID] << "!\n";
            break;
        }
    }
}
int main(){
    srand(time(NULL));
    int gamerunning = 1;
    int id = 2; //sistemare per ottenere un oggetto e caricarlo direttamente.
    warrior pwarrior;
    mage pmage;
    map<int, int> inventario;  // id → quantità
    vector<nemico> nemici = { //    nemico(string n, int v, int d, int l, int e){
        nemico("Scheletro", 60, 2, 4, 20), 
        nemico("Orco", 90, 5, 4, 20)
    }; //esempio da mettere in una funzione per i biomi dei vari nemici successivamente
    cout<<"Nel puzzo";
    cout<<pmage.armaturaEquipaggiata.nome<<": armatura mage"<<pmage.armaturaEquipaggiata.bonusDifesa<<endl;
    cout<<pmage.armaEquipaggiata.nome<<": arma mage"<<endl;
    cout<<pwarrior.armaEquipaggiata.nome<<": arma warrior"<<endl;
    if(schermatainiziale() == 1){
        caricadainventario(inventario);
        aggiungiinventario(inventario, id);
        caricasalvataggio(pwarrior, pmage);
        salvasalvataggio(pwarrior, pmage);
        salvainventario(inventario);
        
    //debug
    cout << pwarrior.vita << " "<< pwarrior.difesa << " "  <<  pwarrior.livello << pwarrior.exp<<" " <<pwarrior.armaEquipaggiata.id<<" "<<pwarrior.armaturaEquipaggiata.id<<endl;
    cout << pmage.vita << " "<< pmage.difesa<<" "<< pmage.livello << pmage.exp<<" "<< pmage.armaEquipaggiata.id<<" "<< pmage.armaturaEquipaggiata.id <<endl;
    }else if (schermatainiziale() == 2){
        cout<<"Inizio una nuova partita."<<endl;
    pwarrior.vita = pwarrior.maxVita();
    pmage.vita = pmage.maxVita();
    pwarrior.puntiforza = pwarrior.maxPuntif();
    pmage.mana = pmage.maxMana();
    cout<<"pwarrior vita: "<<pwarrior.vita<<" pmage vita: "<<pmage.vita<<" pwarrior punti forza: "<<pwarrior.puntiforza <<" pmage mana: "<<pmage.mana<<endl;
    }
    combattiTuttiNemici(nemici, pwarrior, pmage, inventario);
  /*  while ((pmage.isAlive() || pwarrior.isAlive()) && nemico.isAlive()) {
        if (pwarrior.isAlive()) turnoplayer(pwarrior, nemico);
        if (pmage.isAlive() && nemico.isAlive()) turnoplayer(pmage, nemico);
        if (nemico.isAlive()) {
            if (pwarrior.isAlive()) turnonemico(nemico, pwarrior);
            if (pmage.isAlive()) turnonemico(nemico, pmage);
        } */
            int turno = 1;
/*while ((pmage.isAlive() || pwarrior.isAlive()) && nemico.isAlive()) {
        cout << "===== TURNO " << turno++ << " =====";

        if (pwarrior.isAlive()) turnoplayer(pwarrior, nemico);
        if (pmage.isAlive() && nemico.isAlive()) turnoplayer(pmage, nemico);

        if (nemico.isAlive()) {
            if (pwarrior.isAlive()) turnonemico(nemico, pwarrior);
            if (pmage.isAlive()) turnonemico(nemico, pmage);
        }
    } */
   /*for (auto& nemico : nemici) {
    if (!nemico.isAlive()) continue;
    
    cout << "\nStai combattendo: " << nemico.nomeClasse() << endl;

    while ((pwarrior.isAlive() || pmage.isAlive()) && nemico.isAlive()) {
        cout << "===== TURNO " << turno++ << " ====="<<endl;
        if (pwarrior.isAlive()) turnoplayer(pwarrior, nemico, inventario, pwarrior, pmage);
                if (nemico.isAlive()) {turnonemico(nemico, pwarrior);}
        if (pmage.isAlive() && nemico.isAlive()) turnoplayer(pmage, nemico, inventario, pwarrior, pmage);
             if (nemico.isAlive()) {turnonemico(nemico, pmage);}
        //sistemare questa parte w - n - m - n

    } 

    cout << nemico.nomeClasse() << " è stato sconfitto!"<<"+ "<<nemico.exp<<" esperienza"<<endl;
    if(nemico.isAlive() == false){
        pmage.exp += nemico.exp;
        pwarrior.exp += nemico.exp;
        calcololvl(pmage);
        calcololvl(pwarrior);
        calcolaDrop(nemico, inventario);  // qui viene aggiunto il drop post calcolo all'inventario.
    } 
}*/
/*turnoplayer(pwarrior, nemico);
turnoplayer(pmage, nemico); */

/*    pwarrior.vita = 0;
  pwarrior.cura(10); 
    //abemus salvataggio
    if (pwarrior.isAlive() == true){
        cout<<"il guerriero è vivo"<<endl;
    } else { cout<<"il guerriero è morto"<<endl;
    }

    cout<<pwarrior.vita; */
    return 0;
}
//aggiungere alla fine un easter egg da alfio: mitoclasta vex
//aggiungere un saggio di nome Gieck, deve evidenziare la pelata
//02/07/2025 rifatto l'inventario, da vettore a mappa.
//aggiunto anche un sistema di drop interamente copiato da gpt ma non sapevo come fare tbh
