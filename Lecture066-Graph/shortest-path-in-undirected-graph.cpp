#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

vector<int> shortestpath (vector<pair<int,int>> edges, int n, int m, int s, int t){
    //create adjaceny list
    unordered_map<int,list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    // do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int>parent;
    queue<int>q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    //prepare shortest path
    vector<int>ans;
    int currentNode = t;
    ans.push_back(t);
    while(currentNode != s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;

}
int main() {
    int n, m;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> edges;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int s, t;
    cout << "Enter source and target: ";
    cin >> s >> t;

    vector<int> path = shortestpath(edges, n, m, s, t);

    if (path.empty()) {
        cout << "No path exists between " << s << " and " << t << endl;
    } else {
        cout << "Shortest Path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}