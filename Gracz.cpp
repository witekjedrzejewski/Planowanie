#include <sstream>
#include <cassert>

#include "Gracz.h"

using namespace std;

Gracz::Gracz(int nr) : nr(nr) { }

Gracz::~Gracz() { }

void Gracz::deklaruj() {
	int d = wybierzDeklaracje();
	
	cout << "Gracz " << nr << ": deklaracja " << d << endl;
	
	assert(d >= 0 && d <= (int)reka.size());
					
	plansza->przyjmijDeklaracje(d, nr);
}

void Gracz::grajKarte() {
	cout << "Gracz " << nr << ": grajKarte" << endl;
	
	int indeks;
	
	if (reka.size() == 1) { // specjalny przypadek
		indeks = 0;
	} else {
		indeks = wybierzIndeksKarty();
		assert(kartaOIndeksiePoprawna(indeks));
	}
	
	Karta k = reka[indeks];
	plansza->dolozKarteOdGracza(k, nr);
	usunKarteOIndeksie(indeks);
}

void Gracz::setReka(std::vector<Karta> r) {
	reka = r;
}

void Gracz::setPlansza(Plansza* p) {
	plansza = p;
}

string Gracz::wypiszReke() {
	ostringstream oss;
	for (unsigned i = 0; i < reka.size(); i++) {
		oss << reka[i] << " ";
	}
	return oss.str();
}

void Gracz::usunKarteOIndeksie(int i) {
	swap(reka[i], reka[reka.size()-1]);
	reka.pop_back();
}

bool Gracz::kartaOIndeksiePoprawna (int i)
{
	if (i >= (int)reka.size() || i < 0)
		return false; // nie ma takiego indeksu

	int wychodzi = plansza->ktoWychodzi();
	if (nr == wychodzi)
		return true; // my wykladamy, wiec dowolna karta
	
	Karta k = reka[i];
	int kolWyjscia = plansza->kolorWyjscia();
	if (k.kolor() == kolWyjscia)
		return true; // dolozone do koloru
	
	return !posiadaKartyWKolorze(kolWyjscia);
}

bool Gracz::posiadaKartyWKolorze(int kol) {
	for (unsigned i = 0; i < reka.size(); i++) {
		if (reka[i].kolor() == kol)
			return true;
	}
	return false;
}