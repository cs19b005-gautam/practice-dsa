#include <bits/stdc++.h>
using namespace std;

class UndirectedGraph{
private:
    int V;
    vector<int> *adj;
    int * dist;
public:
    UndirectedGraph(vector<int> *_adj, int _V){
        adj = _adj;
        V = _V;
    }

    vector<int> BFS(){
        vector<bool> vis(V+1, false);
        vector<int> bfs;
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                vis[i] = true;
                queue<int> Q;
                Q.push(i);
                while(!Q.empty()){
                    int parent = Q.front();
                    Q.pop();
                    bfs.push_back(parent);
                    for(auto node : adj[parent]){
                        if(!vis[node]){
                            vis[node] = true;
                            Q.push(node);
                        }
                    }
                }
                
            }
        }
        return bfs;
    }

    void dfs_of_node(int parent, vector<bool> &vis, vector<int> &dfs){
        vis[parent] = true;
        dfs.push_back(parent);
        for(auto node : adj[parent]){
            if(!vis[node]){
                vis[node] = true;
                dfs_of_node(node, vis, dfs);
            }
        }
    }
    vector<int> DFS(){
        vector<bool> vis(V+1, false);
        vector<int> dfs;
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                dfs_of_node(i, vis, dfs);
            }
        }
    }

    bool foundCycle_BFS(int &start, vector<bool> &vis){
        vis[start] = true;
        queue<pair<int, int>> Q;
        Q.push({start, -1});
        while(!Q.empty()){
            int parent = Q.front().first;
            int node = Q.front().second;
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    Q.push({it, node});
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
        return false; 
    }
    bool isCycle_BFS(){
        vector<bool> vis(V+1, false);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                if(foundCycle_BFS(i, vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool foundCycle_DFS(int &node, int &parent, vector<bool> &vis){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(foundCycle_DFS(it, node, vis)){
                    return true;
                }
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle_DFS(){
        vector<bool> vis(V+1, false);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                int p = -1;
                if(foundCycle_DFS(i, p, vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool bipartite_BFS(int &src, int color[]){
        color[src] = 0;
        queue<int> Q;
        Q.push(src);
        while(!Q.empty()){
            int parent = Q.front();
            Q.pop();
            for(auto node : adj[parent]){
                if(color[node]==-1){
                    color[node] = 1-color[parent];
                    Q.push(node);
                }
                else if(color[node]==color[parent]){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBipartite_BFS(){
        int color[V+1];
        memset(color, -1, sizeof color);
        for(int i=1;i<=V;i++){
            if(color[i]==-1){
                if(!bipartite_BFS(i, color)){
                    return false;
                }
            }
        }
        return true;
    }

    

};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    
    /*scanning all the graph*/
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    UndirectedGraph g(adj, n);
    return 0;
}