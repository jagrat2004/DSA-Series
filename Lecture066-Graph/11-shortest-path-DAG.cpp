#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <climits>

using namespace std;

/*
Time Complexity : O(V + E)
Space Complexity: O(V + E)

V = Number of Vertices
E = Number of Edges
*/

class Graph {

public:

    unordered_map<int, list<pair<int, int>>> adj;

    // Add directed weighted edge
    void addEdge(int u, int v, int weight) {

        adj[u].push_back({v, weight});
    }

    // Print adjacency list
    void printAdj() {

        for (auto i : adj) {

            cout << i.first << " -> ";

            for (auto j : i.second) {
                cout << "(" << j.first << "," << j.second << ") ";
            }

            cout << endl;
        }
    }

    // DFS for Topological Sort
    void dfs(int node,
             unordered_map<int, bool> &vis,
             stack<int> &topo) {

        vis[node] = true;

        for (auto neighbour : adj[node]) {

            if (!vis[neighbour.first]) {
                dfs(neighbour.first, vis, topo);
            }
        }

        topo.push(node);
    }

    // Shortest Path using Topological Order
    void getShortestPath(int src,
                         vector<int> &dist,
                         stack<int> &topo) {

        dist[src] = 0;

        while (!topo.empty()) {

            int top = topo.top();
            topo.pop();

            if (dist[top] != INT_MAX) {

                for (auto i : adj[top]) {

                    if (dist[top] + i.second < dist[i.first]) {

                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main() {

    Graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    cout << "Adjacency List:\n";
    g.printAdj();

    int vertices = 6;

    unordered_map<int, bool> vis;
    stack<int> topo;

    // Topological Sort
    for (int i = 0; i < vertices; i++) {
        if (!vis[i]) {
            g.dfs(i, vis, topo);
        }
    }

    vector<int> dist(vertices, INT_MAX);

    g.getShortestPath(1, dist, topo);

    cout << "\nShortest Distance from Source 1:\n";

    for (int i = 0; i < vertices; i++) {

        cout << "Vertex " << i << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}