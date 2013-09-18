#ifndef BOT_GRACZ_H_
#define BOT_GRACZ_H_

#include "Gracz.h"

class GraczBot : public Gracz {
public:
    GraczBot(int);
    virtual ~GraczBot();
    virtual int wybierzNumerKarty();

    virtual Karta wybierzKarte() = 0;
};

#endif

