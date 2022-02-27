#include <bits/stdc++.h>
using namespace std;

bool bipartite_DFS(int &node, vector<int> adj[], int color[], int &V){
    if(color[node]==-1){
        color[node] = 1;
    }
    for(auto it : adj[node]){
        if(color[it]==-1){
            color[it] = 1-color[node];
            if(!bipartite_DFS(it, adj, color, V)){
                return false;
            }
        }
        else if(color[it]==color[node]){
            return false;
        }
    }
    return true;
}

bool checkBipartite_DFS(vector<int> adj[], int &V){
    int color[V+1];
    memset(color, -1, sizeof color);
    for(int i=1;i<=V;i++){
        if(color[i]==-1){
            if(!bipartite_DFS(i, adj, color, V)){
                return false;
            }
        }
    }
    return true;
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

    cout << (checkBipartite_DFS(adj, n)?"Bipartite Graph":"Not a Bipartite Graph") << endl;
    return 0;
}