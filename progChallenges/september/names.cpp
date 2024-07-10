// names.cpp: Sort by multiple factors

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
    string first;
    string last;
};

int main(int argc, char *argv[]) {
    // O(nlogn)

    vector<Person> people;
    Person         person;

    while (cin >> person.first >> person.last) {
        people.push_back(person);
    }

    sort(people.begin(), people.end(),
        [](const Person &a, const Person &b) {
        if (a.last == b.last) {
            return a.first < b.first;
        } else {
            return a.last < b.last; 
        }
    });

     /* stable_sort(people.begin(), people.end(),
        [](const Person &a, const Person &b) {
            return a.first < b.first; 
    });

    stable_sort(people.begin(), people.end(),
        [](const Person &a, const Person &b) {
            return a.last < b.last; 
    }); */ 

    for (auto p : people) {
        cout << p.first << " " << p.last << endl;
    } 

    return 0;
}