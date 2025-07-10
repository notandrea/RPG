


/*#include <iostream>
#include <string>
#include <map>
#include "player.h"
#include "equip.h"
using namespace std;


class player{
        public:
        int vita, difesa, livello, exp;
            Equip armaEquipaggiata;
            Equip armaturaEquipaggiata;

        void cura(int punti, player &giocatore){
            if(vita>0){
            int cura = punti;
            if(maxVita() - giocatore.vita < 10){
                cura = maxVita() - giocatore.vita;
            } else{
                cura = 10;
            }
            vita +=cura;
            cout<<"Si cura di: "<<cura<<endl;
            } else {
                cout<<"impossibile curare un target morto"<<endl;
        }
        }
        bool isAlive(){
            if (vita>0){
            return true;
            } else{
                return false;
            }

        }
        void mostraStatistiche() {
        if(armaEquipaggiata.bonusMagia > 0)cout << "Arma magica: "<<armaEquipaggiata.nome <<" (+" <<armaEquipaggiata.bonusMagia<<" magia)"<<endl;
        cout << "Arma: " << armaEquipaggiata.nome << " (+" << armaEquipaggiata.bonusAttacco << " attacco)"<<endl;
        cout << "Armatura: " << armaturaEquipaggiata.nome << " (+" << armaturaEquipaggiata.bonusDifesa << " difesa)"<<endl;


    }
    virtual bool éMago(){
        return false;
    }
    virtual void usaMagia(player &nemico) {
        cout << "Non puoi usare magia.\n";
    }
    virtual string nomeClasse(){
        return "Figghio";
    }
    virtual void mostraspell(){
        cout<<"Non hai magie/spell a disposizione."<<endl;
        cout<<"..."<<endl;
    }
    virtual void usaPugno(player &nemico){
        cout<<"non puoi usare pugno"<<endl;
    }
    virtual void bonusLevelUp(){
        //aspetta ammia
    }
    virtual int maxVita(){
        //aspetta ammia
        return 0;
    }
    virtual int maxMana(){
        //aspetta ammia
        return 0;
    }
    virtual int maxPuntif(){
        //aspetta ammia
        return 0;
    }
    };
class mage : public player{ //eredita dal player
    public:
    int mana; //aggiungi alle variabili del player anche il mana.
    string tipoClasse = "Mago";
    int baseVita; 
    mage() { 
        mana = 50;
        baseVita = 50;
        Equip e = oggettiEquip[100];
        armaturaEquipaggiata = e;
        livello = 1;
    }
    bool éMago() override{
        return true;
    }
    void usaMagia(player &nemico) {
        if (mana >= 20){
            mana -= 20;
            int dannoMagia = 40 + (armaEquipaggiata.bonusMagia * livello);
            nemico.vita -= dannoMagia;
            cout << "Hai usato la palla di fuoco, -20 mana e hai inflitto: "<<dannoMagia<<" danni"<<endl;
        } else {
            cout << "Non hai abbastanza mana" << endl;
        }
    }
    void mostraspell(){
        cout<<"Palla di fuco -20 mana (1)"<<endl;
        cout<<"..."<<endl;
    }
    void bonusLevelUp() override {
    mana += 10;
    cout << "Hai guadagnato +10 mana!\n";
}
    int maxVita() override{
        int maxV = baseVita + (livello * 10);
        return maxV;
    }
    int maxMana() override {
        int maxM = 30 + (livello * livello * livello);
        return maxM;
    }
};
class warrior : public player{
    public:
    int puntiforza;
    string tipoClasse;
    int baseVita;
    warrior() {
        puntiforza = 50;
        tipoClasse = "Guerriero";
        baseVita = 60;
        Equip e = oggettiEquip[100];
        armaturaEquipaggiata = e;
        livello = 1;
    }
    void usaPugno(player &nemico) {
        if (puntiforza >= 20){
            puntiforza -= 20;
            int danno = 40 + (armaEquipaggiata.bonusAttacco * livello);
            nemico.vita -= danno;
            cout << "Hai usato 'Pugno schiaccia palle', -20 punti forza e hai inflitto:"<<danno<< " danni" << endl;
        } else {
            cout << "Non hai abbastanza punti forza" << endl;
        }
    }
    void mostraspell(){
        cout<<"Pugno schiaccia palle 20 punti forza (1)"<<endl;
        cout<<"..."<<endl;
    }
    void bonusLevelUp() override {
    vita += 5;
    difesa += 1;
    cout << "Hai guadagnato +5 vita e +1 difesa!\n";
}
    int maxVita() override{
        int maxV = baseVita + (livello * 10);
        return maxV;
    }
    int maxPuntif() override {
        int maxP = 30 + (livello * livello * livello);
        return maxP;
    }
}; */
#include "player.h"
#include "equip.h"
#include <iostream>
using namespace std;

