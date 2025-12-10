bool isBipartite(int V, vector<vector<int>> &adj) {
    vector<int> color(V, -1);
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            color[i] = 0;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(auto &v : adj[u]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}