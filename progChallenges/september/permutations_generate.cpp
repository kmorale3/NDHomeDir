// permutations_backtracking.cpp

#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

// Functions

void permutations(string &p, set<char> &c) {
    // p: current permuation
    // c: set of candidates (sets in c++ are default ordered)
    if (c.empty()) {
        for (auto e : p) { cout << e;} cout << endl;
    } else {
        auto n = c;
        for (auto e : n) {
            p.push_back(e); //add element to permutation
            c.erase(e);     //remove element from candidates
            permutations(p,c);

            // backtrack
            c.insert(e);
            p.pop_back();
        }
    }
}

// Main execution

int main(int argc, char *argv[]) {
    string    p = "";
    set<char> c = {'A', 'B', 'C'};

    permutations(p, c);
    return 0;
}