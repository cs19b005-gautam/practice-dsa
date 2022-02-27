                            /*  PRIM'S Algorithm  */
#include <bits/stdc++.h>
using namespace std;

void BruteForce(vector<pair<int, int>> adj[], int &n){
    int key[n];
    bool MST[n];
    int parent[n];

    for(int i=0;i<n;i++){
        key[i] = INT_MAX;
        MST[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    for(int cnt = 0; cnt<n; cnt++){
        int node;
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            if(mini>key[i] && MST[i]==false){
                mini = key[i];
                node = i;
            }
        }
        MST[node] = true;
        for(auto it : adj[node]){
            int v = it.first;
            int w = it.second;
            if(MST[v]==false && key[v]>w){
                key[v] = w;
                parent[v] = node;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << parent[i] << " ";
    }
    cout << endl;
}

void Eff_Algo(vector<pair<int, int>> adj[], int &n){
    int key[n];
    bool MST[n];
    int par[n];

    for(int i=0; i<n; i++){
        key[i] = INT_MAX;
        MST[i] = false;
    }

    key[0] = 0;
    par[0] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({0, 0}); //(key[v], v)
    while(!PQ.empty()){
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
    for(int i=0; i<n;i++){
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
    bool select;
    cout << "Press and Enter: \n\t'0' for Brute Force \n\t'1' for efficient algorithm :\n\t\t ";
    cin >> select;
    if(!select)
        BruteForce(adj, n);
    else
        Eff_Algo(adj, n);
    return 0;
}