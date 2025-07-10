#ifndef COMBATTIMENTO_H
#define COMBATTIMENTO_H
#include <map>
#include <vector>
#include "player.h"
#include "inventario.h"
#include "nemici.h"
#include "equip.h"
using namespace std;

// Correzione delle firme delle funzioni per matchare turni.cpp
void turnoplayer(player& giocatore, player& nemico, map<int, int>& inventario, warrior& w, mage& m);
void turnonemico(player& nemico, player& bersaglio);
void calcololvl(player& p);
void calcolaDrop(nemico& n, map<int, int>& inventario);

//funzione principale per il combattimento
void combattiTuttiNemici(vector<nemico>& nemici, warrior& pwarrior, mage& pmage, map<int, int>& inventario);

#endif