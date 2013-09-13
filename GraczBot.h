#ifndef BOT_GRACZ_H_
#define BOT_GRACZ_H_

#include "Gracz.h"

class GraczBot : public Gracz {
	
public:
	GraczBot(int);
	virtual int wybierzDeklaracje();
	virtual int wybierzIndeksKarty();
};

#endif

