#include <bits/stdc++.h>
using namespace std;

int Rank[10000];
int parent[10000];

void makeset(int n){
    for(int i=0; i<n; i++){
        Rank[i] = 0;
        parent[i] = i;
    }
}

int findPar(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findPar(node);
}

void Union(int u, int v){
    u = findPar(u);
    v = findPar(v);
    if(Rank[u]<Rank[v]){
        parent[u] = v;
    }
    else if(Rank[u]>Rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        Rank[u]++;
    }
}

int main(){
    int n;
    cin >> n;
    makeset(n);
    int m;
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        Union(u,v);
    }

    if(findPar(2)!=findPar(3)){
        cout << "Different components" << endl;
    }
    else{
        cout << "Same component" << endl;
    }
    return 0;
}