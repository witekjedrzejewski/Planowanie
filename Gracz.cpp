#include <sstream>

#include "Gracz.h"

using namespace std;

Gracz::Gracz(int nr) : nr(nr) { }

void Gracz::deklaruj() {
	int d = wybierzDeklaracje();
	cout << "Gracz " << nr << ": deklaracja " << d << endl;
	plansza->przyjmijDeklaracje(d, nr);
}

void Gracz::grajKarte() {
	cout << "Gracz " << nr << ": grajKarte" << endl;
	int indeks = wybierzIndeksKarty();
	Karta k = reka[indeks];
	plansza->dolozKarteOdGracza(k, nr);
	usunKarteOIndeksie(indeks);
}

void Gracz::setReka(std::vector<Karta> r) {
	reka = r;
}

void Gracz::setPlansza(Plansza* p) {
	plansza = p;
}

string Gracz::wypiszReke() {
	ostringstream oss;
	for (unsigned i = 0; i < reka.size(); i++) {
		oss << reka[i] << " ";
	}
	return oss.str();
}

void Gracz::usunKarteOIndeksie(int i) {
	swap(reka[i], reka[reka.size()-1]);
	reka.pop_back();
}
/*
bool Gracz::kartaPoprawna (Karta k)
{
	int i;
	bool b;
	b=0;
	if((k.wysokosc==0)||(k.kolor==0))
		return 0;
	if(wskPlansza->kolorWyjscia!=-1)
	{
		if(k.kolor!=wskPlansza->kolorWyjscia)
			if(kartyWKolorze[wskPlansza->kolorWyjscia]>0)
				return 0;
	}
	for(i=0; i<=12; i++)
		if((k.kolor==reka[i].kolor)&&(k.wysokosc==reka[i].wysokosc))
			b=1;
	return b;
		
}

void gracz::dodajPunktyZaRozdanie()
{
	cout<<"wykonuje dodajPunktyZaRozdanie"<<endl;
	punkty+=liczbaLew;
	if(liczbaLew==deklaracja)
		punkty+=wskPlansza->liczbaKart;
}

void gracz::zakonczRozdanie()
{
	cout<<"wykonuje zakonczRozdanie"<<endl;
	int i;
	for(i=0; i<=12; i++)
	{
		reka[i].wysokosc=0;
		reka[i].kolor=0;
	}
	deklaracja=0;
	liczbaLew=0;
	for (i=1; i<=4; i++)
		kartyWKolorze[i]=0;
}
*/