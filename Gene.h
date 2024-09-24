#ifndef GENERATION
#define GENERATION

#include <unordered_set>
#include <vector>
#include <functional>
#include <utility>

using namespace std;

// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        
        // Combine the two hash values
        return 5131830419411ULL * h1 + 3758991985019ULL * h2;  // Bitwise XOR and shift
    }
};

class Gen {
public:
    // Constructor
    //Gen();

    // Member functions
    void init(vector <pair<int, int> > value);
    int gettotal() const;
    bool isliving(pair<int, int> value) const;
    vector <pair<int, int> > getvec() const;

private:
    unordered_set<pair<int, int>, pair_hash> Living;
};

#endif
