#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool CheckCycleDFS(int node,unordered_map<int, bool> &visited,unordered_map<int, bool> &dfsvisited,unordered_map<int, list<int>> &adj) {

    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : adj[node]) {

        if (!visited[neighbour]) {

            bool cycleDetected = CheckCycleDFS(neighbour, visited, dfsvisited, adj);

            if (cycleDetected)
                return true;
        }
        else if (dfsvisited[neighbour]) {
            return true;
        }
    }

    dfsvisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {

    unordered_map<int, list<int>> adj;

    // Create adjacency list
    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    // Check every component
    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            bool cycleFound = CheckCycleDFS(i, visited, dfsvisited, adj);

            if (cycleFound)
                return true;
        }
    }

    return false;
}

int main() {

    int n = 4;

    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}     // Creates a cycle
    };

    if (detectCycleInDirectedGraph(n, edges))
        cout << "Cycle Present" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}