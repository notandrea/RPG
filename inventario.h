/*#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <map>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
map<int, string> dizionarioitem = {
    {1, "Erba curativa"}, //diamo un id agli oggetti, li salviamo nell'inventario come id, successivamente il player vedrà SOLTANTO gli item
    {2, "Cristallo oscuro"},
    {3, "Pozione di mana"},
    {100, "Armatura di cuio"},
    {110, "Spada del fuoco"},
    {111, "Scudo sacro"}
}; 

void caricadainventario(map<int, int>& inventario); */
/*void salvainventario(vector<int> &inventario){ //salva l'inventario
    ofstream file("inventario.txt");
     for (size_t i = 0; i < inventario.size(); ++i) {
        file << inventario[i] << endl; //scrive nel file il vettore
    }
}*/
// void salvainventario(map<int, int>& inventario);

/*void mostrainventario(vector<int> &inventario){
    cout<<"Inventario: "<<endl;
    if(inventario.empty()) cout<<"L'inventario è vuoto"<<endl;
    else{
        for(int id : inventario) //scorre tutti gli elementi presenti nel vettore
        cout<<"- "<<dizionarioitem[id]<<endl;
    }
}*/
// void mostrainventario(map<int, int>& inventario);
/*void aggiungiinventario(vector<int> &inventario, int id){
    if(dizionarioitem.count(id)){
        inventario.push_back(id);
        cout<<"hai ottenuto: "<<dizionarioitem[id]<<endl;
}
else{
    cout<<"oggetto non esistente!!"<<endl;
} 
}*/
//void aggiungiinventario(map<int, int>& inventario, int id);
//void rimuovidallinventario(map<int, int> &inventario, int id);
//#endif
#pragma once
#include <map>
#include <string>

extern std::map<int, std::string> dizionarioitem;

void mostrainventario(std::map<int, int>& inventario);
void aggiungiinventario(std::map<int, int>& inventario, int id);
void salvainventario(std::map<int, int>& inventario);
void caricadainventario(std::map<int, int>& inventario);
