#ifndef GRACZZYWY_H
#define	GRACZZYWY_H

#include "Gracz.h"

class GraczZywy : public Gracz {
public:
	GraczZywy(int);
	virtual int wybierzDeklaracje();
	virtual int wybierzIndeksKarty();
private:

};

#endif	/* GRACZZYWY_H */

