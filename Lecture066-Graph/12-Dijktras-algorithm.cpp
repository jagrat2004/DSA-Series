vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source){
    // create adj list
    unordered_map<int,list<pair<int,int>>adj;
    for(int i = 0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[u].push_back(make_pair(u,w));

        //create of distance array with infinite value initially
        vector<int> dist(vertices);
        
    }
}