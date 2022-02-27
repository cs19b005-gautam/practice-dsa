#include <bits/stdc++.h>
using namespace std;

bool checkCycle_DFS(int &node, vector<int> adj[], bool vis[], bool dfs_vis[]){
    vis[node] = true;
    dfs_vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(checkCycle_DFS(it, adj, vis, dfs_vis)){
                return true;
            }
        }
        else if(dfs_vis[it]){
            return true;
        }
    }
    dfs_vis[node] = false;
    return false;
}

bool isCycle_DFS(vector<int> adj[], int &V){
    bool vis[V+1];
    bool dfs_vis[V+1];
    memset(vis, false, sizeof vis);
    memset(dfs_vis, false, sizeof dfs_vis);
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            if(checkCycle_DFS(i, adj, vis, dfs_vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << (isCycle_DFS(adj, n)?"Cycle Presence Detected":"Cycle Presence Not Detected") << endl;

    return 0;
}