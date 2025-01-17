// Exercise 14-B: Max Min

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Functions

bool read_numbers(int &n, int &k, vector<int> &v) {
    int t;

    if (!(cin >> n >> k)) {
    	return false;
    }

    v.clear();
    for (int i = 0; i < n; i++) {
    	cin >> t;
    	v.push_back(t);
    }

    return true;
}

int compute_unfairness(int n, int k, vector<int> &v) {
    // TODO: Compute minimum unfairness
    int u, d;       // u = minimum, unfairness, d= difference
    sort(v.begin(), v.end());
    u = v[n - 1] - v[0];
    for (int i = 0; i <=(n - k); i++){
        d = v[i + k - 1] - v[i];
        u = min(d, u);
    }
    return u;
}

// Main execution

int main(int argc, char *argv[]) {
    int n, k;
    vector<int> v;

    while (read_numbers(n, k, v)) {
	cout << compute_unfairness(n, k, v) << endl;
    }

    return 0;
}