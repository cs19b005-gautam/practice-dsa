            /*  We are going to use topological sorting algorithm here  */

#include <bits/stdc++.h>
#define infinity INT_MAX
using namespace std;

void getStk(int &parent, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &stk){
    vis[parent] = true;
    for(auto node : adj[parent]){
        if(!vis[node.first]){
            getStk(node.first, adj, vis, stk);
        }
    }
    stk.push(parent);
}

void shortestDistance(int &src, vector<pair<int, int>> adj[], int &V){
    vector<bool> vis(V, false);
    stack<int> stk;
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i] = INT_MAX-10;
    }
    for(int i=0;i<V;i++){
        if(!vis[i]){
            getStk(i, adj, vis, stk);
        }
    }
    dist[src] = 0;
    while(!stk.empty()){
        int parent = stk.top();
        stk.pop();
        if(dist[parent]!=infinity){
            for(auto it : adj[parent]){
                int node = it.first;
                int weight = it.second;
                if(dist[node]>dist[parent]+weight){
                    dist[node]=dist[parent]+weight;
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    // return dist;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int src;
    cout << "src = " ;
    cin >> src;
    for(int i=0;i<n;i++){
        cout << i << " ";
    }
    cout << endl;
    shortestDistance(src, adj, n);
    // for(int i=0;i<n;i++){
    //     cout << dist[i] << " ";
    // }
    return 0;
}