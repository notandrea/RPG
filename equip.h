/*#ifndef EQUIP_H
#define EQUIP_H

#include <iostream>
#include <string>
#include <map>
#include "player.h"
using namespace std;
struct Equip;
extern map<int, string> dizionarioitem;
extern map<int, Equip> oggettiEquip;
extern void equipaggia(player& p, int id);
bool éItemValido(int id);
#endif */
#pragma once

#include <string>
#include <map>

class player; // <-- DICHIARAZIONE ANTICIPATA DELLA CLASSE

struct Equip {
    int id = 0;
    std::string nome = "Nessuno";
    int bonusAttacco = 0;
    int bonusDifesa = 0;
    int bonusMagia = 0;
};

extern std::map<int, Equip> oggettiEquip;


void equipaggia(player& p, int id);
bool éItemValido(int id);