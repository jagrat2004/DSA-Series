#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool isCyclicDFS(int node,
                 int parent,
                 unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj) {

    visited[node] = true;

    for (auto neighbour : adj[node]) {

        if (!visited[neighbour]) {

            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);

            if (cycleDetected)
                return true;
        }
        else if (neighbour != parent) {
            return true;
        }
    }

    return false;
}

string CycleDetection(vector<vector<int>> &edges, int n, int m) {

    unordered_map<int, list<int>> adj;

    // Create adjacency list
    for (int i = 0; i < m; i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // Handle disconnected components
    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            bool ans = isCyclicDFS(i, -1, visited, adj);

            if (ans)
                return "Yes";
        }
    }

    return "No";
}

int main() {

    int n = 5;
    int m = 5;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1}      // Creates a cycle
    };

    cout << "Cycle Present: " << CycleDetection(edges, n, m) << endl;

    return 0;
}