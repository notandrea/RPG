#ifndef NEMICI_H
#define NEMICI_H
#include <vector>
#include "player.h"
using namespace std;
class nemico : public player {
public:
    string nome;
    nemico(string n, int v, int d, int l, int e);
    string nomeClasse() override;
};

    #endif