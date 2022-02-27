#include <bits/stdc++.h>
using namespace std;
void dfs(int &node, int &parent, vector<int> adj[], int &V, vector<bool> &vis, vector<int> &tin, vector<int> &low, int &timer){
    vis[node] = true;
    int temp = timer++;
    low[node] = temp;
    tin[node] = temp;
    for(auto it : adj[node]){
        if(it==parent){
            continue;
        }
        else if(!vis[it]){
            dfs(it, node, adj, V, vis, tin, low, timer);
            low[node] = min(low[node], low[it]);
            if(low[it]>tin[node]){
                cout << "\t" << node << "->" << it << endl;
            }
        }
        else{
            low[node] = min(low[node], low[it]);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, false);
    vector<int> low(n, -1);
    vector<int> tin(n, -1);
    int p = -1;
    int timer = 0;
    cout << "Bridged Edges : " << endl;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, p, adj, n, vis, tin, low, timer);
        }
    }
    return 0;
}