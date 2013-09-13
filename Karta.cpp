#include <iostream>

#include "Karta.h"

const int Karta::ATU = 1;

const char Karta::kolory[] = {'0', 'C', 'D', 'H', 'S'};
const char Karta::figury[] = {'T', 'J', 'Q', 'K', 'A'};

Karta::Karta() : _kolor(0), _wysokosc(0) { }

Karta::Karta(int p) {
	_wysokosc = (p % 13) +2;
	_kolor = (p/13) + 1;
}

Karta::Karta(const Karta& k) 
	: _kolor(k._kolor), _wysokosc(k._wysokosc) { }

Karta& Karta::operator=(const Karta& k)
{
    if (&k != this) {
			_wysokosc = k._wysokosc;
			_kolor = k._kolor;
		}
		return *this;
}

bool Karta::operator==(const Karta& k) {
	return _kolor == k._kolor && _wysokosc == k._wysokosc;
}

int Karta::kolor() {
	return _kolor;
}

int Karta::wysokosc() {
	return _wysokosc;
}

bool Karta::lepszaNizWychodzaca(const Karta &k) {
	if (_kolor == k._kolor) {
		return _wysokosc > k._wysokosc;
	}
	return _kolor == ATU;
}

std::ostream& operator<<(std::ostream& os, const Karta& k) {
	if (k._wysokosc <= 9) {
		os << k._wysokosc;
	} else {
		os << Karta::figury[k._wysokosc - 10];
	}
	
	os << Karta::kolory[k._kolor];
	return os;
}