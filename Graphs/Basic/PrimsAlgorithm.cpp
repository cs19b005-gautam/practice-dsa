                /*  This algorithm is used to find Minimum Spanning Tree  */
#include <bits/stdc++.h>
using namespace std;

void Prims_Eff_algo(vector<pair<int, int>> adj[], int &V){
    int par[V];
    bool MST[V];
    int key[V];

    for(int i=0; i<V; i++){
        MST[i] = false;
        key[i] = INT_MAX;
    }

    par[0] = -1;
    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({0, 0});
    while (!PQ.empty()){
        int u = PQ.top().second;
        PQ.pop();
        MST[u] = true;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(MST[v]==false && key[v]>w){
                key[v] = w;
                par[v] = u;
                PQ.push({key[v], v});
            }
        }
    }
    for(int i=0; i<V;i++){
        cout << par[i] << " ";
    }
    cout << endl;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Prims_Eff_algo(adj, n);
    return 0;
}