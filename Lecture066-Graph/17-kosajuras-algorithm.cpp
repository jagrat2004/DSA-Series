#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

// First DFS for Topological Ordering
void dfs(int node,
         unordered_map<int, bool>& vis,
         stack<int>& st,
         unordered_map<int, list<int>>& adj)
{
    vis[node] = true;

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, vis, st, adj);
        }
    }

    st.push(node);
}

// DFS on Transpose Graph
void revDfs(int node,
            unordered_map<int, bool>& vis,
            unordered_map<int, list<int>>& adj)
{
    vis[node] = true;

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            revDfs(nbr, vis, adj);
        }
    }
}

// Function to find SCC count
int stronglyConnectedComponents(int V, vector<vector<int>>& edges)
{
    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Step 2: Topological Sort using DFS
    stack<int> st;
    unordered_map<int, bool> vis;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    // Step 3: Create Transpose Graph
    unordered_map<int, list<int>> transpose;

    for (int i = 0; i < V; i++) {
        vis[i] = false;

        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // Step 4: DFS according to stack order
    int count = 0;

    while (!st.empty()) {
        int top = st.top();
        st.pop();

        if (!vis[top]) {
            count++;
            revDfs(top, vis, transpose);
        }
    }

    return count;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter directed edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int ans = stronglyConnectedComponents(V, edges);

    cout << "Number of Strongly Connected Components = "
         << ans << endl;

    return 0;
}