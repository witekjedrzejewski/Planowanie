#ifndef GRACZZYWY_H
#define	GRACZZYWY_H

#include "Gracz.h"

class GraczZywy : public Gracz {
public:
	GraczZywy(int);
protected:		
	virtual int wybierzDeklaracje();
	virtual ItKarta wybierzKarte();
private:
	ItKarta wczytajKarte();
};

#endif	/* GRACZZYWY_H */

