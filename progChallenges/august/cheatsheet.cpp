#include <iostream>
#include <vector> 

using namespace std;
//using std::vector (if you dont want to use namespace std)
//typedef std::vector<int> Array

int main(int argc, char *argv[]) {
    //create dynamic array
    vector<int> v = {1,2,3};
    //apend to the back
    v.push_back(4);
    //prepend tothe front
    v.insert(v.begin(),0);
    //display num of elem
    cout << v.size() << endl;
    //traverse elements
    for (auto e : v) {
        cout << e << endl;
    }

    for (size_t i = 0; i <v.size(); i++){
        cout << i << ". " << v[i] << endl;
    }

    return 0;
}