#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector> 

using namespace std;

void read_numbers(vector<int> &v) {
    int number;
    while( cin >> number) {
        numbers.push_back(number);
    }
}

int count_duplicates(vector<int> &v) {
    // Time: O(nlogn)
    //Space: O(1)
    int total = 0;
    //v.begin() and v.end are called iterators but they are essentially pointers to the beginning and ends of the vector
    sort(v.begin(), v.end()) // O(nlogn)
    for (size_t i = 1; i < v.size(); i++) { //O(n)
        if (v[i] == v[i-1]) {
            total++;
        }
    }

    return total;
}

int count_duplicates(vector<int> &v) {
    // Time: O(n)
    //Space: O(n)
    int total = 0;
    //hash table (ordered set is a RBTree)
    unordered_set<int> seen;

    for (auto n : v) {           //O(n)
        if(seen.count(n)) {      //O(1)
            total++;
        } else {
            seen.insert(n);      //O(1)
        }
    }

    return total;
}


int main(int argc, char *argv[]) {
    vector<int> numbers;

    read_numbers(numbers);

    auto total = count_duplicates(numbers);

    cout << total << endl;
}