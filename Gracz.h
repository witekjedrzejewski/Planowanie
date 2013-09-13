#ifndef gracz_H_
#define gracz_H_

#include <vector>

#include "Karta.h"
#include "Plansza.h"

class Gracz {
	
public:
	Gracz(int nr);
	void setReka(std::vector<Karta> reka);
	void setPlansza(Plansza* plansza);
	
	void deklaruj();
	void grajKarte();
	
	std::string wypiszReke();

protected:
	virtual int wybierzIndeksKarty() = 0;
	virtual int wybierzDeklaracje() = 0;
	void usunKarteOIndeksie(int i);
	
	std::vector<Karta> reka;
	Plansza* plansza;
	int nr;
	
	/*
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
	int numer;*/
};

#endif

