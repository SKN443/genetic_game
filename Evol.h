#ifndef EVOL
#define EVOL

#include "Gene.h"
#include <unordered_map>
#include <utility>
#include <vector>
#include <functional>

using namespace std;

// Custom hash function for pair<int, int>
struct pair_hash1 {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        
        // Combine the two hash values
        return 5131830419411ULL * h1 + 3758991985019ULL * h2;  // Bitwise XOR and shift
    }
};

class Evol {
public:
    // Member functions
    void init();
    int getsurround(pair<int, int> value);
    vector<pair<int, int> > Listliving(const Gen& living);
    void update(pair<int, int> value);

private:
    unordered_map<pair <int, int>, int, pair_hash1> Pos;
};

#endif
