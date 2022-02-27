#include <bits/stdc++.h>
using namespace std;

void DFS(int & parent, vector<int> adj[], vector<bool> &vis, vector<int> &dfs){
    vis[parent] = true;
    dfs.push_back(parent);
    for(auto node : adj[parent]){
        if(!vis[node]){
            DFS(node, adj, vis, dfs);
        }
    }
}

vector<int> DepthFirstSearch(vector<int> adj[], int & V){
    vector<bool> vis(V+1, false);
    vector<int> dfs;
    for(int i=1; i<=V; i++){
        if(!vis[i]){
            DFS(i, adj, vis, dfs);
        }
    }
    return dfs;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfs = DepthFirstSearch(adj, n);

    for(auto node : dfs){
        cout << node << " ";
    }
    return 0;
}