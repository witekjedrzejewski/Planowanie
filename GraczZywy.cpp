
#include <iostream>
#include <algorithm>

#include "GraczZywy.h"

using namespace std;

GraczZywy::GraczZywy(int nr) : Gracz(nr) {
};

int GraczZywy::wybierzDeklaracje() {
    cout << "gracz nr." << nr << ": WYBIERZ DEKLARACJE" << endl;
    cout << "Twoja reka: " << wypiszReke() << endl;
    int d;
    cin >> d;
    return d;
}

int GraczZywy::wybierzNumerKarty() {
    cout << "gracz nr." << nr << ": WYBIERZ INDEKS KARTY" << endl;
    cout << "Twoja reka: " << wypiszReke() << endl;
    int indeks;
    cin >> indeks;

    while (!kartaONumerzePoprawna(indeks)) {
	cout << "ZLE! " << reka[indeks] << " nie jest poprawna karta" << endl;
	cin >> indeks;
    }

    cout << "wybrano " << reka[indeks] << endl;
    return indeks;
}