#include <vector>
#include <algorithm>
class Karta;

class Plansza{
	public:
	
	std::vector<Karta> stol();
	std::vector<int> deklaracje();
	std::vector<int> wyniki();
	std::vector<int> wziete();
	/* kto wyszed³, do³o¿one karty */
	std::pair<int, std::vector<Karta> > ostatniaLewa();
	int ktoWychodzi();
	
	void doluzKarteOdGracza(Karta k, int i);
};
