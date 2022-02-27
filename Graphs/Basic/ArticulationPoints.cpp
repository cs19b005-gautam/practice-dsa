#include <bits/stdc++.h>
using namespace std;

void dfs(int &node, int &parent, vector<int> adj[], int &V, vector<bool> &vis, vector<int> &tin, vector<int> &low, vector<bool> &isAP, int &timer){
    vis[node] = true;
    int temp = timer++;
    low[node] = temp;
    tin[node] = temp;
    int child = 0;
    for(auto it : adj[node]){
        if(it==parent){
            continue;
        }
        else if(!vis[it]){
            dfs(it, node, adj, V, vis, tin, low, isAP, timer);
            low[node] = min(low[node], low[it]);
            child++;
            if(low[it]>=tin[node] && parent!=-1){
                isAP[node] = true;
            }
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
    if(parent==-1 && child>1){
        isAP[node] = true;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0; i<n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<bool> isAP(n, false);
    int p = -1;
    int timer = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, p, adj, n, vis, tin, low, isAP, timer);
        }
    }
    cout << "Articulation Points : ";
    for(int i=0; i<n; i++){
        if(isAP[i]) cout << i << " " ;
    }
    cout << endl;
    return 0;
}