#ifndef gracz_H_
#define gracz_H_

#include <vector>
#include <set>

#include "Karta.h"
#include "Plansza.h"

class Gracz {
	
public:
	Gracz(int nr);
	
	virtual ~Gracz();
	
	virtual void setReka(std::vector<Karta> reka);
	void setPlansza(Plansza* plansza);
	
	void deklaruj();
	void grajKarte();
	
	std::string wypiszReke();

protected:
	
	struct KartyComparator {
		bool operator() (const Karta&, const Karta&) const;
	};
	
	typedef std::set<Karta, KartyComparator> ZestawKart;
	typedef ZestawKart::iterator ItKarta;
	
	virtual ItKarta wybierzKarte() = 0;
	virtual int wybierzDeklaracje() = 0;
	virtual void usunKarte(ItKarta iter);
	bool kartaPoprawna(ItKarta iter);
	virtual bool posiadaKartyWKolorze(int kol);
	
	ZestawKart reka;
	Plansza* plansza;
	int nr;

};

#endif

