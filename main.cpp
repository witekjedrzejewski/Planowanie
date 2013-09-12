#include "gracz.h"
#include "gra.h"
#include "karta.h"
#include "plansza.h"

#include<iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;



int main ()
{
	gra G;
	G.liczbaRozdan=2;
	G.ktoWistuje=0;
	G.liczbagraczy=4;
	G.numerRozdania=1;
	
	G.odpalGre();
}
