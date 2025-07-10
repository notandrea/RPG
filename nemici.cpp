#include <vector>
#include "nemici.h"
using namespace std;

nemico::nemico(std::string n, int v, int d, int l, int e) {
    nome = n;
    vita = v;
    difesa = d;
    livello = l;
    exp = e;
}
string nemico::nomeClasse() {
    return nome;
}
