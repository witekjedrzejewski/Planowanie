#ifndef PLANSZA_H_
#define PLANSZA_H_

#include <vector>
#include <algorithm>

#include "Karta.h"

class Plansza {
	
public:	
	Plansza(int liczbaGraczy);
	
	/* karty aktualnie lezace na stole */
	std::vector<Karta> stol();
	
	std::vector<int> deklaracje();
	//std::vector<int> wyniki();
	
	/* ile ugrali w tym rozdaniu poszczegolnie gracze */
	std::vector<int> wziete();
	
	/* kto wyszedl, dolozone karty */
	std::pair<int, std::vector<Karta> > ostatniaLewa();
	
	int ktoWyklada();
	int liczbaGraczy();
	void dolozKarteOdGracza(Karta k, int nr);
	void przyjmijDeklaracje(int d, int nr);
	void setLiczbaKart(int l);
	void setKtoWistuje(int w);
	
	int kolejnyGracz(int aktualnyGracz);
	
private:
	void zakonczLewe();
	void czyscStol();
	
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
	
	int wzialOstatnia;
	std::vector<Karta> _ostatniaLewa;
};

#endif
