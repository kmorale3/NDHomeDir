// subsets.cpp

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

size_t subsets( vector <int> &s, vector<int> &d, size_t k) {
    // s: current subset we are building
    // d: set of elements to consider
    // k: current element (candidate)

    if (k == d.size()) {                     // Base Case: we run out of candidates
        auto sum = accumulate(s.begin(), s.end(), 0);
        return(sum % 3 == 0) ? 1 : 0;
    } else {                                 // Recursive: (a) take (b) skip
        auto count1 = subsets(s, d, k + 1);  // skipping

        s.push_back(d[k]);                   // taking
        auto count2 = subsets(s, d, k + 1);
        s.pop_back();                        // backtracking
        return count1 + count2;
    }

}

int main(int argc, char *argv[]) {
    vector<int> subset;
    vector<int> data  = {0,1,2,3,4,5,6,7,8,9};
    size_t      count = 0;
    cout << subsets(subset, data, 0) << endl;
    return 0;
}