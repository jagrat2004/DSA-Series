#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <climits>

using namespace std;

/*
Time Complexity : O((V + E) log V)
Space Complexity: O(V + E)

V = Number of Vertices
E = Number of Edges
*/

vector<int> dijkstra(vector<vector<int>> &vec,
                     int vertices,
                     int edges,
                     int source) {

    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++) {

        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // Undirected Graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Distance array
    vector<int> dist(vertices, INT_MAX);

    // Set stores {distance, node}
    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty()) {

        // Node having minimum distance
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        // Traverse neighbours
        for (auto neighbour : adj[topNode]) {

            int neighbourNode = neighbour.first;
            int weight = neighbour.second;

            if (nodeDistance + weight < dist[neighbourNode]) {

                auto record = st.find({dist[neighbourNode], neighbourNode});

                // Remove old record if present
                if (record != st.end()) {
                    st.erase(record);
                }

                // Update distance
                dist[neighbourNode] = nodeDistance + weight;

                st.insert({dist[neighbourNode], neighbourNode});
            }
        }
    }

    return dist;
}

int main() {

    int vertices = 5;
    int edges = 6;
    int source = 0;

    vector<vector<int>> graph = {

        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}

    };

    vector<int> dist = dijkstra(graph, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";

    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << " : " << dist[i] << endl;
    }

    return 0;
}