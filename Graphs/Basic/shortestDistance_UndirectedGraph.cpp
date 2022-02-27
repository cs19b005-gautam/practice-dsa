            /*   Shortest distance from the source can be found using BFS algorithm   */

#include <bits/stdc++.h>
using namespace std;

void shortestDistAllVertices(int &src, vector<int> adj[], int &V){
    vector<int> dist(V, INT_MAX-2);
    dist[src] = 0;
    queue<int> Q;
    Q.push(src);
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        for(auto it : adj[node]){
            if(dist[it]>1+dist[node]){
                dist[it] = dist[node] + 1;
                Q.push(it);
            }
        }
    }

    for(int i=0;i<V;i++){
        cout << "(" << i << "," << dist[i] << ") ";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];  // 0-based indexing for the vertices in the graph
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int src = 0;
    cout << "(v,dis[v]) => ";
    shortestDistAllVertices(src, adj, n);
    return 0;
}