#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>

using namespace std;

/*
Time Complexity : O(N^2 + E)
Space Complexity: O(N + E)

N = Number of Vertices
E = Number of Edges
*/

vector<pair<pair<int, int>, int>> calculatePrimsMst(
    int n,
    int m,
    vector<pair<pair<int, int>, int>> &g) {

    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) {

        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Start from node 1
    key[1] = 0;

    // Prim's Algorithm
    for (int i = 1; i < n; i++) {

        int mini = INT_MAX;
        int u = -1;

        // Find minimum key vertex
        for (int v = 1; v <= n; v++) {

            if (!mst[v] && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        mst[u] = true;

        // Update adjacent vertices
        for (auto it : adj[u]) {

            int v = it.first;
            int w = it.second;

            if (!mst[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main() {

    int n = 5;
    int m = 6;

    vector<pair<pair<int, int>, int>> graph = {

        {{1, 2}, 2},
        {{1, 4}, 6},
        {{2, 3}, 3},
        {{2, 4}, 8},
        {{2, 5}, 5},
        {{3, 5}, 7}

    };

    vector<pair<pair<int, int>, int>> mst =
        calculatePrimsMst(n, m, graph);

    cout << "Edges in MST:\n";

    for (auto edge : mst) {

        cout << edge.first.first << " - "
             << edge.first.second
             << " : Weight = "
             << edge.second << endl;
    }

    return 0;
}