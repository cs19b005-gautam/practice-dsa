#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<int> adj[], int V){
    vector<bool> vis(V+1,0);
    vector<int> bfs;
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            vis[i] = true;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int parent = Q.front();
                Q.pop();
                bfs.push_back(parent);
                for(auto node : adj[parent]){
                    if(!vis[node]){
                        vis[node] = true;
                        Q.push(node);
                    }
                }
            }
            
        }
    }
    return bfs;
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

    vector<int> bfs = BFS(adj, n);
    
    for(auto e: bfs){
        cout << e << " ";
    }
    return 0;
}