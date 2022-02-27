                    /*   Topological Sorting can only be done in Directed Acyclic Graphs   */

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSorting_BFS(vector<int> adj[], int &V){
    vector<int> indegree(V+1, 0);
    for(int i=1;i<=V;i++){
        for(auto node : adj[i]){
            indegree[node]++;
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
        topo.push_back(node);
        Q.pop();
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

    vector<int> topo = topologicalSorting_BFS(adj, n);

    for(auto e : topo){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}