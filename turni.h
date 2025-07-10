#ifndef TURNI_H
#define TURNI_H

#include <map>
#include "player.h"   
#include "nemici.h"   
void turnoplayer(player &giocatore, player &nemico, std::map<int,int>& inventario, warrior& w, mage& m);
void turnonemico(player &nemico, player &bersaglio);
void usaOggettoConEffetto(std::map<int, int>& inventario, int id, player& target, warrior& w);
#endif