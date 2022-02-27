                    /*   Topological Sorting can only be done in Directed Acyclic Graphs   */

#include <bits/stdc++.h>
using namespace std;

void topoSort_DFS(int &parent, vector<int> adj[], vector<bool> &vis, stack<int> &stk, vector<int> &topoSort){
    vis[parent] = true;
    for(auto node : adj[parent]){
        if(!vis[node]){
            topoSort_DFS(node, adj, vis, stk, topoSort);
        }
    }
    stk.push(parent);
}

vector<int> topologicalSorting_DFS(vector<int> adj[], int& V){
    vector<bool> vis(V+1, false);
    stack<int> stk;
    vector<int> topoSort;
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            topoSort_DFS(i, adj, vis, stk, topoSort);
        }
    }
    while(!stk.empty()){
        topoSort.push_back(stk.top());
        stk.pop();
    }
    return topoSort;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> topoSort = topologicalSorting_DFS(adj, n);
    for(auto e : topoSort){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}