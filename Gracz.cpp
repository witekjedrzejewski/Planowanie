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
	
	ItKarta iter;
	
	if (reka.size() == 1) { // specjalny przypadek
		iter = reka.begin();
	} else {
		iter = wybierzKarte();
		assert(kartaPoprawna(iter));
	}
	
	plansza->dolozKarteOdGracza(*iter, nr);
	usunKarte(iter);
}

void Gracz::setReka(std::vector<Karta> r) {
	reka = ZestawKart(r.begin(), r.end());
}

void Gracz::setPlansza(Plansza* p) {
	plansza = p;
}

string Gracz::wypiszReke() {
	ostringstream oss;
	for (ItKarta it = reka.begin(); it != reka.end(); it++) {
		oss << *it << " ";
	}
	return oss.str();
}

void Gracz::usunKarte(ItKarta iter) {
	reka.erase(iter);
}

bool Gracz::kartaPoprawna (ItKarta iter)
{
	if (iter == reka.end()) {
		cerr << "nie znaleziona" << endl;
		return false;
	}
	
	int wychodzi = plansza->ktoWychodzi();
	if (nr == wychodzi)
		return true; // my wykladamy, wiec dowolna karta
	
	Karta k = *iter;
	int kolWyjscia = plansza->kolorWyjscia();
	if (k.kolor() == kolWyjscia)
		return true; // dolozone do koloru
	
	return !posiadaKartyWKolorze(kolWyjscia);
}

bool Gracz::posiadaKartyWKolorze(int kol) {
	for (ItKarta it = reka.begin(); it != reka.end(); it++) {
		if (it->kolor() == kol)
			return true;
	}
	return false;
}

bool Gracz::KartyComparator::operator() (const Karta& a, const Karta& b) const {
	if (a.kolor() == b.kolor())
		return a.wysokosc() > b.wysokosc();
	return a.kolor() < b.kolor();
}