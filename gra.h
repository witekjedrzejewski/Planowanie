#ifndef gra_H_
#define gra_H_

#include "gracz.h"
#include "plansza.h"

class gra{
	public:
	int liczbaRozdan;
	int numerRozdania;
	int liczbaKart;
	int ktoDoklada;
	int ktoWistuje;
	plansza *wskPlansza;
	void odpalGre();
	void nastepnepolecenie();
	void rozdajKarty(int i);
	void grajRozdanie(int n);
	void grajLewe ();
	int nastepnyGracz(int i);
	void podajWynikiGry();
	void zakonczRozdanie();
	void licytacja();
	karta losujKarte (bool t[52]);
	int liczbagraczy;
	gracz* gracze[4];
	gra()
	{
		wskPlansza =new plansza;
		wskPlansza->wskGra=this;
	}
};
#endif
