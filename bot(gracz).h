#ifndef BOT_GRACZ_H_
#define BOT_GRACZ_H_

#include "gracz.h"
#include "gra.h"
#include "karta.h"
#include "plansza.h"


class bot: public gracz{
	
	public:
	void dajZnacZeDostajeszKarty();
	void wezKarte (karta k);
	virtual void licytuj ();
	void doluzKarte ();
	void dajZnacZeRozdajesz();
	void wyswietlStol();
	void wyswietlKarty();
	karta kartaOZnakach(char wys, char kol);
	bool kartaPoprawna(karta k);
	void dodajPunktyZaRozdanie();
	void zakonczRozdanie();
};

#endif

