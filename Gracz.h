#ifndef gracz_H_
#define gracz_H_

#include <vector>

#include "Karta.h"
#include "Plansza.h"

class Gracz {
public:
    Gracz(int nr);

    virtual ~Gracz();

    virtual void setReka(std::vector<Karta> reka);
    void setPlansza(Plansza* plansza);

    void deklaruj();
    void grajKarte();

    std::string wypiszReke();

protected:

    virtual int numerKarty(Karta k) const;
    virtual Karta kartaONumerze(int nrKarty) const;
    virtual int wybierzNumerKarty() = 0;
    virtual int wybierzDeklaracje() = 0;
    virtual void usunKarteONumerze(int nrKarty);
    virtual bool kartaONumerzePoprawna(int i) const;
    virtual bool posiadaKartyWKolorze(int kol) const;

    std::vector<Karta> reka;
    Plansza* plansza;
    int nr;
};

#endif

