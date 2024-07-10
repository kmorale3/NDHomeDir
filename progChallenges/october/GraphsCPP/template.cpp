// Exercise 18-A: Graph Traversals

#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// WalkType Constants

typedef enum {
    DFS_REC,
    DFS_ITER,
    BFS_ITER,
} WalkType;

// Graph structure

typedef unordered_map<int, set<int>> Graph;

// Load graph from standard input

void load_graph(Graph &g) {
    // Read edges
    int source, target;
    while (cin >> source >> target) {
        g[source].insert(target);
        // for an undirected graph 
        // g[target].insert(source); 
    }
}

// Depth-First-Search (recursive)

void walk_graph_dfs_rec(Graph &g, int v, set<int> &visited) {
    // base case: already visited node
    if (visited.count(v)) {
        return;
    }

    visited.insert(v); // mark vertex as visited 
    cout << v << endl; // process the vertex 

    // recursive: visit the neighbors
    for (auto &u : g[v]) {
        walk_graph_dfs_rec(g, u, visited);
    }
}

// Depth-First-Search (iterative)

void walk_graph_dfs_iter(Graph &g, int v) {
    // use a stack
    stack<int> frontier; // nodes we can see/visit, but haven't yet
    set<int>   visited;  // nodes already visited
    
    frontier.push(v);    // add first node to frontier

    while(!frontier.empty()) {
        // get next node to visit
        auto n = frontier.top(); frontier.pop();

        // check if visited before
        if (visited.count(n)) {
            continue;
        }

        // mark as visited and process node
        visited.insert(n);
        cout << n << endl;

        // add the neighbors to frontier
        for (auto &u : g[n]) {
            frontier.push(u);
        }
    }
}

// Breadth-First-Search (iterative)

void walk_graph_bfs_iter(Graph &g, int v) {
    // use a stack
    queue<int> frontier; // nodes we can see/visit, but haven't yet
    set<int>   visited;  // nodes already visited
    
    frontier.push(v);    // add first node to frontier

    while(!frontier.empty()) {
        // get next node to visit
        auto n = frontier.front(); frontier.pop();

        // check if visited before
        if (visited.count(n)) {
            continue;
        }

        // mark as visited and process node
        visited.insert(n);
        cout << n << endl;

        // add the neighbors to frontier
        for (auto &u : g[n]) {
            frontier.push(u);
        }
    }
}

// Walk graph dispatch function

void walk_graph(Graph &g, int root, WalkType w) {
    set<int> visited;

    switch (w) {
        case DFS_REC:
            walk_graph_dfs_rec(g, root, visited);
            break;
        case DFS_ITER:
            walk_graph_dfs_iter(g, root);
            break;
        case BFS_ITER:
            walk_graph_bfs_iter(g, root);
            break;
        default:
            cerr << "Unknown WalkType: " << w << endl;
            break;
    }
}

// Main execution

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " root [0 = DFS_REC | 1 = DFS_ITER | 2 = BFS_ITER]" << endl;
        return EXIT_FAILURE;
    }

    int root = atoi(argv[1]);
    int walk = atoi(argv[2]);
    
    Graph g;

    load_graph(g);
    walk_graph(g, root, static_cast<WalkType>(walk));

    return EXIT_SUCCESS;
}
