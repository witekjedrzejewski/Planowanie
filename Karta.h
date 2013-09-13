#ifndef karta_H_
#define karta_H_

#include <iostream>

class Karta {

public:
	int kolor();
	int wysokosc();
	Karta();
	Karta(int p);
	Karta(const Karta& k);
	Karta& operator=(const Karta& k);
	
	bool operator==(const Karta& k);
	
	/* czy przebijamy karte k, jesli ktos wyszedl w karte k? */
	bool lepszaNizWychodzaca(const Karta& k);
	
	friend std::ostream& operator<<(std::ostream&, const Karta&);
	
private:
	int _kolor;
	int _wysokosc;
	static const char kolory[5];
	static const char figury[5];
	static const int ATU;
};

#endif
