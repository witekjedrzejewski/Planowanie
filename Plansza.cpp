#include <cassert>

#include "Plansza.h"

using namespace std;

Plansza::Plansza(int liczbaGraczy) : _liczbaGraczy(liczbaGraczy) {
    _stol = vector<Karta > (liczbaGraczy);
    _deklaracje = vector<int>(liczbaGraczy);
    _wziete = vector<int>(liczbaGraczy);
    _punkty = vector<int>(liczbaGraczy, 0);
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

int Plansza::ktoWychodzi() {
    return _ktoWychodzi;
}

int Plansza::kolorWyjscia() {
    return _kolorWyjscia;
}

vector<Karta> Plansza::stol() {
    return _stol;
}

vector<int> Plansza::wziete() {
    return _wziete;
}

vector<Karta> Plansza::ostatniaLewa() {
    return _ostatniaLewa;
}

int Plansza::ktoWyklada() {
    return _ktoWyklada;
}

int Plansza::punktyZa(int wziete, int deklarowane) {
    return wziete + ((wziete == deklarowane) ? _liczbaKart : 0);
}

void Plansza::zeruj(vector<int>& v) {
    fill(v.begin(), v.end(), 0);
}

void Plansza::podsumujRozdanie() {
    cout << "Wyniki (wziete/deklarowane): ";
    for (int i = 0; i < _liczbaGraczy; i++) {
	int punkty = punktyZa(_wziete[i], _deklaracje[i]);
	cout << i << ": " << punkty << "(" << _wziete[i]
		<< "/" << _deklaracje[i] << ") ";
	_punkty[i] += punkty;
    }
    cout << endl;

    zeruj(_wziete);
}

void Plansza::wypiszWynikiGry() {
    cout << "WYNIKI GRY: " << endl;
    for (int i = 0; i < _liczbaGraczy; i++) {
	cout << i << ": " << _punkty[i] << " ";
    }
    cout << endl;
}

void Plansza::dolozKarteOdGracza(Karta k, int nr) {
    assert(nr == _ktoWyklada);
    cout << "-> " << k << " od gracza " << nr << ")" << endl;
    _stol[nr] = k;
    if (nr == _ktoWychodzi) {
	_kolorWyjscia = k.kolor();
    }
    _ktoWyklada = kolejnyGracz(_ktoWyklada);

    if (_ktoWyklada == _ktoWychodzi) {
	zakonczLewe();
    }
}

void Plansza::zakonczLewe() {
    // cerr << "Plansza.zakonczLewe" << endl;

    // zapisanie historii
    _ostatniaLewa = _stol;
    _wychodzilOstatnio = _ktoWychodzi;

    // wylonienie zwyciezcy
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

    czyscStol();
}

void Plansza::czyscStol() {
    //cerr << "Plansza.czyscStol" << endl;

    for (unsigned i = 0; i < _stol.size(); i++) {
	_stol[i] = Karta(); /* TODO pusta karta */
    }
}

int Plansza::kolejnyGracz(int aktualnyGracz) {
    return (aktualnyGracz + 1) % _liczbaGraczy;
}

void Plansza::przyjmijDeklaracje(int d, int nr) {
    _deklaracje[nr] = d;
}