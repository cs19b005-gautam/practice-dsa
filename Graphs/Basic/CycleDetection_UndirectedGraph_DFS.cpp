#include <bits/stdc++.h>
using namespace std;

bool cycleDFS(int &node, int parent, int &V, vector<int> adj[], vector<bool> &vis){
    vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(cycleDFS(it, node, V, adj, vis)){
                return true;
            }
        }
        else if(it!= parent){
            return true;
        }
    }
    return false;
}

bool isCycle(vector<int> adj[], int &V){
    vector<bool> vis(V+1, 0);
    for(int i=1; i<=V; i++){
        if(!vis[i]){
            if(cycleDFS(i, -1, V, adj, vis)){
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
        adj[v].push_back(u);
    }

    cout << (isCycle(adj, n)?"Cycle presence detected":"Cycle presence not detected") << endl;

    return 0;
}