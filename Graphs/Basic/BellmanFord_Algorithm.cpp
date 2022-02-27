#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, wt;
    edge(int _u, int _v, int _wt){
        u = _u;
        v = _v;
        wt = _wt;
    }
};

void BellmanFord_Algorithm(int &src, vector<edge> edges, int &V){
    int inf = 1e7;
    vector<int> dist(V, inf);
    dist[src] = 0;

    for(int i=0; i<V-1; i++){
        for(auto it : edges){
            if(dist[it.v] > dist[it.u]+it.wt){
                dist[it.v] = dist[it.u]+it.wt;
            }
        }
    }

    bool Neg_cycle = false;
    for(auto it : edges){
        if(dist[it.v] > dist[it.u]+it.wt){
            Neg_cycle = true;
            cout << "Negative Cycle Detected" << endl;
        }
    }

    if(!Neg_cycle){
        cout << "Shortest distances (src = " << src << ") : ";
        for(int i=0; i<V; i++){
            cout << "(" << i << "->" << dist[i] << ") ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(edge(u, v, wt));
    }
    int src;
    cout << "src = ";
    cin >> src;
    BellmanFord_Algorithm(src, edges, n);
    return 0;
}