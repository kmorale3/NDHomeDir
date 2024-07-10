// anagrams.cpp: Sort by multiple factors

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_palindromic(string &s) {
    //time      O(n)
    //space     O(1)
    unordered_map<char, size_t> counts;

    for (auto c : s) {
        counts[tolower(c)]++;
    }
    size_t odds = 0;
    for (auto p : counts) {
        odds += p.second % 2;
    }
    return odds <= 1;
}

int main(int argc, char *argv[]) {

}