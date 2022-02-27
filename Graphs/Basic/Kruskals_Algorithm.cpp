                                    /*  KRUSKAL'S ALGORITHM  */

#include <bits/stdc++.h>
using namespace std;

class edge{
public:
    int u, v, w;
    edge(int _u, int _v, int _w){
        u=_u; v=_v; w=_w;
    }
    int weight(){
        return w;
    }
};

bool comp(edge a, edge b){
    return a.weight() < b.weight();
}

int findParent(int u, vector<int> &parent){
    if(u==parent[u]) return u;
    else findParent(parent[u], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &Rank){
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(Rank[u] < Rank[v]){
        parent[u] = v;
    }
    else if(Rank[v] < Rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        Rank[u]++;
    }
}

int main(){
    int n, m;
    vector<edge> edges;
    int u, v, w;
    for(int i=0; i<n; i++){
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    vector<int> Rank(n, 0);

    int cost = 0;
    vector<pair<int, int>> MST;
    for(auto it : edges){
        if(findParent(it.u, parent)!=findParent(it.v, parent)){
            cost+=it.w;
            MST.push_back({it.u, it.v});
            Union(it.u, it.v, parent, Rank);
        }
    }
    cout << "cost = " << cost << endl;
    cout << "Tree :" << endl;
    for(auto it : MST){
        cout << it.first << " - " << it.second << endl;
    }
    return 0;
}