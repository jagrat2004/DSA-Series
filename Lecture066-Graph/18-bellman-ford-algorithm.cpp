#include <iostream>
#include <vector>
using namespace std;

int bellmanFord(int n, int m, int src, int dest,
                vector<vector<int>>& edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 &&
                dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 &&
            dist[u] + wt < dist[v]) {
            return -1; // Negative cycle exists
        }
    }

    return dist[dest];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int src, dest;
    cin >> src >> dest;

    int ans = bellmanFord(n, m, src, dest, edges);

    if (ans == -1)
        cout << "Negative Weight Cycle Exists\n";
    else if (ans == 1e9)
        cout << "No path exists\n";
    else
        cout << "Shortest Distance = " << ans << endl;

    return 0;
}

/*
Bellman-Ford Algorithm

Time Complexity:
1. Relaxing all edges (V-1 times):
   O((V-1) * E) ≈ O(V * E)

2. Checking for a negative weight cycle:
   O(E)

Overall Time Complexity:
   O(V * E)

Space Complexity:
1. Distance array:
   O(V)

2. No extra data structures are used apart from the distance array.

Overall Space Complexity:
   O(V)
*/