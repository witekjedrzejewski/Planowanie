#include <iostream>
#include <vector>

#include "Gra.h"

using namespace std;

int main() {
    vector<bool> g(2, 0);
    g[0] = 1;
    vector<int> r(2, 2);
    Gra gra(g, r);
    gra.uruchom();
}
