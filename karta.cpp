#include "gracz.h"
#include "gra.h"
#include "karta.h"
#include "plansza.h"

#include "karta.h"
#include<iostream>
#include <cstdio>
#include <cstdlib>



karta::karta(int p)
{
	wysokosc=(p%13)+2;
	kolor=(p/13)+1;
}
