#include "gracz.h"
#include "gra.h"
#include "karta.h"
#include "plansza.h"

#include "plansza.h"
#include<iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


void plansza::doluzKarteOdGracza(karta k, int i)
{
	int d;
	cout<<"wykonuje doluzKarteOdGracza"<<endl;
	stol[i]=k;
	if (stol[poprzedniGracz(i)].kolor==0)
		kolorWyjscia=k.kolor;
	d=nastepnyGracz(i);
	if (stol[wskGra->nastepnyGracz(i)].kolor!=0)
		zakonczLewe();
}

int plansza::poprzedniGracz(int i)
{
	if (i==0)
		return 3;
	else
		return (i-1); 
}

void plansza::zakonczLewe()
{
	cout<<"wykonuje zakonczLewe"<<endl;
	int wygrany, i, najwyzsza;
	wygrany=-1;
	najwyzsza=0;
	for(i=0; i<=3; i++)
	{
		if(stol[i].kolor==1)
			if(stol[i].wysokosc>najwyzsza)
			{
				wygrany=i;
				najwyzsza=stol[i].wysokosc;
			}
	}
	if(wygrany!=-1)
	{
		leweWygrywa(wygrany);
		czyscStol();
		return;
	}
	else
	{
		for(i=0; i<=3; i++)
		{
			if (stol[i].kolor=kolorWyjscia)
				if(stol[i].wysokosc>najwyzsza)
				{
					wygrany=i;
					najwyzsza=stol[i].wysokosc;
				}
		}
		leweWygrywa(wygrany);
		czyscStol();
		return;
	}
	cout<<"blad 'zakonczLewe'";
}

void plansza::leweWygrywa(int i)
{
	cout<<"wykonuje leweWygrywa"<<endl;
	gracze[i]->liczbaLew++;
	wskGra->ktoDoklada=i;
}

void plansza::czyscStol()
{
	cout<<"wykonuje czyscStol"<<endl;
	int i;
	kolorWyjscia=-1;
	for(i=0; i<=3; i++)
		{
			stol[i].wysokosc=0;
			stol[i].kolor=0;
		}
}

int plansza::nastepnyGracz(int i)
{

	if (i==3)
		return 0;
	else
		return (i+1);
}


