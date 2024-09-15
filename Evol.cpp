#include "Evol.h"
#include "Gene.h"

using namespace std;

void Evol::init() {
    Pos.clear();
}

int Evol::getsurround(pair<int, int> value) {
    return Pos[value];
}

vector<pair<int, int> > Evol::Listliving(const Gen& living) {
    vector<pair<int, int> > ans;

    for (const auto& it : Pos) {
        if(it.second == 3 || (it.second == 2 && living.isliving(it.first))) {
            ans.push_back(pair<int, int> (it.first.first, it.first.second));
        }
    }

    return ans;
}

void Evol::update(pair<int, int> value) {
    Pos[value]++;
}

