#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

/*
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {

    // Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    // Find indegree of every node
    vector<int> indegree(n, 0);

    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Push all nodes having indegree = 0
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // BFS (Topological Sort)
    int cnt = 0;

    while (!q.empty()) {

        int front = q.front();
        q.pop();

        cnt++;

        // Update indegree of neighbours
        for (auto neighbour : adj[front]) {

            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    // If all nodes are processed, no cycle exists
    if (cnt == n)
        return false;
    else
        return true;
}

int main() {

    int n = 4;

    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2}      // Creates a cycle
    };

    if (detectCycleInDirectedGraph(n, edges))
        cout << "Cycle Present" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}

/*
Time Complexity: O(V + E)

Reason:
- Building adjacency list → O(E)
- Calculating indegree → O(E)
- BFS (each vertex and edge processed once) → O(V + E)

Overall: O(V + E)

Space Complexity: O(V + E)

Reason:
- Adjacency list → O(V + E)
- Indegree array → O(V)
- Queue → O(V)

Overall: O(V + E)
*/