#include "GraczBot.h"
using namespace std;

GraczBot::GraczBot(int nr) : Gracz(nr) { };

int GraczBot::wybierzDeklaracje() {
	int d = reka.size() / plansza->liczbaGraczy();
	cerr << "Gracz " << nr << " deklaruje " << d 
					<< " (" << wypiszReke() << ")" << endl;
	return d;
}

int GraczBot::wybierzIndeksKarty() {
	int idx = 0;
	while(!kartaOIndeksiePoprawna(idx)) {
		idx++;
	}
	cerr << "Gracz " << nr << " wybiera " << reka[idx]
					<< " ( z " << wypiszReke() << ")" << endl;
	return idx;
}