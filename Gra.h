#ifndef gra_H_
#define gra_H_

#include <vector>
#include "Gracz.h"
#include "Plansza.h"

class Gra {

public:
	Gra(int liczbaGraczy, std::vector<int>liczbyKart);

private:
	void grajRozdanie(int liczbaKart, int ktoWistuje);
	void pobierzDeklaracje();
	void rozdajKarty(int liczbaKart);
	void grajLewe();
	
	int liczbaGraczy;
	Plansza* plansza;
	std::vector<Gracz*> gracze;
};
#endif
