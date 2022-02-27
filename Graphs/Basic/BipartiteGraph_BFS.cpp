#include <bits/stdc++.h>
using namespace std;

bool bipartite_BFS(int &src, vector<int> adj[], int color[]){
    color[src] = 0;
    queue<int> Q;
    Q.push(src);
    while(!Q.empty()){
        int parent = Q.front();
        Q.pop();
        for(auto node : adj[parent]){
            if(color[node]==-1){
                color[node] = 1-color[parent];
                Q.push(node);
            }
            else if(color[node]==color[parent]){
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite_BFS(vector<int> adj[], int &V){
    int color[V+1];
    memset(color, -1, sizeof color);
    for(int i=1;i<=V;i++){
        if(color[i]==-1){
            if(!bipartite_BFS(i, adj, color)){
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

    cout << (checkBipartite_BFS(adj, n)?"Bipartite Graph":"Not a Bipartite Graph") << endl;
    return 0;
}