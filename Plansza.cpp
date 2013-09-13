#include <cassert>

#include "Plansza.h"

using namespace std;

Plansza::Plansza(int liczbaGraczy) : _liczbaGraczy(liczbaGraczy) {
	_stol = vector<Karta>(liczbaGraczy);
	_deklaracje = vector<int>(liczbaGraczy);
	_wziete = vector<int>(liczbaGraczy);
}

void Plansza::setLiczbaKart(int l) {
	_liczbaKart = l;
}

void Plansza::setKtoWistuje(int w) {
	_ktoWistuje = _ktoWychodzi = _ktoWyklada = w;
}

int Plansza::liczbaGraczy() {
	return _liczbaGraczy;
}

vector<Karta> Plansza::stol() {
	return _stol;
}

vector<int> Plansza::wziete() {
	return _wziete;
}

pair<int, vector<Karta> > Plansza::ostatniaLewa() {
	return make_pair(wzialOstatnia, _ostatniaLewa);
}

int Plansza::ktoWyklada() {
	return _ktoWyklada;
}

void Plansza::dolozKarteOdGracza(Karta k, int nr) {
	assert(nr == _ktoWyklada);
	cout << "Plansza.dolozKarte(" << k << " od gracza " << nr << ")" << endl;
	_stol[nr] = k;
	if (nr == _ktoWychodzi) {
		_kolorWyjscia=k.kolor();
	}
	_ktoWyklada = kolejnyGracz(_ktoWyklada);
	
	if (_ktoWyklada == _ktoWychodzi) {
		zakonczLewe();
	}
}

void Plansza::zakonczLewe() {
	cout << "Plansza.zakonczLewe" << endl;
	int wygrany = _ktoWychodzi;
	int i = _ktoWychodzi;
	do {
		i = kolejnyGracz(i);
		if (_stol[i].lepszaNizWychodzaca(_stol[wygrany])) {
			wygrany = i;
		}
	} while (i != _ktoWychodzi);
	
	cout << "Lewe wygrywa " << wygrany << endl;
	_ktoWychodzi = _ktoWyklada = wygrany;
	_wziete[wygrany]++;
	
	_ostatniaLewa = _stol;
	wzialOstatnia = wygrany;
	
	czyscStol();
}

void Plansza::czyscStol() {
	cout << "Plansza.czyscStol" << endl;
	for (unsigned i = 0; i < _stol.size(); i++) {
		_stol[i] = Karta();
	}
}

int Plansza::kolejnyGracz(int aktualnyGracz) {
	return (aktualnyGracz + 1) % _liczbaGraczy;
}

void Plansza::przyjmijDeklaracje(int d, int nr) {
	_deklaracje[nr] = d;
}