
#include <iostream>
#include <algorithm>

#include "GraczZywy.h"

using namespace std;

GraczZywy::GraczZywy(int nr) :Gracz(nr) { };

int GraczZywy::wybierzDeklaracje() {
	cout << "gracz nr." << nr << ": WYBIERZ DEKLARACJE" << endl;
	cout << "Twoja reka: " << wypiszReke() << endl;
	int d;
	cin >> d;
	return d;
}

Gracz::ItKarta GraczZywy::wczytajKarte() {

	string opis;
	
	cin >> opis;
	Karta k(opis);
	return reka.find(k);
}

Gracz::ItKarta GraczZywy::wybierzKarte() {
	cout << "gracz nr." << nr << ": WPISZ KARTE" << endl;
	cout << "Twoja reka: " << wypiszReke() << endl;
	
	ItKarta iter = wczytajKarte();
	
	while(!kartaPoprawna(iter)) {
		cout << "ZLE! Niedozwolony ruch" << endl;
		iter = wczytajKarte();
	}
	
	cout<< "wybrano " << *iter << endl;
	return iter;
}