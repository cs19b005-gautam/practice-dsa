#include <bits/stdc++.h>
using namespace std;

void TopoDFS(int &parent, vector<int> adj[], vector<bool> &vis, stack<int> &stk){
    vis[parent] = true;
    for(auto node : adj[parent]){
        if(!vis[node]){
            TopoDFS(node, adj, vis, stk);
        }
    }
    stk.push(parent);
}

void TopoSort(vector<int> adj[], int &V, vector<bool> &vis, stack<int> &stk){
    for(int i=1; i<=V; i++){
        if(!vis[i]){
            TopoDFS(i, adj, vis, stk);
        }
    }
}

void transpose(vector<int> adj[], vector<int> adjT[], int &V){
    for(int u=1; u<=V; u++){
        for(auto v : adj[u]){
            adjT[v].push_back(u);
        }
    }
}

void ReverseDFS(int &parent, vector<int> adjT[], int &V, vector<bool> &vis){
    vis[parent] = true;
    cout << parent << " ";
    for(auto node : adjT[parent]){
        if(!vis[node]){
            ReverseDFS(node, adjT, V, vis);
        }
    }
}

void KosarajuAlgorithm(vector<int> adj[], int &V){
    //Step1 : get the Topological Sorting of vertices or the stack used in it
    stack<int> stk;
    vector<bool> vis(V+1, false);
    TopoSort(adj, V, vis, stk);


                // stack<int> __new = stk;
                // cout << "Stack : " ;
                // while(!__new.empty()){
                //     cout << __new.top()-1 << " ";
                //     __new.pop();
                // }
                // cout << endl;

    //Step2 : Create a transpose of the given graph/Adjacency List
    vector<int> adjT[V+1];
    transpose(adj, adjT, V);

                    // for(int u=1; u<=V; u++){
                    //     cout << u-1 << " : ";
                    //     for(auto v : adjT[u]){
                    //         cout << v-1 <<", ";
                    //     }
                    //     cout << endl;
                    // }
                    // cout << endl << endl;

    fill(vis.begin(), vis.end(), false);


    //Step3 : Perform a Reverse-DFS on the vertices using TopoSorted stack and transpose adjacency list
    int cnt = 0;
    cout << "\nStrongly Connected Components of the Graphs are :" << endl;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        if(!vis[node]){
            cnt++;
            cout << "SCC" << cnt << " : ";
            ReverseDFS(node, adjT, V, vis);
            cout << endl;
        }
    }
    
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    KosarajuAlgorithm(adj, n);
    return 0;
}