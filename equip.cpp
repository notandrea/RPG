/*#include <iostream>
#include <string>
#include <map>
#include "equip.h"
#include "player.h"
using namespace std;

struct Equip {
    int id = 0;
    string nome = "Nessuno";
    int bonusAttacco = 0;
    int bonusDifesa = 0;
    int bonusMagia = 0;
};
map<int, string> dizionarioitem = {
    {1, "Erba curativa"},
    {2, "Pozione forza"},
    // aggiungi altri item...
};

map<int, Equip> oggettiEquip = {
    {100, Equip{100, "Armatura di cuoio", 0, 10, 0}},
    {110, Equip{110, "Spada del fuoco", 10, 0, 0}},
    {111, Equip{111, "Scudo sacro", 0, 8, 0}}
};

void equipaggia(player& p, int id){

    if(oggettiEquip.count(id)){
        Equip e = oggettiEquip[id];
        if(e.bonusAttacco > 0){
            p.armaEquipaggiata = e;
            cout<<"Arma equip"<<e.nome<<endl;
        }else if(e.bonusDifesa > 0){
            p.armaturaEquipaggiata = e;
            cout<<"Armatura equip"<<e.nome<<endl;
        }else if(e.bonusMagia > 0){
            p.armaEquipaggiata = e;
            cout<<"Arma magica equipaggiata: "<<e.nome<<endl;
        }
    } else {
        cout<<"non lo puoi equipaggiare"<<endl;
    }
}

bool éItemValido(int id) {
    return dizionarioitem.count(id) > 0;
} */
#include "equip.h"
#include "inventario.h" // Per dizionarioitem
#include <iostream>
#include "player.h"
using namespace std;

map<int, Equip> oggettiEquip = {
    {100, {100, "Armatura di cuoio", 0, 7, 0}},
    {110, {110, "Spada del fuoco", 5, 0, 0}},
    {111, {111, "Scudo sacro", 0, 8, 0}},
    {112, {112, "Sfera Magica", 0, 0, 5}},
};

void equipaggia(player& p, int id) {
    if(oggettiEquip.count(id)) {
        Equip e = oggettiEquip[id];
        if(e.bonusAttacco > 0) {
            p.armaEquipaggiata = e;
            cout << "Arma equip: " << e.nome << endl;
        } else if(e.bonusDifesa > 0) {
            p.armaturaEquipaggiata = e;
            cout << "Armatura equip: " << e.nome << endl;
        } else if(e.bonusMagia > 0) {
            p.armaEquipaggiata = e;
            cout << "Arma magica equipaggiata: " << e.nome << endl;
        }
    } else {
        cout << "Non lo puoi equipaggiare" << endl;
    }
}