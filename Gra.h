#ifndef gra_H_
#define gra_H_

#include <vector>
#include "Gracz.h"
#include "Plansza.h"

class Gra {
public:
    Gra(const std::vector<bool>& gracze, const std::vector<int>& liczbyKart);
    void uruchom();

private:
    void grajRozdanie(int liczbaKart, int ktoWistuje);
    void pobierzDeklaracje();
    void rozdajKarty(int liczbaKart);
    void grajLewe();

    int liczbaGraczy;
    Plansza* plansza;
    std::vector<Gracz*> gracze;

    std::vector<bool> zywiGracze;
    std::vector<int> liczbyKart;

};
#endif
