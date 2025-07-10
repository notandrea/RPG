#include "turni.h"
#include <iostream>
#include "inventario.h"

using namespace std;
void usaOggettoConEffetto(map<int, int>& inventario, int id, player& target, warrior& w) {
    if (inventario.count(id) && inventario[id] > 0) {
        inventario[id]--;
        if (inventario[id] == 0) inventario.erase(id);

        cout << "Hai usato: " << dizionarioitem[id] << endl;

        if (id == 1) {
            target.cura(10, target);
        }
        else if (id == 2) {
            // Solo il guerriero può usarla
            if (!target.éMago()) {
                w.puntiforza += 20;
                cout << "Punti forza aumentati di 20!" << endl;
            } else {
                cout << "Il mago non può usare questa pozione." << endl;
            }
        }
    } else {
        cout << "Non hai questo oggetto nell'inventario!" << endl;
    }
}
void turnoplayer(player &giocatore, player &nemico, map<int, int>& inventario, warrior& w, mage& m) {
    cout << "Turno ";
    /*if (giocatore.éMago()) {
        cout << "del Mago" << endl;
    } else {
        cout << "del Guerriero" << endl;
    }*/
    giocatore.éMago() ? cout<<"del Mago"<<endl : cout<<"del Guerriero"<<endl;
    cout << "Attacca (1), Item (2), Spell (3), Situazione Party (4)" << endl;
    cout << "Scegli: ";
    int scelta;
    cin >> scelta;
switch(scelta){
    case 1:
        {
        int bonus = giocatore.éMago() ? giocatore.armaEquipaggiata.bonusMagia : giocatore.armaEquipaggiata.bonusAttacco;
        int danno = (giocatore.livello * 5 + bonus) - nemico.difesa;
        danno = max(0, danno);
        nemico.vita -= danno;
        cout << "Hai inflitto: " << danno << " danni" << endl;
        break;
    }
    case 2:
        {
            cout << "Gli item disponibili sono:" << endl;
        mostrainventario(inventario);
        cout << "Quale item vuoi utilizzare? Inserisci l'ID (0 per tornare): ";
        int sceltaItem;
        cin >> sceltaItem;
        if (sceltaItem == 0) return; // torna al menu principale
        if (!éItemValido(sceltaItem)) {
            cout << "Item non esistente!" << endl;
            return;
        }
        usaOggettoConEffetto(inventario, sceltaItem, giocatore, w);
        break;
    }
    case 3:
        {
        if (giocatore.éMago()) {
            giocatore.mostraspell();
            int sceltaMagia;
            cin >> sceltaMagia;
            if (sceltaMagia == 1) {
                giocatore.usaMagia(nemico);
            }
        } else {
            giocatore.mostraspell();
            int sceltaPugno;
            cin >> sceltaPugno;
            if (sceltaPugno == 1) {
                giocatore.usaPugno(nemico);
            }
        }
    }
        break;
    case 4:
    {
        cout << "Situazione party:" << endl;
        cout << "Mage: " << m.vita << " HP    " << m.mana << " MP" << endl;
        cout << "Warrior: " << w.vita << " HP    " << w.puntiforza << " MP" << endl;
        break;
    }
    default: 
    cout << "Scelta non valida (bestia)" << endl;
        break;
    }
}
    /*if (scelta == 1) {
        int bonus = giocatore.éMago() ? giocatore.armaEquipaggiata.bonusMagia : giocatore.armaEquipaggiata.bonusAttacco;
        int danno = (giocatore.livello * 5 + bonus) - nemico.difesa;
        danno = max(0, danno);
        nemico.vita -= danno;
        cout << "Hai inflitto: " << danno << " danni" << endl;

    } else if (scelta == 2) {
        cout << "Gli item disponibili sono:" << endl;
        mostrainventario(inventario);
        cout << "Quale item vuoi utilizzare? Inserisci l'ID (0 per tornare): ";
        int sceltaItem;
        cin >> sceltaItem;
        if (sceltaItem == 0) return; // torna al menu principale
        if (!éItemValido(sceltaItem)) {
            cout << "Item non esistente!" << endl;
            return;
        }
        usaOggettoConEffetto(inventario, sceltaItem, giocatore, w);

    } else if (scelta == 3) {
        if (giocatore.éMago()) {
            giocatore.mostraspell();
            int sceltaMagia;
            cin >> sceltaMagia;
            if (sceltaMagia == 1) {
                giocatore.usaMagia(nemico);
            }
        } else {
            giocatore.mostraspell();
            int sceltaPugno;
            cin >> sceltaPugno;
            if (sceltaPugno == 1) {
                giocatore.usaPugno(nemico);
            }
        }

    } else if (scelta == 4) {
        cout << "Situazione party:" << endl;
        cout << "Mage: " << m.vita << " HP    " << m.mana << " MP" << endl;
        cout << "Warrior: " << w.vita << " HP    " << w.puntiforza << " MP" << endl;

    } else {
        cout << "Scelta non valida (bestia)" << endl;
    }
}*/

void turnonemico(player &nemico, player &bersaglio){
    if (!nemico.isAlive()) return; // se il nemico è morto non agire
    int danno = (nemico.livello * 4) - (bersaglio.difesa + bersaglio.armaturaEquipaggiata.bonusDifesa);
    danno = max(0, danno);
    bersaglio.vita -= danno;
    cout << "Il nemico attacca e infligge " << danno << " danni." << endl;
}
