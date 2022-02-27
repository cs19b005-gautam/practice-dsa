            /*  This algorithm is used to find shortest distance from src in Unweighted graph  */
#include <bits/stdc++.h>
using namespace std;

void shortestDistance(int &src, vector<pair<int, int>> adj[], int &V){
    vector<int> dist(V+1, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ; 
    //greater<> used for priority_queue being min heap, notation using = (dist, node)
    PQ.push({0, src});
    while(!PQ.empty()){
        int par_dist = PQ.top().first;
        int parent = PQ.top().second;
        PQ.pop();
        for(auto it : adj[parent]){
            int node = it.first;
            int weight = it.second;
            if(dist[node]>weight+par_dist){
                dist[node]=weight+par_dist;
                PQ.push({dist[node],node});
            }
        }
    }
    for(int i=1; i<=V; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src;
    cout << "src = ";
    cin >> src;
    shortestDistance(src, adj, n);
    return 0;
}