            /* Kahn's Algorithm is the algorithm for topological sorting of DAG using BFS */

#include <bits/stdc++.h>
using namespace std;

vector<int> KahnsAlgo(vector<int> adj[], int &V){
    vector<int> indegree(V+1, 0);
    for(int i=1;i<=V;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> Q;
    for(int i=1;i<=V;i++){
        if(indegree[i]==0){
            Q.push(i);
        }
    }
    vector<int> topo;
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                Q.push(it);
            }
        }
    }
    return topo;
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
    vector<int> topo = KahnsAlgo(adj, n);
    return 0;
}