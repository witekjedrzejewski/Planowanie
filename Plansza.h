#ifndef PLANSZA_H_
#define PLANSZA_H_

#include <vector>
#include <algorithm>

#include "Karta.h"

class Plansza {
	
public:	
	Plansza(int liczbaGraczy);
	
	/* karty aktualnie lezace na stole */
	std::vector<Karta> stol() const;
	
	/* deklaracje poszczegolnych graczy */
	std::vector<int> deklaracje() const;
	
	/* wyniki punktowe */
	std::vector<int> wyniki() const;
	
	/* ile ugrali w tym rozdaniu poszczegolnie gracze */
	std::vector<int> wziete() const;
	
	/* kto wyszedl, dolozone karty */
	std::pair<int, std::vector<Karta> > ostatniaLewa() const;
	
	/* nr gracza ktory powinien wylozyc pierwszy w aktualnej lewie */
	int ktoWychodzi() const;
	
	/* nr gracza ktory powinien teraz wylozyc karte */
	int ktoWyklada() const;
	
	int liczbaGraczy() const;
	
	/* kolor w ktorym jest wylozona karta */
	int kolorWyjscia() const;
	
	/* przyjmuje karte k od gracza z numerem nr */
	void dolozKarteOdGracza(Karta k, int nr);
	
	/* przyjmuje deklaracje d lew od gracza nr */
	void przyjmijDeklaracje(int d, int nr);
	
	void podsumujRozdanie();
	
	void wypiszWynikiGry();
	
	void setLiczbaKart(int l);
	
	void setKtoWistuje(int w);
	
	/* nr gracza po lewej od aktualnego */
	int kolejnyGracz(int aktualnyGracz);
	
private:
	void zakonczLewe();
	void czyscStol();
	int punktyZa(int wziete, int deklarowane);
	
	/* wypelnia v zerami */
	static void zeruj(std::vector<int>& v);
	
	int _liczbaGraczy;
	char _kolorWyjscia;
	int _ktoWyklada;
	int _nrLewy;
	int _liczbaKart;
	int _ktoWistuje;
	int _ktoWychodzi;
	
	std::vector<int> _deklaracje;
	std::vector<Karta> _stol;
	std::vector<int> _wziete;
	std::vector<int> _punkty;
	
	int _wychodzilOstatnio;
	std::vector<Karta> _ostatniaLewa;
};

#endif
