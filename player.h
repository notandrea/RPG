/* player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>
#include "equip.h"
using namespace std;

struct Equip {
    int id = 0;
    string nome = "Nessuno";
    int bonusAttacco = 0;
    int bonusDifesa = 0;
    int bonusMagia = 0;
};

class player {
public:
    int vita, difesa, livello, exp;
    Equip armaEquipaggiata;
    Equip armaturaEquipaggiata;

    virtual void cura(int punti, player& giocatore);
    bool isAlive();
    void mostraStatistiche();

    virtual bool éMago();
    virtual void usaMagia(player& nemico);
    virtual string nomeClasse();
    virtual void mostraspell();
    virtual void usaPugno(player& nemico);
    virtual void bonusLevelUp();
    virtual int maxVita();
    virtual int maxMana();
    virtual int maxPuntif();
};

class mage : public player {
public:
    int mana;
    int baseVita;
    mage();
    bool éMago() override;
    void usaMagia(player& nemico) override;
    void mostraspell() override;
    void bonusLevelUp() override;
    int maxVita() override;
    int maxMana() override;
};

class warrior : public player {
public:
    int puntiforza;
    int baseVita;
    warrior();
    void usaPugno(player& nemico) override;
    void mostraspell() override;
    void bonusLevelUp() override;
    int maxVita() override;
    int maxPuntif() override;
};
#endif*/
#pragma once
#include <iostream>
#include <string>
#include <map>
#include "equip.h"

class player {
public:
    int vita, difesa, livello, exp;
    Equip armaEquipaggiata;
    Equip armaturaEquipaggiata;

    virtual void cura(int punti, player &giocatore);
    virtual bool isAlive();
    virtual void mostraStatistiche();

    virtual bool éMago();
    virtual void usaMagia(player &nemico);
    virtual std::string nomeClasse();
    virtual void mostraspell();
    virtual void usaPugno(player &nemico);
    virtual void bonusLevelUp();
    virtual int maxVita();
    virtual int maxMana();
    virtual int maxPuntif();
};

class mage : public player {
public:
    int mana;
    std::string tipoClasse;
    int baseVita;

    mage();
    bool éMago() override;
    void usaMagia(player &nemico) override;
    void mostraspell() override;
    void bonusLevelUp() override;
    int maxVita() override;
    int maxMana() override;
};

class warrior : public player {
public:
    int puntiforza;
    std::string tipoClasse;
    int baseVita;

    warrior();
    void usaPugno(player &nemico) override;
    void mostraspell() override;
    void bonusLevelUp() override;
    int maxVita() override;
    int maxPuntif() override;
};