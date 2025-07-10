#include "combattimento.h"

void combattiTuttiNemici(vector<nemico>& nemici, player& pwarrior, player& pmage, map<int, int>& inventario) {
    for (auto& nemico : nemici) {
        if (!nemico.isAlive()) continue;

        while ((pwarrior.isAlive() || pmage.isAlive()) && nemico.isAlive()) {
            if (pwarrior.isAlive())
                turnoplayer(pwarrior, nemico, inventario, pwarrior, pmage);
            if (nemico.isAlive())
                turnonemico(nemico, pwarrior);
            if (pmage.isAlive() && nemico.isAlive())
                turnoplayer(pmage, nemico, inventario, pwarrior, pmage);
            if (nemico.isAlive())
                turnonemico(nemico, pmage);
        }

        if (!nemico.isAlive()) {
            pmage.exp += nemico.exp;
            pwarrior.exp += nemico.exp;
            calcololvl(pmage);
            calcololvl(pwarrior);
            calcolaDrop(nemico, inventario);
        }
    }
}