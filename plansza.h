#ifndef plansza_H_
#define plansza_H_

#include "karta.h"

class gra;
class gracz;

class plansza{
	public:
	karta stol[4];
	int liczbaKart;
	gracz* gracze[4];
	int kolorWyjscia;
	void doluzKarteOdGracza(karta k, int i);
	int poprzedniGracz(int i);
	void zakonczLewe();
	void leweWygrywa(int i);
	void czyscStol();
	int nastepnyGracz(int i);
};
#endif
