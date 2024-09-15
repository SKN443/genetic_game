#include <bits/stdc++.h>
#include <bitset>
#include <algorithm> // for std::shuffle
#include <random>    // for std::random_device and std::mt19937

using namespace std;

//vector <bitset<9> > arr;

vector <int > arr;

int main() {
    freopen("output.txt", "w", stdout);

    for(int i=0; i < 512; i++)
        arr.push_back(i);

    // Create a random number generator
    random_device rd; // Obtain a random number from hardware
    for(int i = 43; i < 59; i++) {
    default_random_engine g(rd());  // Seed the generator

    // Shuffle the array
    shuffle(arr.begin(), arr.end(), g);

    cout <<"{";
    for(int i=0; i < 512; i++) {
        cout <<"" <<arr[i] << ",";
    }
    cout <<"}, \n";
    }

    return 0;
}
