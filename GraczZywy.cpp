
#include <iostream>
#include <algorithm>

#include "GraczZywy.h"

using namespace std;

GraczZywy::GraczZywy(int nr) :Gracz(nr) { };

int GraczZywy::wybierzDeklaracje() {
	return reka.size() / plansza->liczbaGraczy();
}

int GraczZywy::wybierzIndeksKarty() {
	cout << "gracz nr." << nr << ": WYBIERZ INDEKS KARTY" << endl;
	cout << "Twoja reka: " << wypiszReke() << endl;
	int indeks;
	cin >> indeks;
	indeks = min(indeks, (int)reka.size() - 1);
	cout<< "wybrano " << reka[indeks] << endl;
	return indeks;
}