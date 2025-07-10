#ifndef COMBATTIMENTO_H
#define COMBATTIMENTO_H
#include <map>
#include <vector>
#include "player.h"
#include "inventario.h"
#include "nemici.h"
#include "equip.h"
#include "nemici.h"
using namespace std;
void turnoplayer(player& giocatore, nemico& nemico, map<int, int>& inventario, player& pwarrior, player& pmage);
void turnonemico(nemico& nemico, player& giocatore);
void calcololvl(player& p);
void calcolaDrop(nemico& n, map<int, int>& inventario);

//funzione principale per il combattimento
void combattiTuttiNemici(vector<nemico>& nemici, player& pwarrior, player& pmage, map<int, int>& inventario);


#endif