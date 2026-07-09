#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void dfs(int node,
         int parent,
         vector<int>& disc,
         vector<int>& low,
         unordered_map<int, bool>& vis,
         unordered_map<int, list<int>>& adj,
         vector<int>& ap,
         int& timer)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
            continue;

        if (!vis[nbr])
        {
            dfs(nbr, node, disc, low, vis, adj, ap, timer);

            low[node] = min(low[node], low[nbr]);

            // Articulation point condition
            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }

            child++;
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // Special case for root node
    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{
    int n = 5;

    vector<pair<int, int>> edges;

    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    // Adjacency List
    unordered_map<int, list<int>> adj;

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;

    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<int> ap(n, 0);

    unordered_map<int, bool> vis;

    // DFS for disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    cout << "Articulation points are:\n";

    for (int i = 0; i < n; i++)
    {
        if (ap[i])
        {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}