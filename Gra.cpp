#include <iostream>

#include "Gra.h"
#include "Talia.h"
#include "GraczZywy.h"

using namespace std;

Gra::Gra(int g, vector<int> liczbyKart) : liczbaGraczy(g) {
	
	cout << "gra(" << g << ")" <<endl;
	
	plansza = new Plansza(liczbaGraczy);
	cout << "plansza ready" << endl;
	for (int i = 0; i < liczbaGraczy; i++) {
		gracze.push_back(new GraczZywy(i));
		gracze[i]->setPlansza(plansza);
	}
	
	int ktoWistuje = 0;
	for (unsigned i = 0; i < liczbyKart.size(); i++) {
		grajRozdanie(liczbyKart[i], ktoWistuje);
		ktoWistuje = plansza->kolejnyGracz(ktoWistuje);
	}
	cout << "KONIEC" << endl;
}

void Gra::grajRozdanie(int liczbaKart, int ktoWistuje) {

	cout<<"Gra.grajRozdanie("<< liczbaKart 
		<< " kart, wist: " << ktoWistuje << ")" << endl;
	
	plansza->setLiczbaKart(liczbaKart);
	plansza->setKtoWistuje(ktoWistuje);
	rozdajKarty(liczbaKart);
	pobierzDeklaracje();
	for (int i = 0; i < liczbaKart; i++) {
		grajLewe();
	}
}

void Gra::grajLewe()
{
	cout << "Gra.grajLewe()" << endl;
	for (int i = 0; i < liczbaGraczy; i++) {
		gracze[plansza->ktoWyklada()]->grajKarte();
	}
}

void Gra::rozdajKarty(int liczbaKart)
{
	cout << "Gra.rozdajKarty" << endl;
	Talia talia;
	for (int i = 0; i < liczbaGraczy; i++) {
		gracze[i]->setReka(talia.getKarty(liczbaKart));
	}
}

void Gra::pobierzDeklaracje()
{
	cout << "Gra.pobierzDeklaracje" << endl;
	for (int i = 0; i < liczbaGraczy; i++) {
		gracze[i]->deklaruj();
	}
}