// ---------------------- PLAYER --------------------------
void player::cura(int punti, player& giocatore) {
    if (vita > 0) {
        int cura = (maxVita() - giocatore.vita < punti) ? (maxVita() - giocatore.vita) : punti;
        vita += cura;
        cout << "Si cura di: " << cura << endl;
    } else {
        cout << "Impossibile curare un target morto" << endl;
    }
}

bool player::isAlive() {
    return vita > 0;
}

void player::mostraStatistiche() {
    if (armaEquipaggiata.bonusMagia > 0)
        cout << "Arma magica: " << armaEquipaggiata.nome << " (+" << armaEquipaggiata.bonusMagia << " magia)" << endl;
    cout << "Arma: " << armaEquipaggiata.nome << " (+" << armaEquipaggiata.bonusAttacco << " attacco)" << endl;
    cout << "Armatura: " << armaturaEquipaggiata.nome << " (+" << armaturaEquipaggiata.bonusDifesa << " difesa)" << endl;
}

bool player::éMago() { return false; }
void player::usaMagia(player&) { cout << "Non puoi usare magia.\n"; }
string player::nomeClasse() { return "Figghio"; }
void player::mostraspell() { cout << "Non hai magie/spell a disposizione.\n...\n"; }
void player::usaPugno(player&) { cout << "non puoi usare pugno" << endl; }
void player::bonusLevelUp() {}
int player::maxVita() { return 0; }
int player::maxMana() { return 0; }
int player::maxPuntif() { return 0; }

// ---------------------- MAGE ----------------------------
mage::mage() {
    mana = 50;
    baseVita = 50;
    armaturaEquipaggiata = oggettiEquip[100];
    armaEquipaggiata = oggettiEquip[112];
    livello = 1;
}

bool mage::éMago() { return true; }

void mage::usaMagia(player& nemico) {
    if (mana >= 10) {
        mana -= 10;
        int dannoMagia = 40 + (armaEquipaggiata.bonusMagia * livello);
        nemico.vita -= dannoMagia;
        cout << "Hai usato la palla di fuoco, -20 mana e hai inflitto: " << dannoMagia << " danni" << endl;
    } else {
        cout << "Non hai abbastanza mana" << endl;
    }
}

void mage::mostraspell() {
    cout << "Palla di fuco -10 mana (1)\n..." << endl;
}

void mage::bonusLevelUp() {
    mana += 10;
    cout << "Hai guadagnato +10 mana!\n";
}

int mage::maxVita() {
    return baseVita + (livello * 10);
}

int mage::maxMana() {
    return 30 + (livello * livello * livello);
}

// ---------------------- WARRIOR -------------------------
warrior::warrior() {
    puntiforza = 50;
    tipoClasse = "Guerriero";
    baseVita = 60;
    armaturaEquipaggiata = oggettiEquip[100];
    armaEquipaggiata = oggettiEquip[110];
    livello = 1;
}

void warrior::usaPugno(player& nemico) {
    if (puntiforza >= 10) {
        puntiforza -= 10;
        int danno = 40 + (armaEquipaggiata.bonusAttacco * livello);
        nemico.vita -= danno;
        cout << "Hai usato 'Pugno schiaccia palle', -10 punti forza e hai inflitto:" << danno << " danni" << endl;
    } else {
        cout << "Non hai abbastanza punti forza" << endl;
    }
}

void warrior::mostraspell() {
    cout << "Pugno schiaccia palle 20 punti forza (1)\n..." << endl;
}

void warrior::bonusLevelUp() {
    vita += 5;
    difesa += 1;
    cout << "Hai guadagnato +5 vita e +1 difesa!\n";
}

int warrior::maxVita() {
    return baseVita + (livello * 10);
}

int warrior::maxPuntif() {
    return 30 + (livello * livello * livello);
}
