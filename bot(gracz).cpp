#ifndef gracz_H_
#define gracz_H_


#include "gracz.h"
#include "gra.h"
#include "karta.h"
#include "plansza.h"

#include "bot(gracz).h"
#include<iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void bot::licytuj()
{
	deklaracja=0;
	cout<<"gracz nr."<<numer<<" deklaruje "<< deklaracja<< " lew"<<endl;
}

void bot::doluzKarte()
{
	char c[2];
	karta k;
	int i;
	if(wskPlansza->kolorWyjscia=-1)
	{
		i=0;
		while(reka[i].kolor==0)
			i++;
		k=reka[i];
	}
	else
	{
		i=0;
		while((i<=12)&&(reka[i].kolor!=wskPlansza->kolorWyjscia))
			i++;
		if(reka[i].kolor==wskPlansza->kolorWyjscia)
			k=reka[i];
		else
		{
			while(reka[i].kolor==0)
			i++;
			k=reka[i];
		}
	}
	jakZapisacTeKarte(k, c);
	cout<<"gracz nr."<< numer<<" doklada "<<c<<endl;
	
	wskPlansza->doluzKarteOdGracza(k, numer);	
	i=0;
	while ((reka[i].kolor!=k.kolor)||(reka[i].wysokosc!=k.wysokosc))
	{
		i++;
	}
	reka[i].wysokosc=0;
	reka[i].kolor=0;
	kartyWKolorze[k.kolor]--;
}


#endif
