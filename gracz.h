#ifndef gracz_H_
#define gracz_H_

#include "gra.h"
#include "karta.h"
#include "plansza.h"


class gracz{
	public:
	karta reka[13];
	int liczbaLew;
	int deklaracja;
	int kartyWKolorze[5];
	int punkty;
	plansza *wskPlansza;
	void dajZnacZeDostajeszKarty();
	void wezKarte (karta k);
	virtual void licytuj ();
	virtual void doluzKarte ();
	void dajZnacZeRozdajesz();
	void wyswietlStol();
	void wyswietlKarty();
	karta kartaOZnakach(char wys, char kol);
	void jakZapisacTeKarte(karta k, char c[2]);
	bool kartaPoprawna(karta k);
	void dodajPunktyZaRozdanie();
	void zakonczRozdanie();
	int numer;
	gracz()
	{
		punkty=0;
		liczbaLew=0;
	}
};

#endif

