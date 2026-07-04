#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

/*
Time Complexity : O(V + E)
Space Complexity: O(V + E)

V = Number of Vertices
E = Number of Edges
*/

void dfs(int node,
         int parent,
         int &timer,
         vector<int> &disc,
         vector<int> &low,
         vector<vector<int>> &result,
         unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis) {

    vis[node] = true;

    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {

        if (nbr == parent)
            continue;

        if (!vis[nbr]) {

            dfs(nbr, node, timer, disc, low, result, adj, vis);

            low[node] = min(low[node], low[nbr]);

            // Bridge Condition
            if (low[nbr] > disc[node]) {

                result.push_back({node, nbr});
            }
        }
        else {

            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges,
                                int v,
                                int e) {

    // Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++) {

        int u = edges[i][0];
        int w = edges[i][1];

        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    int timer = 0;

    vector<int> disc(v, -1);
    vector<int> low(v, -1);

    unordered_map<int, bool> vis;

    vector<vector<int>> result;

    // Handle disconnected graph
    for (int i = 0; i < v; i++) {

        if (!vis[i]) {

            dfs(i, -1, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}

int main() {

    int vertices = 5;
    int edgesCount = 5;

    vector<vector<int>> edges = {

        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}

    };

    vector<vector<int>> bridges =
        findBridges(edges, vertices, edgesCount);

    cout << "Bridges in Graph:\n";

    for (auto bridge : bridges) {

        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}