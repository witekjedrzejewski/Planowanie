#include <vector>
#include <algorithm>
class Karta;

class Plansza{
	public:
	
	std::vector<Karta> getStol();
	std::vector<int> getDeklaracje();
	std::vector<int> getWyniki();
	std::vector<int> getWziete();
	/* kto wyszed³, do³o¿one karty */
	std::pair<int, std::vector<Karta> > ostatniaLewa();
	int getKtoWychodzi();
	int getLiczbaGraczy();
	void doluzKarteOdGracza(Karta k, int i);
};
