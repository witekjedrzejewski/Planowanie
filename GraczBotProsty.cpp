#include <iostream>

#include "GraczBotProsty.h"

using namespace std;

GraczBotProsty::GraczBotProsty(int nr) : GraczBot(nr) {
}

GraczBotProsty::~GraczBotProsty() {
}

Karta GraczBotProsty::wybierzKarte() {
    vector<Karta>ost = plansza->ostatniaLewa();
    for (unsigned i = 0; i < ost.size(); ++i) {
	odkreslKarte(ost[i]);
    }
    vector<Karta>stol = plansza->stol();
    int ktoWychodzi = plansza->ktoWychodzi();
    for (int i = ktoWychodzi; i < nr; i = plansza->kolejnyGracz(i)) {
	odkreslKarte(stol[i]);
    }
    
    int idx = 0;
    while (!kartaONumerzePoprawna(idx)) {
	idx++;
    }
    return kartaONumerze(idx);
    
}

int GraczBotProsty::wybierzDeklaracje() {
    int d = reka.size() / plansza->liczbaGraczy();    
    cout << "Gracz " << nr << " deklaruje " << d 
	    << " (" << wypiszReke() << ")" << endl;
    
    return d;
}

void GraczBotProsty::setReka(std::vector<Karta> r) {
    GraczBot::setReka(r);
    
    for (unsigned i = 0; i < r.size(); ++i) {
	odkreslKarte(r[i]);
    }
}

void GraczBotProsty::usunKarteONumerze(int nrKarty) {
    GraczBot::usunKarteONumerze(nrKarty);
    
    odkreslKarte(kartaONumerze(nrKarty));
}

void GraczBotProsty::odkreslKarte(Karta k) {
    t[k.kolor()][k.wysokosc()] = 1;
}