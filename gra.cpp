#include "gracz.h"
#include "gra.h"
#include "karta.h"
#include "plansza.h"

#include "gra.h"
#include <cstdlib>
#include <ctime>
#include<iostream>
#include <cstdio>

#include "gracz.h"
#include "gra.h"
#include "karta.h"
#include "plansza.h"

using namespace std;

void gra::odpalGre()
{
	cout<<"wykonuje odpalGre"<<endl;
	srand( time(NULL));
	int a, i;
	cout<< "ilu ma byæ graczy?"<< endl;
	cin>>a;
	for (i=0; i<=a-1; i++)
	{
		gracze[i]= new gracz;
	}
	for (i=a; i<=3; i++)
	{
		gracze[i]=new bot;
	}
	for(i=0; i<=3; i++)
	{
		gracze[i]->numer=i;
		wskPlansza->gracze[i]=gracze[i];
		gracze[i]->wskPlansza=wskPlansza;
		gracze[i]->wskGra=this;
	}
	for (i=1; i<=liczbaRozdan; i++)
	{
		grajRozdanie (i);
	}
	podajWynikiGry();
}




void gra::grajRozdanie(int i)
{
	cout<<"wykonuje grajRozdanie"<<endl;
	int j, l;
	ktoDoklada=ktoWistuje;
	liczbaKart=numerRozdania;
	wskPlansza->czyscStol();
	for(j=0; j<=3; j++)
	{
		for(l=0; l<=4; l++)
		{
			gracze[j]->kartyWKolorze[l]=0;
		}	
	}
	rozdajKarty(liczbaKart);
	licytacja();
	for (j=1; j<=liczbaKart; j++)
	{
		grajLewe();
	}
	zakonczRozdanie();
}

void gra::grajLewe()
{
	cout<<"wykonuje grajLewe"<<endl;
	int a;
	for (a=0; a<=3; a++)
	{
		gracze[ktoDoklada]->doluzKarte();
		ktoDoklada=nastepnyGracz(ktoDoklada);
	}
	
}

int gra::nastepnyGracz(int i)
{
	if (i==3)
		return 0;
	else
		return (i+1);
}

karta gra::losujKarte(bool t[52])
{
	int i, j, l, m, p;
	karta k;
	j=0;
	for (i=0; i<=51; i++)
	{
		if(t[i]==1)
		j++;
	}
	l= (rand()%j) +1;
	p=-1;
	m=0;
	while (m<l)
	{
		p++;
		if (t[p]==1)
		m++;
	}
	t[p]=0;
	return (jakaKarteReprezentujeLiczba (p));
	
}

void gra::rozdajKarty(int i)
{
	cout<<"wykonuje rozdajKarty"<<endl;
	int j, l;
	karta k;
	bool t[52];
	for(j=0; j<=51; j++)
		t[j]= 1;
	for(j=0; j<=3; j++)
	{
		gracze[j]->dajZnacZeDostajeszKarty();
		for (l=1; l<=i; l++)
		{
			k=losujKarte(t);
			gracze[j]->wezKarte(k);
		}
		cout<<endl;
	}
}



void gra::licytacja()
{
	cout<<"wykonuje licytacja"<<endl;
	int a;
	for (a=0; a<=3; a++)
	{
		gracze[a]->licytuj();
	}
}

void gra::zakonczRozdanie()
{
	cout<<"wykonuje zakonczRozdanie"<<endl;
	int i;

	for(i=0; i<=3; i++)
	{
		gracze[i]->dodajPunktyZaRozdanie();
		gracze[i]->zakonczRozdanie();
	}
	ktoWistuje=nastepnyGracz(ktoWistuje);
	numerRozdania++;
}

void gra::podajWynikiGry()
{
	cout<<"wykonuje podajWynikiGry"<<endl;
	int i;
	cout<< "wyniki gry" << endl;
	for(i=0; i<=3; i++)
	{
		cout<< "gracz nr." << i <<" zdobyl" << gracze[i]->punkty << " punktow" << endl;
	}
}




