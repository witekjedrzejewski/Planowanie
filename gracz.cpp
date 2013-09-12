#include "gracz.h"
#include "gra.h"
#include "karta.h"
#include "plansza.h"


#include "gracz.h"
#include<iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


void gracz::dajZnacZeDostajeszKarty()
{
	cout<< "gracz nr. "<< numer<< "otrzymuje karty:"<< endl;
}

void gracz::wezKarte(karta k)
{
	char c[2];
	int i;
	i=0;
	while (reka[i].wysokosc!=0)
		i++;
	reka[i]=k;
	kartyWKolorze[k.kolor]++;
	
	jakZapisacTeKarte(k, c);
	cout<< c<<" ";
	
}

void gracz::jakZapisacTeKarte(karta k, char c[2])
{
		switch (k.kolor)
	{
		case 1: c[1]='C'; break;
		case 2: c[1]='D'; break;
		case 3: c[1]='H'; break;
		case 4: c[1]='S'; break;
		
	}
	if (k.wysokosc<=9)
	c[0]=k.wysokosc+48;
	else
	{
		switch (k.wysokosc)
		{
			case 10: c[0]='T'; break;
			case 11: c[0]='J'; break;
			case 12: c[0]='Q'; break;
			case 13: c[0]='K'; break;
			case 14: c[0]='A'; break;
		}
	}
}

void gracz::licytuj()
{
	char c;
	int d;
	cout<< "gracz nr."<< numer<< " licytuj"<<endl;
	cin>>d;
	deklaracja=d;
}

void gracz::doluzKarte()
{
	cout<<"wykonuje doluzKarte"<<endl;
	int i;
	char c[2];
	karta k;
	cout<< "gracz nr."<< numer<< "doluz karte"<< endl;
	cin>>c;
	cout<< "otrzymalem "<<c[0]<<c[1]<<endl;
	k= kartaOZnakach(c[0], c[1]);
	cout<<"czyli inaczej"<<k.wysokosc<<" "<<k.kolor<<endl;
	if (kartaPoprawna(k)==0)
	{
		cout<<"niepoprawna karta, spróbuj jeszcze raz"<<endl;
		doluzKarte();
	}
	else
	{
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
}

karta gracz::kartaOZnakach(char wys, char kol)
{
	karta k;
	k.wysokosc=0;
	k.kolor=0;
	if((wys<=57)&&(wys>=50))
	{
		k.wysokosc=wys-48;
	}
	else
	{
		switch (wys)
		{
			case 'T': k.wysokosc=10; break;
			case 'J': k.wysokosc=11; break;
			case 'Q': k.wysokosc=12; break;
			case 'K': k.wysokosc=13; break;
			case 'A': k.wysokosc=14; break;
		}
	}
	switch (kol)
	{
		case 'C': k.kolor=1; break;
		case 'D': k.kolor=2; break;
		case 'H': k.kolor=3; break;
		case 'S': k.kolor=4; break;
	}
	return k;
}

bool gracz::kartaPoprawna (karta k)
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
