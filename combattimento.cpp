#include "combattimento.h"
#include "turni.h"

void combattiTuttiNemici(vector<nemico>& nemici, warrior& pwarrior, mage& pmage, map<int, int>& inventario) {
int turno = 1;
    for (auto& nemico : nemici) {
        if (!nemico.isAlive()) continue;
        cout << "===== TURNO " << turno++ << " =====";
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