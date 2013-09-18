#ifndef GRACZBOTPROSTY_H
#define	GRACZBOTPROSTY_H

#include "GraczBot.h"

class GraczBotProsty : public GraczBot {
public:
    GraczBotProsty(int);
    virtual ~GraczBotProsty();
    
    virtual void setReka(std::vector<Karta> r);
    virtual int wybierzDeklaracje();
    
protected:
    virtual Karta wybierzKarte();
    virtual void usunKarteONumerze(int nrKarty);
    
    // jakies ustrojstwa tego bota
    void odkreslKarte(Karta k);
    bool t[5][16]; // karty ktorych nie moga miec inni gracze
};

#endif	/* GRACZBOTPROSTY_H */

