#include <bits/stdc++.h>
using namespace std;

bool isCycleBFS(int & start, vector<int> adj[], vector<bool> &vis, int & V){
    queue<pair<int, int>> Q;
    Q.push({start, -1});
    while(!Q.empty()){
        int node = Q.front().first;
        int parent = Q.front().second;
        Q.pop();
        for(auto it : adj[node]){
            if(!vis[node]){
                vis[node] = true;
                Q.push({it, node});
            }
            else if(parent != it){ 
                /* {node, parent} is the parent entry in the queue.
                    So the we always will be getting an parent node entry
                    which we will will always avoid using visited array
                    if parent==it => means we are getting back to the edge we came from
                    it that's not the case the node is reached from other route
                    If reached from other route this means that a cycle is present */
                cout << "2nd degree detection at " << it << " " << parent << endl;
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<int> adj[], int & V){
    vector<bool> vis(V+1, false);
    for(int i=1; i<=V;i++){
        if(!vis[i]){
            //checking if each component have any cyclic component
            if(isCycleBFS(i, adj, vis, V)){
                cout << "detection at vertex " << i << endl;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (isCycle(adj, n)?"Cycle presence detected":"Cycle presence not detected") << endl;

    return 0;
}