#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void dfs(int node, unordered_map<int,bool> & visited, unordered_map<int,list<int>>&adj, vector<int>& component){
    component.push_back(node);
    visited[node]=true;
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i, visited, adj, component);
        }
    }
}
vector<vector<int>>depthFirstSearch(int v, int e, vector<vector<int>>& edges ){
    unordered_map<int,list<int>>adj;
    for(int i = 0; i <edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>ans;
    unordered_map<int,bool>visited;

    for( int i = 0; i < v; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main() {

    int v = 5;
    int e = 4;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4}
    };

    vector<vector<int>> result = depthFirstSearch(v, e, edges);

    cout << "Connected Components:\n";

    for (auto component : result) {
        for (auto node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}