#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "inventario.h"
using namespace std;
map<int, string> dizionarioitem = {
    {1, "Erba curativa"}, //diamo un id agli oggetti, li salviamo nell'inventario come id, successivamente il player vedrà SOLTANTO gli item
    {2, "Cristallo oscuro"},
    {3, "Pozione di mana"},
    {100, "Armatura di cuio"},
    {110, "Spada del fuoco"},
    {111, "Scudo sacro"},
    {112, "Sfera Magica"},
};

void caricadainventario(map<int, int>& inventario) {
    ifstream file("inventario.txt");
    int id, quantita;
    while (file >> id >> quantita) {
        inventario[id] = quantita;
    }
}
void salvainventario(map<int, int>& inventario) {
    ofstream file("inventario.txt");
    for (const auto& oggetto : inventario) {
        file << oggetto.first << " " << oggetto.second << endl;
    }
}

void mostrainventario(map<int, int>& inventario){
    cout << "Inventario: " << endl;
    if(inventario.empty()) cout << "L'inventario è vuoto" << endl;
    else {
        for(const auto& oggetto : inventario){
            cout << "- " << dizionarioitem[oggetto.first] << " x" << oggetto.second << endl;
        }
    }
}
void aggiungiinventario(map<int, int>& inventario, int id){
    if(dizionarioitem.count(id)){
        inventario[id]++;
        cout<<"Hai ottenuto: "<<dizionarioitem[id]<<endl;
    } else {
        cout<<"Oggetto non esistente!"<<endl;
    }
}
void rimuovidallinventario(map<int, int> &inventario, int id) {
    if (inventario.count(id) && inventario[id] > 0) {
        inventario[id]--;
        cout << "Hai usato: " << dizionarioitem[id] << endl;
        if (inventario[id] == 0) {
            inventario.erase(id);
        }
    } else {
        cout << "Non hai questo oggetto nell'inventario!\n";
    }
}
