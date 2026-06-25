#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e){
    //create adj list
    unordered_map<int,list<int>>adj;
    for(int i = 0; i <e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
        //find indegree
        vector<int> indegree(v);
        for(auto i : adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        }
        //0 indegree valo ko push krdo
        queue<int>q;
        for(int i =0; i<v; i++){
            if(indegree[i] == 0)
            q.push(i);
        }
        // do bfs
        vector<int>ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto neighbour : adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                q.push(neighbour);
            }
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

    vector<int> topoOrder = topologicalSort(edges, v, e);

    // Check for cycle
    if (topoOrder.size() != v) {
        cout << "Graph contains a cycle. Topological Sort not possible.\n";
    } else {
        cout << "Topological Order: ";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}