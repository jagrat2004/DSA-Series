#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

// DFS utility function
void topoSort(int node,
              vector<bool>& visited,
              stack<int>& s,
              unordered_map<int, list<int>>& adj) {

    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, s, adj);
        }
    }

    s.push(node);
}

// Topological Sort using DFS
vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {

    // Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int dest = edges[i][1];

        adj[u].push_back(dest);
    }

    // Visited array
    vector<bool> visited(v, false);

    stack<int> s;

    // DFS for all components
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }

    // Store answer
    vector<int> ans;

    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main() {

    int v, e;

    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological Order: ";

    for (int node : result) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}