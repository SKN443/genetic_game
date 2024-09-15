#include "Gene.h"

using namespace std;

void Gen::init(vector <pair<int, int> > value) {
    Living.clear();
    for(const auto& it : value)
        Living.insert(it);
}

int Gen::gettotal() const {
    return Living.size();
}

bool Gen::isliving(pair<int, int> value) const{
    return (Living.find(value) != Living.end());
}

vector <pair<int, int> > Gen::getvec() const {
    vector <pair<int, int> > ans;
    for (const auto&it : Living)
        ans.push_back(it);

    return ans;
}
