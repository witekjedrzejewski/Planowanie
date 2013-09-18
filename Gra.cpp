#include <iostream>

#include "Gra.h"
#include "Talia.h"
#include "GraczZywy.h"
#include "GraczBotProsty.h"

using namespace std;

Gra::Gra(const vector<bool>& g, const vector<int>& k)
: zywiGracze(g), liczbyKart(k) {
}

void Gra::uruchom() {
    cout << "ROZPOCZYNAM GRE" << endl;
    liczbaGraczy = zywiGracze.size();

    plansza = new Plansza(liczbaGraczy);

    cout << "Gracze:" << endl;

    for (int i = 0; i < liczbaGraczy; i++) {
	cout << i << ": ";
	if (zywiGracze[i]) {
	    cout << "zywy";
	    gracze.push_back(new GraczZywy(i));
	} else {
	    cout << "bot";
	    gracze.push_back(new GraczBotProsty(i));
	}
	gracze.back()->setPlansza(plansza);
	cout << endl;
    }

    cout << endl;

    int ktoWistuje = 0;
    for (unsigned i = 0; i < liczbyKart.size(); i++) {
	grajRozdanie(liczbyKart[i], ktoWistuje);
	ktoWistuje = plansza->kolejnyGracz(ktoWistuje);
    }
    plansza->wypiszWynikiGry();
    cout << "KONIEC" << endl;
}

void Gra::grajRozdanie(int liczbaKart, int ktoWistuje) {

    cout << "Rozdanie (" << liczbaKart
	    << " kart, wist: " << ktoWistuje << ")" << endl;

    plansza->setLiczbaKart(liczbaKart);
    plansza->setKtoWistuje(ktoWistuje);
    rozdajKarty(liczbaKart);
    pobierzDeklaracje();
    for (int i = 0; i < liczbaKart; i++) {
	grajLewe();
    }
    plansza->podsumujRozdanie();
}

void Gra::grajLewe() {
    // cerr << "Gra.grajLewe()" << endl;

    for (int i = 0; i < liczbaGraczy; i++) {
	gracze[plansza->ktoWyklada()]->grajKarte();
    }
}

void Gra::rozdajKarty(int liczbaKart) {
    // cerr << "Gra.rozdajKarty" << endl;

    Talia talia;
    for (int i = 0; i < liczbaGraczy; i++) {
	gracze[i]->setReka(talia.getKarty(liczbaKart));
    }
}

void Gra::pobierzDeklaracje() {
    cout << "Deklaracje: " << endl;
    for (int i = 0; i < liczbaGraczy; i++) {
	gracze[i]->deklaruj();
    }
}




