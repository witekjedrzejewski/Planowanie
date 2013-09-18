#include "GraczBot.h"
using namespace std;

GraczBot::GraczBot(int nr) : Gracz(nr) {
};

GraczBot::~GraczBot() {
    
}

int GraczBot::wybierzNumerKarty() {
    Karta k = wybierzKarte();
    return numerKarty(k);
}