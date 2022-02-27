                    /* same of the Kahn's Algorithm is used here */

#include <bits/stdc++.h>
using namespace std;

bool checkCycle(vector<int> adj[], int &V){
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

    int cnt = 0;
    while(!Q.empty()){
        int parent = Q.front();
        Q.pop();
        cnt++;
        for(auto node : adj[parent]){
            indegree[node]--;
            if(indegree[node]==0){
                Q.push(node);
            }
        }
    }
    if(cnt==V) return false;
    return true;
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

    cout << (checkCycle(adj, n)?"Cycle Presence Detected":"Cycle Presence Not Detected") << endl;
    return 0;
}